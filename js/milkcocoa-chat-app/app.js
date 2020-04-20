const mc = new MilkCocoa('icej6hziqtg.mlkcca.com')
const ds = mc.dataStore('chat')
const msg = document.getElementById('msg'),
      send = document.getElementById('send'),
      board = document.getElementById('board')

send.addEventListener('click', () => {
  const text = msg.value
  sendText(text)
})

const sendText = text => {
  ds.push({ message: text })
}

ds.on('push', data => {
  addText(data.value.message)
})

const addText = text => {
  const msgDom = document.createElement('li')
  msgDom.appendChild(document.createTextNode(text))
  board.appendChild(msgDom)
  board.removeChild(board.firstChild)
}

const stream = ds.stream().size(10).next((err, data) => {
  data.forEach((d, i) => {
    const msgDom = document.createElement('li')
    msgDom.appendChild(document.createTextNode(d.value.message))
    board.appendChild(msgDom)
  })
})