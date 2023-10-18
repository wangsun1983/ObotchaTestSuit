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

class S(BaseHTTPRequestHandler):
    def do_HEAD(self):
        self.send_response(200)
        self.send_header('Content-type', 'text/html')
        self.end_headers()

    def do_GET(self):
        print("aaaa")
        self.send_response(200)
        self.send_header('transfer-encoding', 'chunked')
        self.send_header('Content-Type', 'text/plain')
        self.end_headers()
        file_size = os.path.getsize('./tmp/testdata')
        print("file_size is " + str(file_size))
        with open('./tmp/testdata', 'r+') as f:
            while file_size > 0:
                if file_size > 4096:
                    data = f.read(4096)
                    chunk = '{0:x}\r\n'.format(len(data)) + str(data) + '\r\n'
                    self.wfile.write(chunk.encode(encoding='utf-8'))
                    file_size = file_size - 4096;
                else:
                    data = f.read(file_size)
                    chunk = '{0:x}\r\n'.format(len(data)) + str(data) + '\r\n'
                    self.wfile.write(chunk.encode(encoding='utf-8'))
                    file_size = 0
                    break
         # writing close sequence
        close_chunk = '0\r\n\r\n'
        self.wfile.write(close_chunk.encode(encoding='utf-8'))
        time.sleep(1)
        os._exit(0)
        
    def do_POST(self):
        ctype, pdict = cgi.parse_header(self.headers['Content-Type'])
        if ctype == 'multipart/form-data':
            pdict['boundary'] = bytes(pdict['boundary'], 'utf-8')
            fields = cgi.parse_multipart(self.rfile, pdict)
            fo = open("./tmp/getdata", "wb")
            fo.write(fields.get("testdata")[0])
            fo.close()
            self.send_response(200)
            self.send_header('Content-type', 'text/html')
            self.end_headers()
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