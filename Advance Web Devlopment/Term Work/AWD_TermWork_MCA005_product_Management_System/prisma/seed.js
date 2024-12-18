// import { PrismaClient } from "@prisma/client";
const { PrismaClient } = require("@prisma/client");

const prisma = new PrismaClient();

async function main() {
  // Inserting initial product data
  await prisma.product.createMany({
    data: [
      {
        name: "Wireless Headphones",
        price: 99.99,
        quantity: 150,
        description:
          "High-quality wireless headphones with noise cancellation.",
        imageUrl:
          "https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcQYgMEjpvHkOchM16UZBjU1S5uLtxBdMEojwA&s",
      },
      {
        name: "Gaming Mouse",
        price: 49.99,
        quantity: 300,
        description: "Ergonomic gaming mouse with customizable buttons.",
        imageUrl:
          "https://assetsio.gnwcdn.com/g502x_f9QuuM8.jpeg?width=1200&height=1200&fit=bounds&quality=70&format=jpg&auto=webp",
      },
      {
        name: "Smart Watch",
        price: 199.99,
        quantity: 120,
        description:
          "Feature-rich smartwatch with health tracking and notifications.",
        imageUrl:
          "https://www.corseca.in/cdn/shop/files/2_6b32baf1-0bdf-4e4e-8fde-d4946d1e94fd.jpg?v=1700823367",
      },
      {
        name: "Bluetooth Speaker",
        price: 79.99,
        quantity: 200,
        description:
          "Portable Bluetooth speaker with deep bass and long battery life.",
        imageUrl:
          "https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcTbppGSX3HdN4bXy-NFVMfATbcQQg3Yg7bbHQ&s",
      },
      {
        name: "Laptop Stand",
        price: 29.99,
        quantity: 500,
        description:
          "Adjustable laptop stand for better ergonomics and cooling.",
        imageUrl:
          "https://symplify.in/cdn/shop/products/Wooden-Laptop-Stand-Opt3-3_1024x1024.jpg?v=1658253933",
      },
      {
        name: "Wireless Charger",
        price: 39.99,
        quantity: 250,
        description: "Fast wireless charger for smartphones and other devices.",
        imageUrl:
          "https://www.brookstone.com/cdn/shop/files/BK15-4QL1F-WT_White_2_750x.jpg?v=1708116047",
      },
      {
        name: "Action Camera",
        price: 149.99,
        quantity: 100,
        description:
          "Compact action camera with 4K recording and waterproof design.",
        imageUrl:
          "https://eavf3cou74b.exactdn.com/wp-content/uploads/2023/08/28104711/Action-Camera-4.jpg",
      },
    ],
  });

  console.log("Seed data for products created successfully.");
}

main()
  .catch((e) => {
    console.error("Error during seed: ", e);
    process.exit(1);
  })
  .finally(async () => {
    await prisma.$disconnect();
  });
