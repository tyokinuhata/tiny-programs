const server = require('ws').Server;
const s = new server({port: 5001});

s.on('connection', ws => {
  console.log('Connection opened.')

  ws.on('message', message => {
    console.log('Received: ' + message)

    s.clients.forEach(client => {
      client.send(message)
    })
  })

  ws.on('close', () => {
    console.log('Connection closed.')
  })
})