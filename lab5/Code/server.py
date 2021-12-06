import http.server
import socketserver

class MyHTTPRequestHandler(http.server.SimpleHTTPRequestHandler):
    def end_headers(self):
        self.send_my_headers()

        http.server.SimpleHTTPRequestHandler.end_headers(self)

    def send_my_headers(self):
        self.send_header("Cross-Origin-Opener-Policy", "same-origin")
        self.send_header("Cross-Origin-Embedder-Policy", "require-corp")

if __name__ == '__main__':
    http.server.test(HandlerClass = MyHTTPRequestHandler)

# PORT = 8080

# class HttpRequestHandler(http.server.SimpleHTTPRequestHandler):
#     extensions_map = {
#         '': 'application/octet-stream',
#         '.manifest': 'text/cache-manifest',
#         '.html': 'text/html',
#         '.png': 'image/png',
#         '.jpg': 'image/jpg',
#         '.svg':	'image/svg+xml',
#         '.css':	'text/css',
#         '.js':'application/x-javascript',
#         '.wasm': 'application/wasm',
#         '.json': 'application/json',
#         '.xml': 'application/xml',
#     }

# httpd = socketserver.TCPServer(("localhost", PORT), HttpRequestHandler)

# try:
#     print(f"serving at http://localhost:{PORT}")
#     httpd.serve_forever()
# except KeyboardInterrupt:
#     pass