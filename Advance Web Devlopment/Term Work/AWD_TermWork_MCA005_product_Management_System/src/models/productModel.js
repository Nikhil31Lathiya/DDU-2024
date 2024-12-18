const prisma = require("./prisma");

exports.getAllProducts = async () => {
  try {
    return await prisma.product.findMany();
  } catch (error) {
    console.error("Error fetching products:", error);
    throw new Error("Failed to fetch products");
  }
};

exports.getParticularProduct = async (id) => {
  try {
    return await prisma.product.findUnique({
      where: { id: Number(id) },
    });
  } catch (error) {
    console.error(`Error fetching product with ID ${id}:`, error);
    throw new Error("Failed to fetch product");
  }
};

exports.addProduct = async (productData) => {
  try {
    return await prisma.product.create({
      data: productData,
    });
  } catch (error) {
    console.error("Error adding product:", error);
    throw new Error("Failed to add product");
  }
};

exports.editProduct = async (id, updatedData) => {
  try {
    return await prisma.product.update({
      where: { id: Number(id) },
      data: updatedData,
    });
  } catch (error) {
    console.error(`Error updating product with ID ${id}:`, error);
    throw new Error("Failed to update product");
  }
};

exports.deleteProduct = async (id) => {
  try {
    return await prisma.product.delete({
      where: { id: Number(id) },
    });
  } catch (error) {
    console.error(`Error deleting product with ID ${id}:`, error);
    throw new Error("Failed to delete product");
  }
};

exports.updateProductQuantity = async (id, quantity) => {
  try {
    return await prisma.product.update({
      where: { id: Number(id) },
      data: { quantity: quantity },
    });
  } catch (error) {
    console.error(`Error updating product quantity:`, error);
    throw new Error("Failed to update product quantity");
  }
};
