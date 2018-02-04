var http = require("http");
var fs = require("fs");
var express = require("express");
var url = require('url');
var PythonShell = require("python-shell");
var bp = require("body-parser");

var port = 3000;
var app = express();

app.use(bp.urlencoded({extended : true}));
app.use(bp.json({limit: "100mb"}));

app.post("/post_data", function(req, res) {
  var request_url = url.parse(req.url, true);
  console.log("Incoming POST request to " + request_url.pathname + " from " + req.connection.remoteAddress);

  res.writeHead(200, {"Content-Type": "application/json"});

  var img = req.body.img;
  fs.writeFile("../yolo-9000/darknet/data/tmp.png", img, 'base64', function(err) {
    if(err) {
      console.log(err);
      res.end(JSON.stringify({"status" : "failure"}));
    } else {
      PythonShell.run("run.py", function(pyerr, pyres) {
        if(pyerr) {
          console.log(pyerr);
          res.end(JSON.stringify({"status" : "failure"}));
        }

        var data = JSON.parse(pyres[0]);
        console.log(data);
        res.end(JSON.stringify({
          "status" : "success",
          "data" : data
        }));
      });
    }
  });




  // var tag = req.body.tag;
  // PythonShell.run("../find_companies/find_companies.py", {pythonPath:"python", args:[tag]}, function(pyerr, pyres) {
  //   res.end(JSON.stringify({"status":pyerr ? "fail" : "success"}));
  //
  //   //if(pyerr) throw pyerr;
  //   console.log(pyerr);
  //   console.log(pyres);
  // });
});

app.listen(port);
console.log('Listening at http://localhost:' + port)
