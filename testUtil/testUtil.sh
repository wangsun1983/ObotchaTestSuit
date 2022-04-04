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
          if [ "$element" == "./testConcurrent" ];then
              cd $element
              ./testConcurrent.sh
              cd ..
          elif [ "$element" == "./testText" ];then
              cd $element
              ./testText.sh
              cd ..
          else
              prebuild $element
          fi
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
            test $element
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

function test() {
  cd $1
  ./mytest
  cd ..
}

ulimit -c unlimited
start
