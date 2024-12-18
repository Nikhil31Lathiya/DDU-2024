var express = require("express");
var app = express();
var os = require("os");

app.get('/architecture',function(req,res){
    res.send("Server Architecture : "+os.arch());
});

app.get('/cpu',function(req,res){
    res.send(os.cpus());
});

app.get('/freemem',function(req,res){
    res.send("Free Memoy : "+os.freemem());
});

app.get('/avgload',function(req,res){
    res.send("Average Load : "+os.loadavg());
});

app.get('/osplatform',function(req,res){
    res.send("Platform : "+os.platform());
});

app.get('/version',function(req,res){
    res.send("Version : "+os.version());
});

app.get('/user',function(req,res){
    res.send(os.userInfo());
});

app.listen(3000, function () {
    console.log('Server is running on http://localhost:3000');
});
