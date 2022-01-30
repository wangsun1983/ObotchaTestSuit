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
          if [ "$element" == "./testAsyncOutputChannel" ];then
            echo ---- Do not test AsyncOutputChannel ------------
          elif [ "$element" == "./testEpollObserver" ];then
            echo ---- Do not test EpollObserver ------------
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
        if [ -d $element ];then
      			if [ "$element" == "./testAsyncOutputChannel" ];then
      				echo ---- Do not test AsyncOutputChannel ------------
      			elif [ "$element" == "./testEpollObserver" ];then
      				echo ---- Do not test EpollObserver ------------
            elif [ "$element" == "./testFileWatcher" ];then
      				echo ---- Do not test FileWatcher ------------
            elif [ "$element" == "./testMappedFile" ];then
      				echo ---- Do not test MappedFile ------------
      		  else
              test $element
            fi
        fi
    done
}

function prebuild() {
    cd $1
    rm core
    rm mytest
    rm -rf tmp
    mkdir tmp
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
