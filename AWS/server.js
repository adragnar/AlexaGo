var http = require("http");
var express = require("express");
var url = require('url');
var PythonShell = require("python-shell");

var port = 3000;
var app = express();

app.post("/post_data", function(req, res) {
  var request_url = url.parse(req.url, true);
  console.log("Incoming POST request to " + request_url.pathname + " from " + req.connection.remoteAddress);

  res.writeHead(200, {"Content-Type": "application/json"});

  PythonShell.run("run.py", function(pyerr, pyres) {
    if(pyerr) {
      console.log(pyerr);
      //res.end(JSON.stringify({"status" : "failure"}));
    }

    console.log(pyres);

    res.end(JSON.stringify({"status" : "success"}));
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
