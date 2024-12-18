const express = require("express");
const app = express();
const bodyParser = require("body-parser");
const adminRoutes = require("./src/routes/adminRoutes");
const userRoutes = require("./src/routes/userRoutes");
const session = require("express-session"); 


app.use(bodyParser.urlencoded({ extended: true }));
app.use(bodyParser.json());
app.use(express.static(__dirname + "/public"));


app.use(
  session({
    secret: "mySecretKey", 
    resave: false,
    saveUninitialized: true,
    cookie: { secure: false } 
  })
);
app.set("view engine", "ejs");
app.set("views", "views");

app.use("/admin", adminRoutes);
app.use("/", userRoutes);

const PORT = process.env.PORT || 3000;
app.listen(PORT, () => {
  console.log(`Server running on port ${PORT}`);
});
