const userId = 'tyokinuhata'

const xhr = new XMLHttpRequest()
xhr.open('GET', `https://api.github.com/users/${userId}`)
xhr.send()
xhr.addEventListener('load', (event) => {
  console.log(event.target.status)
  console.log(event.target.responseText)
})
