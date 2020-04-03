import urllib.request

URL = 'https://google.com'

res = urllib.request.urlopen(URL)
html = res.read()
print(html.decode('utf-8'))
