var app = require('express')()
var server = require('http').Server(app)
var io = require('socket.io')(server)
var count = 0
var fs = require('fs')
var readline = require('readline')


var execFile = require('child_process').execFile;

app.get('/', function(request, response){
  response.sendFile(__dirname + '/index.html')
})

  io.on('connection', function(socket){
     if (count >= 2)
       {
        console.log('Too many users connected!')
       }
     count++;
  console.log('user ' + count + ' connected.')
  socket.on('disconnect', function(){
    console.log('user ' + count + ' disconnected.')
    count--;
   if (count == 0)
     {
      console.log('Currently no users connected.')
     }
      })
  })

  io.on('connection', function(socket){
  socket.on('chat message', function(msg){
  fs.writeFile("log.txt", msg, function(error){

  if(error) throw error;
  else console.log("file created..");

  execFile('/root/test', function(error, stdout, stderr) {

  var rd = readline.createInterface({
     input: fs.createReadStream(__dirname + '/textfile.txt'),
     output: process.stdout,
     console: false
    })

   rd.on('line', function(line) {
   io.emit('chat message', line)
   fs.unlinkSync(__dirname + '/textfile.txt')
   });


     });
   })
 })
})

server.listen(80)

