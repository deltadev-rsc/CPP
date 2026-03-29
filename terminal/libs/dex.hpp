#ifndef DEX_HPP
#define DEX_HPP

#include <cstdio>
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

/*---colors---*/
#define T_RED "\033[38;2;255;0;0m"
#define T_GREEN "\033[38;2;0;255;0m"
#define T_BLUE "\033[38;2;0;0;255m"
#define T_YELLOW "\033[38;2;255;255;0m"
#define T_CYAN "\033[38;2;0;255;255m"
#define T_RESET "\033[0m"
#define T_MAGENTA "\033[0;35m"

/*---constants---*/
#define MAX_LINES 512
#define MAX_LINE_LENGTH 1024
#define MFNL 256

void addFile(char fileName[MFNL]);
void displayFile(char fileName[MFNL]);
void editorLogo();
void editor();

#endif
