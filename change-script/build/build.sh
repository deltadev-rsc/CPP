#!/usr/bin/bash

mkdir ../bin/

function build {
  g++ ../chscript.cpp -o ../bin/cs -lncursesw
  ../bin/cs
}

build
