const { PrismaClient } = require("@prisma/client");
const prisma = new PrismaClient();

// Display the login page
exports.getLoginPage = (req, res) => {
  res.render("admin/adminLogin", { errorMessage: null });
};

// Handle login attempt
exports.handleLogin = async (req, res) => {
  const { username, password } = req.body;

  try {
    const hardcodedUsername = "admin";
    const hardcodedPassword = "admin";

   
    if (username !== hardcodedUsername || password !== hardcodedPassword) {
      return res.render("admin/adminLogin", {
        errorMessage: "Invalid username or password",
      });
    }

    // Redirect to the admin dashboard upon successful login
    res.redirect("/admin/dashboard");
  } catch (error) {
    console.error("Login error:", error);
    res.render("admin/adminLogin", {
      errorMessage: "An error occurred, please try again.",
    });
  }
};

exports.getDashboard = async (req, res) => {
  try {
    // Fetch all products from the database
    const products = await prisma.product.findMany();

    // Render the admin dashboard and pass the products
    res.render("admin/adminDashboard", { products });
  } catch (error) {
    console.error("Error fetching products:", error);
    res.status(500).send("Internal Server Error");
  }
};

exports.logout = (req, res) => {
  // Redirect back to the login page
  res.redirect("/shop");
};

exports.getAddProductPage = (req, res) => {
  res.render("admin/addProduct");
};

exports.addProduct = async (req, res) => {
  const { name, price, quantity, imageUrl, description } = req.body;

  try {
    // Save the new product to the database
    await prisma.product.create({
      data: {
        name,
        price: parseFloat(price),
        quantity: parseInt(quantity),
        imageUrl,
        description,
      },
    });

    // Redirect back to admin dashboard to show the new product
    res.redirect("/admin/dashboard");
  } catch (error) {
    console.error("Error adding product:", error);
    res.status(500).send("Error adding product.");
  }
};

exports.getEditProductPage = async (req, res) => {
  const productId = req.params.id;
  try {
    // Fetch the product by ID
    const product = await prisma.product.findUnique({
      where: { id: Number(productId) },
    });

    //  product doesn't exist then return 404
    if (!product) {
      return res.status(404).send("Product not found");
    }

    res.render("admin/editProduct", { product });
  } catch (error) {
    console.error("Error fetching product:", error);
    res.status(500).send("Error fetching product.");
  }
};

// Handle Edit Product form submission
exports.editProduct = async (req, res) => {
  const productId = req.params.id;
  const { name, price, quantity, imageUrl, description } = req.body;

  try {
    // Update the product in the database
    await prisma.product.update({
      where: { id: Number(productId) },
      data: {
        name,
        price: parseFloat(price),
        quantity: parseInt(quantity),
        imageUrl,
        description,
      },
    });

    // Redirect back to the admin dashboard
    res.redirect("/admin/dashboard");
  } catch (error) {
    console.error("Error updating product:", error);
    res.status(500).send("Error updating product.");
  }
};

exports.deleteProduct = async (req, res) => {
  const productId = req.params.id;

  try {
    // Delete the product from the database
    await prisma.product.delete({
      where: { id: Number(productId) },
    });

    res.redirect("/admin/dashboard");
  } catch (error) {
    console.error("Error deleting product:", error);
    res.status(500).send("Error deleting product.");
  }
};
