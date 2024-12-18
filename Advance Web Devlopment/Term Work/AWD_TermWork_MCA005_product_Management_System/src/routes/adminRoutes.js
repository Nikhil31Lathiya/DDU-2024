const express = require("express");
const router = express.Router();
const adminController = require("../controllers/adminController");

router.get("/", (req, res) => {
  res.redirect("/admin/login"); 
});
// Display the login page when /admin is accessed
router.get("/login", adminController.getLoginPage);

// Handle admin login logic
router.post("/login", adminController.handleLogin);
router.get("/dashboard", adminController.getDashboard);
router.get("/add-product", adminController.getAddProductPage);
router.post("/products/add", adminController.addProduct);

// Route to show the Edit Product form
router.get("/products/edit/:id", adminController.getEditProductPage);

// Route to handle Edit Product form submission
router.post("/products/edit/:id", adminController.editProduct);

router.post("/products/delete/:id", adminController.deleteProduct);

router.get("/logout", adminController.logout); 

module.exports = router;
