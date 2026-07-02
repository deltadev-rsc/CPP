#!/usr/bin/bash

mkdir -p ./bin/

function build_programs {
    gfortran main.f95 -o bin/main
    gfortran cmd.f95 -o bin/cmd
}

build_programs
