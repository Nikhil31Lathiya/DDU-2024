const { PrismaClient } = require('@prisma/client');

// Create and export the Prisma client instance
const prisma = new PrismaClient();

module.exports = prisma;
