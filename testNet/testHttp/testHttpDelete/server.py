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
sys.path.append(r'../../../common')
from NetPort import getEnvPort
from NetPort import setEnvPort
#https://www.cnblogs.com/mq0036/p/12782181.html

class S(BaseHTTPRequestHandler):
    def do_HEAD(self):
        self.send_response(200)
        self.send_header('Content-type', 'text/html')
        self.end_headers()

    def do_DELETE(self):
        resp = "DELETE"
        self.send_response(200)
        self.send_header('Content-type', 'text/html')
        self.send_header('Content-length', str(len(resp)))
        self.end_headers()
        self.wfile.write(resp.encode('utf-8'))
        time.sleep(1)
        os._exit(0) 

    def respond(self, opts):
        response = self.handle_http(opts['status'], self.path)
        self.wfile.write(response)
        time.sleep(1)
        os._exit(0)

    def handle_http(self, status_code, path):
        content = "hello"
        self.send_response(status_code)
        self.send_header('Content-type', 'text/html')
        self.send_header('Content-length', len(content))
        self.end_headers()
        return bytes(content, 'UTF-8')

def run(server_class=HTTPServer, handler_class=S, port=8080):
    logging.basicConfig(level=logging.INFO)
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