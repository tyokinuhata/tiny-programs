import urllib.request

from html.parser import HTMLParser

URL = 'https://google.com'

class MyHTMLParser(HTMLParser):
    def handle_starttag(self, tag, attrs):
        if tag == 'a':
            print(attrs)

    def handle_endtag(self, tag):
        pass

    def handle_data(self, data):
        pass

res = urllib.request.urlopen(URL)
html = res.read()
parser = MyHTMLParser()
parser.feed(html.decode('utf-8'))
