#!/bin/bash

openssl genrsa -out server.key 2048
openssl req -new -key server.key -out server.csr -batch

echo subjectAltName = IP:127.0.0.1 > extfile.cnf
openssl x509 -req -days 365 -in server.csr -signkey server.key -out server.crt -extfile extfile.cnf
