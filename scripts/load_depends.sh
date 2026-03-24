#!/bin/bash

clear

install_deps() {
    while true; do 
        echo "choose your distro group"    
        echo "1.arch, 2.void, 3.debian"
        read group

        if [ "$group" == "1" ]; then
            sudo pacman -S ncurses
            sudo pacman -S gcc g++ make
            break
        elif [ "$group" == "2" ]; then
            sudo xbps-install -S ncurses ncurses-base ncurses-devel ncurses-libs
            sudo xbps-install -S gcc g++ make
            break 
        elif [ "$group" == "3" ]; then
            sudo apt install ncurses 
            sudo apt install gcc g++ make
            break
        else 
            echo "choose only 1, 2 or 3"
        fi
    done
}

install_deps

