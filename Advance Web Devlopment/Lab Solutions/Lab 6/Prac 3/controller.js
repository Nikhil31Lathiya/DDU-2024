var express = require("express");
var app = express();
var bp = require("body-parser");
var fs = require("fs");

app.set('view engine', 'pug');
app.set('views','./Views');

app.use(bp.urlencoded({ extended: true }));

app.get("/form",function(req,res){
    console.log("Request Received For entry form.");
    res.render('form');
});

app.post("/file_handling",function(req,res){
    var fname = req.body.fname;
    var msg = req.body.msg;

    if(!fname || !msg)
    {
        console.log("Incomplete Form");
        return res.send("Filename and file content are required.");
    }

    var file_path = "./files/"+fname+".txt";
    
    if(!fs.existsSync(file_path))
    {
        console.log("File does not exists. Creating new file");
    }

    fs.writeFile(file_path,msg,function(err){
        if(err)
        {
            console.log("File entry failed");
            res.send("File Entry Failed");
        }
        else
        {
            console.log("File entry successfull");
            res.send("File Entry successfull");
        }
    });
});

app.post('/showfilecontents',function(req,res){
    var fname1 = req.body.fname1;
    
    if(!fname1)
    {
        console.log("Incomplete Form");
        return res.send("Filename required.");
    }

    var file_path = "./files/"+fname1+".txt";

    if(!fs.existsSync(file_path))
    {
        console.log("File does not exists.");
        res.send("<b>Error : </b>File Does Not Exists.");
    }

    fs.readFile(file_path,'utf8',function(err,data){
        if(err)
        {
            res.send("Error Occured While Opening file");
            console.log(err);
        }
        else
        {
            res.send("<h3>Contents inside "+fname1+".txt</h3><br><br>" +data);
            console.log("File COntents Displayed Successfully");
        }

    });
});

app.listen(3000);