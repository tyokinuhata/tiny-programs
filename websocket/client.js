const ws = new WebSocket('ws://127.0.0.1:5001')

ws.addEventListener('open', event => {
  console.log('Connection opened.')
})

ws.addEventListener('close', event => {
  console.log('Connection closed.')
})

ws.addEventListener('message', event => {
  console.log('Received: ' + event.data)
})

document.getElementById('send').addEventListener('click', event => {
  ws.send('hello!')
})
