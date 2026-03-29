/*
    редактор маленько не работает так что
    не кидайтесь тапками пж.
*/
#include <iostream>
#include <string>
#include <stdio.h>
#include "./libs/dex.hpp"

/* constants */
#define MAX_DISK_MEMORY 32768
#define IN 1
#define OUT 0

/* strutures */
typedef struct {
    const char user_name[128];
    const char os_title[128];
    const char host_name[128];
    const char cpu[128];
    const char gpu[128];
    double disk_memory[MAX_DISK_MEMORY];
} fetch;

typedef struct {
    const char kitty[128];
    const char alacritty[128];
    const char ghostty[128];
    const char rio[128];
    const char konsole[128];
    const char blackbox[128];
    const char console[128];
} terms;

using namespace std;

int main()
{
    string firstLine =   ".___________________________.";
    string secondLine =  "|                           |";
    string thirdLine =   "|[ Welcome to the FenixOS! ]|";
    string fourthLine =  "|___________________________|";
    string warn = "write 'help'";

    cout << firstLine << endl;
    cout << secondLine << endl;
    cout << thirdLine << endl;
    cout << fourthLine << endl;
    cout << warn << endl;

    string command;
    while (true) {
        cout << "user@host";
        cout << T_CYAN << "~" << T_RESET;
        cout << "$ > ";

        cin >> command;
        if (command == "calc") {
            cout << T_BLUE << "[калькулятор]" << T_RESET << endl;

            int num_1, num_2;
            char sym;
            double res;

            int inputResult;
            cin >> num_1;
            cin >> sym; 
            cin >> num_2;

            if (inputResult != 3) 
            {
                cout << T_RED << "[неверный ввод!]" << T_RESET << endl;
                while (getchar() != '\n');
                continue;
            }

            switch (sym)
            {
                case '+':
                    res = num_1 + num_2;
                    break;
                case '-':
                    res = num_1 - num_2;
                    break;
                case '*':
                    res = num_1 * num_2;
                    break;
                case '/':
                    if (num_2 == 0) {
                        cout << T_RED << "[деление на ноль]" << T_RESET << endl;
                        while (getchar() != '\n');
                        continue;
                    }

                    res = num_1 / num_2;
                    break;
                default:
                    cout << T_RED << "[неверный символ операции]" << T_RESET << endl;
                    while (getchar() != '\n');
                    continue;
            }

            cout << T_GREEN << "[результат]: " << T_RESET;
            cout << res << endl;
            cout << T_BLUE << "[калькулятор завершил работу]" << T_RESET << endl;
        }

        else if (command == "edit") {
            editor();
        }

        else if (command == "fetch") {
            cout << T_CYAN << "info of OS" << T_RESET << endl;
            
            fetch info = {
                .user_name = "user@host",
                .os_title = "Phoenix Shel Sub-System",
                .host_name = "laptop",
                .cpu = "kartofan procyk",
                .gpu = "ventilator 300",
                .disk_memory = 128
            };

            terms terms_db = {
                .kitty = "kitty",
                .alacritty = "alaritty",
                .ghostty = "ghostty",
                .rio = "rio",
                .konsole = "konsole",
                .blackbox = "чёрный ящик",
                .console = "консоль"
            };

            cout << T_YELLOW << "_______                                  User: " << info.user_name << T_RESET << endl;
            cout << T_YELLOW << "|     |                                  OS: " << info.os_title << T_RESET << endl;
            cout << T_YELLOW << "| ___ |                                  Kernel: ?" << T_RESET << endl;
            cout << T_YELLOW << "| |_| |                                  Shell: fnxsh 0.0.5" << T_RESET << endl;
            cout << T_YELLOW << "| ____|                                  Terminal: termitex" << T_RESET << endl;
            cout << T_YELLOW << "| |  __      __ __   __   \\ \\  / /       Host: " << info.host_name << T_RESET << endl;
            cout << T_YELLOW << "| |  | |___  | |\\ \\  | |   \\_\\/_/        CPU: " << info.cpu << T_RESET << endl;
            cout << T_YELLOW << "| |  | |_| | | | \\ \\ | |   / /\\ \\        GPU: " << info.gpu << T_RESET << endl;
            cout << T_YELLOW << "|_|  |_| |_| |_|  \\_\\|_|  /_/  \\_\\       Disk Memory: " << info.disk_memory << "GB" << T_RESET << endl;
        } 

        else if (command == "lsf") {
            cout << T_CYAN << "[файл для работы системы]" << endl;
            cout << "terminal.cpp" << endl;
            cout << "term.elf" << T_RESET << endl;
        }

        else if (command == "help") {
            cout << "[все команды]" << endl;
            string calc = "1.calc - запускает консольный калькулятор";
            string editor = "2.edit - запуск текстового редактора";
            string fetch = "3.fetch - просто как неофетч но покачто без лого";
            string help = "4.help - вывод всех команд что есть на данный момент";
            string lsf = "5.lsf - выводит список системных файлов";
            cout << calc << endl;
            cout << editor << endl;
            cout << fetch << endl;
            cout << help << endl;
            cout << lsf << endl;
        }

        else if (command == "exit") {
            break;
        }

        else {
            cout << T_RED << "not command!" << T_RESET << endl;
        }
    }
    return 0;
}
