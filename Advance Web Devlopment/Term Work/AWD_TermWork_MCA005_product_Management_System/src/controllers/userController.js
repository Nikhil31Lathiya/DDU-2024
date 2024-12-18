const puppeteer = require("puppeteer");
const fs = require("fs");
const path = require("path");
const ProductModel = require("../models/productModel");

exports.getShop = async (req, res) => {
  const products = await ProductModel.getAllProducts();
  res.render("user/shop", { products });
};

exports.getProductDetails = async (req, res) => {
  const productId = req.params.id;

  try {
    const product = await ProductModel.getParticularProduct(productId);

    if (!product) {
      return res.status(404).send("Product not found");
    }

    res.render("user/productDetails", { product });
  } catch (error) {
    console.error("Error fetching product details:", error);
    res.status(500).send("Internal Server Error");
  }
};

// Add product to cart
exports.addToCart = async (req, res) => {
  const productId = req.body.productId;

  try {
    const product = await ProductModel.getParticularProduct(productId);

    if (!product) {
      return res.status(404).send("Product not found");
    }

    if (!req.session.cart) {
      req.session.cart = [];
    }

    // Check if product already exists in the cart
    const existingProductIndex = req.session.cart.findIndex(
      (item) => item.product.id === product.id
    );

    if (existingProductIndex > -1) {
      // Increase the quantity if the product already exists in the cart
      req.session.cart[existingProductIndex].quantity += 1;
    } else {
      // Add the product to the cart
      req.session.cart.push({
        product: product,
        quantity: 1,
      });
    }

    req.session.save(() => {
      res.redirect("/cart"); // Redirect to cart page
    });
  } catch (error) {
    console.error("Error adding to cart:", error);
    res.status(500).send("Internal Server Error");
  }
};

// View the cart
exports.viewCart = (req, res) => {
  const cart = req.session.cart || [];

  const totalPrice = cart.reduce((total, item) => {
    return total + item.product.price * item.quantity;
  }, 0);

  res.render("user/cart", { cart, totalPrice });
};

exports.decreaseQuantity = (req, res) => {
  const productId = parseInt(req.body.productId);

  if (!req.session.cart) {
    return res.redirect("/cart");
  }

  const productIndex = req.session.cart.findIndex(
    (item) => item.product.id === productId
  );

  if (productIndex > -1) {
    if (req.session.cart[productIndex].quantity > 1) {
      req.session.cart[productIndex].quantity -= 1;
    } else {
      req.session.cart.splice(productIndex, 1); // Remove item from cart if quantity reaches 0
    }
  }

  req.session.save(() => {
    res.redirect("/cart");
  });
};

// Increase quantity of product in cart
exports.increaseQuantity = (req, res) => {
  const productId = parseInt(req.body.productId);

  if (!req.session.cart) {
    return res.redirect("/cart");
  }

  const productIndex = req.session.cart.findIndex(
    (item) => item.product.id === productId
  );

  if (productIndex > -1) {
    req.session.cart[productIndex].quantity += 1; // Increase quantity
  }

  req.session.save(() => {
    res.redirect("/cart");
  });
};

exports.viewOrder = (req, res) => {
  const cart = req.session.cart || [];
  const totalPrice = cart.reduce((total, item) => {
    return total + item.product.price * item.quantity;
  }, 0);

  res.render("user/order", { cart, totalPrice });
};

exports.confirmOrder = async (req, res) => {
  const cart = req.session.cart || [];

  if (cart.length === 0) {
    return res.redirect("/cart");
  }

  // Decrease product quantities
  for (let item of cart) {
    const product = await ProductModel.getParticularProduct(item.product.id);
    if (product.quantity >= item.quantity) {
      await ProductModel.updateProductQuantity(
        product.id,
        product.quantity - item.quantity
      );
    } else {
      return res
        .status(400)
        .send("Not enough quantity in stock for " + product.name);
    }
  }

  const billsDir = path.resolve(__dirname, "../public/bills");
  if (!fs.existsSync(billsDir)) {
    fs.mkdirSync(billsDir, { recursive: true });
  }
  const totalPrice = cart.reduce(
    (total, item) => total + item.product.price * item.quantity,
    0
  );
  const orderDate = new Date().toLocaleDateString();

  res.render(
    "user/invoice",
    { cart, totalPrice, orderDate },
    async (err, html) => {
      if (err) {
        console.error("Error rendering EJS:", err);
        return res.status(500).send("Error generating invoice");
      }

      try {
        // Launch Puppeteer to convert HTML to PDF
        const browser = await puppeteer.launch();
        const page = await browser.newPage();
        await page.setContent(html);
        const pdfPath = path.join(billsDir, `bill_${Date.now()}.pdf`);

        await page.pdf({ path: pdfPath, format: "A4" });

        await browser.close();

        // Clear the cart
        req.session.cart = [];

        // Redirect to download the generated PDF
        res.redirect(`/order/download?file=${pdfPath}`);
      } catch (error) {
        console.error("Error generating PDF:", error);
        res.status(500).send("Error generating PDF");
      }
    }
  );
};

// Route to download the generated PDF
exports.downloadBill = (req, res) => {
  const filePath = req.query.file;
  res.download(filePath, "invoice.pdf", (err) => {
    if (err) {
      res.status(500).send("Error downloading file.");
    }
  });
};
