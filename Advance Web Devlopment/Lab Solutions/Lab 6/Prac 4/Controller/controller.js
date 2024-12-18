var express = require("express");
var app = express();
var bp = require("body-parser");

app.set('view engine', 'pug');
app.set('views','../Views');

app.use(bp.urlencoded({ extended: true }));

app.get("/login_form",function(req,res){
    res.render('login');
});

app.post("/authenticate",function(req,res){
    var username = req.body.username;
    var password = req.body.password;

    if(username === password)
    {
        res.send("Welcome "+username);
    }
    else
    {
        res.send("<b>Error : </b>Invalid Credentials");
    }
});

app.listen(3000,function(){
    console.log("Server Running.");
});