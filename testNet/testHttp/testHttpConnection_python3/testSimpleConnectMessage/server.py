import socket
import threading
import time
import http.client
import requests
import os
import os, sys, platform
import posixpath
import http.server
from socketserver import ThreadingMixIn
import threading
import urllib
import cgi
import shutil
import mimetypes
import re
import time
from http.server import BaseHTTPRequestHandler, HTTPServer
import logging

import sys
sys.path.append(r'../../../../common')
from NetPort import getEnvPort
from NetPort import setEnvPort
#https://www.cnblogs.com/mq0036/p/12782181.html

#BaseHTTPServer.HTTPServer is a subclass of SocketServer.
#TCPServer which itself is a subclass of SocketServer.BaseServer. 
#Every time a request comes in it will process the request process_request 
#and then call finish_request. finish_request will instantiate a fresh 
#instance of whatever your request handler is.

class S(BaseHTTPRequestHandler):
    def do_HEAD(self):
        self.send_response(200)
        self.send_header('Content-type', 'text/html')
        self.end_headers()

    def do_GET(self):
        print("do_GET1!!!!!")
        paths = {
            '/foo': {'status': 200},
            '/bar': {'status': 302},
            '/baz': {'status': 404},
            '/qux': {'status': 500},
			'/test': {'status': 200},
        }
	
        if self.path in paths:
            self.respond(paths[self.path])
        else:
            self.respond({'status': 500})
        #logging.info("GET request,\nPath: %s\nHeaders:\n%s\n", str(self.path), str(self.headers))
        #self.wfile.write("GET request for {}".format(self.path).encode('utf-8'))
        time.sleep(1)
        os._exit(0)

    def do_POST(self):
        print("do_POST1!!!!!")
        content_length = int(self.headers['Content-Length']) # <--- Gets the size of data
        post_data = self.rfile.read(content_length) # <--- Gets the data itself

        logging.info("POST request,\nPath: %s\nHeaders:\n%s\n\nBody:\n%s\n",
                str(self.path), str(self.headers), post_data.decode('utf-8'))

        self.do_HEAD()
        self.wfile.write("POST request for {}".format(self.path).encode('utf-8'))

    def respond(self, opts):
        response = self.handle_http(opts['status'], self.path)
        self.wfile.write(response)

    def handle_http(self, status_code, path):
        print("handle http")
        content = "hello"
        self.send_response(status_code)
        self.send_header('Content-type', 'text/html')
        self.send_header('Content-length', len(content))
        self.end_headers()
        return bytes(content, 'UTF-8')

def run(server_class=HTTPServer, handler_class=S, port=8080):
    logging.basicConfig(level=logging.DEBUG)
    server_address = ('', port)
    httpd = server_class(server_address, handler_class)
    logging.info('Starting httpd...\n')
    try:
        httpd.serve_forever()
    except KeyboardInterrupt:
        pass
    httpd.server_close()
    logging.info('Stopping httpd...\n')


if __name__ == '__main__':
	myport = getEnvPort()
	run(port = myport)