const express = require("express");
const router = express.Router();
const userController = require("../controllers/userController");

router.get("/", userController.getShop);
router.get("/shop", userController.getShop);
router.get("/product/:id", userController.getProductDetails);
router.post("/cart", userController.addToCart);
router.get("/cart", userController.viewCart);
router.post("/cart/increase", userController.increaseQuantity);
router.post("/cart/decrease", userController.decreaseQuantity);

// Routes for order confirmation and downloading the bill
router.get("/order", userController.viewOrder);
router.post("/order/confirm", userController.confirmOrder);
router.get("/order/download", userController.downloadBill);

module.exports = router;
