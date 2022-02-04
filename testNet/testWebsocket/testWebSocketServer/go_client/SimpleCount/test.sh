#!/bin/bash

for ((i=1; i<=1024*32; i++))
do
{
    ./mytest
} &
sleep 1
./client
wait
sleep 3
done
