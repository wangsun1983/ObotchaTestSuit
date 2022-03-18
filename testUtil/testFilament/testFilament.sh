#!/bin/bash

function start(){
    echo -----------------------
    echo -----Start Prebuild----
    echo -----------------------
    for element in ./*;
    do
        echo $element
        if [ -d $element ]
        then
            prebuild $element
        else
            echo ------------No build $element !!!!!!!!------------
        fi
    done

    echo -----------------------
    echo -----Start Test----
    echo -----------------------
    for element in ./*;
    do
        if [ -d $element ]
        then
            if [ "$element" == "./SimpleConnect" ];then
              testSimpleConnect $element
            else
              test $element
            fi
        else
            echo ------------No Test $element !!!!!!!!------------
        fi
    done
}

function prebuild() {
    cd $1
    rm core
    rm mytest
    echo StartBuild $1
    make -j32
    cd ..
}

function testSimpleConnect() {
    cd $1
    python server.py &
    sleep 1
    ./mytest
    sleep 2
    cd ..
}

function test() {
  cd $1
  ./mytest
  cd ..
}

ulimit -c unlimited
start
