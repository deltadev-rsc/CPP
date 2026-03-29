#include "libs/dex.hpp"
#include <cstdio>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
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

void displayFile(char fileName[MFNL])
{
    char line[MAX_LINES];
    FILE * file;
    int isDisplaying;

    file = NULL;
    isDisplaying = 0;

    cout << T_CYAN << "[input file name to display]: " << T_RESET << endl;

    if (scanf("%511s", fileName) != 1) {
        cout << T_RED << "[err]: [failed to reading file name!]" << T_RESET << endl;
        return;
    }
    
    file = fopen(fileName, "r");
    if (file == NULL) {
        cout << T_RED << "[err]: [failed to open file for reading]" << T_RESET << endl;
        return;
    }

    isDisplaying = 1;
    while (fgets(line, sizeof(line), file) != NULL) {
        fputs(line, stdout);
    }

    fclose(file);
    isDisplaying = 0;
}

void addFile(char fileName[MFNL])
{
    int isCreated = 0;
    FILE * file = fopen(fileName, "a");

    if (file == NULL) {
        cout << T_RED << "[FAILED TO CREATE FILE!]" << T_RESET << endl;
        isCreated = 0;
    }
    else {
        fclose(file);
        isCreated = 1;
    }
}

void editorLogo()
{
    cout << T_MAGENTA << "████████        ███████     █       █   ██  ████████        ███████" << T_RESET << endl;
    cout << T_MAGENTA << "██     ██      ██     ██    ██     ██       ██     ██      ██     ██" << T_RESET << endl;
    cout << T_MAGENTA << "██      ██    ██       ██    ██   ██    ██  ██      ██    ██       ██" << T_RESET << endl;
    cout << T_MAGENTA << "██       ██  ██         ██    █████     ██  ██       ██  ██         ██" << T_RESET << endl;
    cout << T_MAGENTA << "██       ██  █████████████   ██   ██    ██  ██       ██  █████████████" << T_RESET << endl;
    cout << T_MAGENTA << "██      ██    ██            ██     ██   ██  ██      ██    ██" << T_RESET << endl;
    cout << T_MAGENTA << "█████████      ██████████   █       █   ██  █████████      ██████████" << T_RESET << endl;
}

void editor()
{
    char lines[MAX_LINES][MAX_LINE_LENGTH];
    char fileName[MFNL];
    char mode;
    int lineCount;
    FILE * file;

    system("clear");
    editorLogo();

    cout << T_CYAN << "[welcome to the DEXIDE!]" << T_RESET << endl;
 
    cout << "[input file name to edit]" << endl;
    cin >> fileName;
    getchar();
    addFile(fileName);

    file = fopen(fileName, "r");
    if (file == NULL) {
        fprintf(stderr, T_RED "[err]: [fail to open file: %s]\n" T_RESET, fileName);
        return;
    }

    while (fgets(lines[lineCount], sizeof(lines[lineCount]), file) != NULL && lineCount < MAX_LINES) {
        lineCount++;
    }
    fclose(file);

    cout << T_CYAN << "['w' for input text, 'r' for read, 'q' for exit]: " << T_RESET << endl;
    while ((mode = getchar()) != 'q') {
        
        if (mode == 'w') {
            
            cout << "[start input('E' for exit)]: " << endl;
            while (lineCount < MAX_LINES) {
                if (fgets(lines[lineCount], sizeof(lines[lineCount]), stdin) == NULL) {
                    fprintf(stderr, T_RED "[err]: [error to read string]\n" T_RESET); 
                    break;
                }

                lines[lineCount][strcspn(lines[lineCount], "\n")] = 0;

                if (strlen(lines[lineCount]) == 0 || strcmp(lines[lineCount], "E") == 0) {
                    break;
                }

                strcpy(lines[lineCount], lines[lineCount]);
                lineCount++;
                    
                if (lineCount >= MAX_LINES) {
                    cout << T_YELLOW << "[warn]: [the maximum number of lines has been reached. Complete the entry]" << T_RESET << endl;
                    break;
                }
            }

            if (mode == 'r') {
                displayFile(fileName);
            }
        }
    }

    file = fopen(fileName, "w");
    if (file == NULL) {
        fprintf(stderr, T_RED "[err]: [failed to open file for writing: %s]\n" T_GREEN, fileName);
        return;
    }

    for (int i = 0; i < lineCount; i++) {
        fprintf(file, "%s\n", lines[i]);
    }
    fclose(file);

    cout << T_CYAN << "[exit editor...]" << T_RESET << endl;
    system("clear");
}
