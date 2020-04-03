import http.server

PORT = 8080

http_handler = http.server.SimpleHTTPRequestHandler
httpd = http.server.HTTPServer(('', PORT), http_handler)
httpd.serve_forever()