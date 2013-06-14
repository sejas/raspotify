

var http = require('http');
http.createServer(function (req, res) {
	var query = require('url').parse(req.url,true).query;
	var operacion= "next";
	if(query.op=='prev'){
		operacion='prev';
	}


  res.writeHead(200, {'Content-Type': 'text/plain'});
  // res.end('Hello World\n');
  // http://nodejs.org/api.html#_child_processes
  var sys = require('sys')
  var exec = require('child_process').exec;
  var child;
   
  // executes `pwd`
  child = exec("console/spotify "+operacion, function (error, stdout, stderr) {
	  sys.print('stdout: ' + stdout);
	  sys.print('stderr: ' + stderr);
	  res.end('<pre>'+stdout+'</pre>');
	  if (error !== null) {
	 	 console.log('exec error: ' + error);
	  }
  });

}).listen(1337, '192.168.0.5');
console.log('Server running at http://127.0.0.1:1337/');

