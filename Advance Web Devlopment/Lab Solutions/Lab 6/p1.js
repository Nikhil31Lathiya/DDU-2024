var express = require("express");
var fs = require("fs");
var app = express();

// Synchronous Way
app.get('/f-sync', function (req, res) {
    var data = fs.readFileSync("file.txt",'utf8');
    res.send(data);
});

// Asynchronous way
app.get('/a-sync',function(req,res){
    fs.readFile('file.txt','utf8',function(err,data){
        if(err)
        {
            res.send("Error Occured While Opening file");
            console.log(err);
        }
        else
        {
            res.send(data);
            console.log("File Opened Successfully");
        }

    });
});

app.listen(3000, function () {
    console.log('Server is running on http://localhost:3000');
});