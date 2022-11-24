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
            echo -------start test $element -------
            test $element
            echo -------finish test $element -------
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

    go build client.go
    cd ..
}

function test() {
  cd $1
  ./mytest &
  sleep 10
  ./client
  wait $!

  sleep 10
  cd ..
}

ulimit -c unlimited
start
