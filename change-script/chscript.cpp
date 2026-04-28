/*
  обязательно посмотрите где у вас лежат скрипты
  поменяйте названия, пути и прочие другое
  я сделал чисто для своих скриптов которые у меня валяются
*/
#include <ncurses.h>
#include <string>
#include <string.h>
#include <vector>
#include <locale.h>
#include <cstdlib>  
#include <cstdio>

using namespace std;

void printCommandOutput(WINDOW *outWin, const string &cmd) 
{
    werase(outWin);
    box(outWin, 0, 0);
    mvwprintw(outWin, 1, 1, "Command Output");
    mvwprintw(outWin, 1, 2, "%s", cmd.c_str());
    wrefresh(outWin);

    FILE *pipe = popen(cmd.c_str(), "r");
    if (!pipe) {
        mvwprintw(outWin, 2, 2, "[err]: [failed to exevute command]");
        wrefresh(outWin);
        return;
    }

    const int maxLine = getmaxy(outWin) - 3;
    const int maxCol = getmaxx(outWin) - 3;
    char line[1024];
    int row = 2;

    while (fgets(line, sizeof(line), pipe) && row < maxLine) {
        line[strcspn(line, "\n")] = '\0';
        line[maxCol] = '\0';
        mvwprintw(outWin, row++, 2, "%s", line);
    }

    pclose(pipe);
    wrefresh(outWin);
}

int main()
{
    setlocale(LC_ALL, "");

    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);

    int termH = LINES, termW = COLS;

    int menuW = termW * 2 / 5;
    int menuH = termH - 2; 
    int menuY = 1, menuX = 1;
    WINDOW *menuWin = newwin(menuH, menuW, menuY, menuX);
    keypad(menuWin, TRUE);
    box(menuWin, 0, 0);
    mvwprintw(menuWin, 1, 2, "Scripts menu");

    int outW = termW - menuW - 3;
    int outH = menuH;
    int outY = menuY;
    int outX = menuX + menuW + 1;
    WINDOW *outWin = newwin(outH, outW, outY, outX);
    box(outWin, 0, 0);
    mvwprintw(outWin, 1, 2, "Command output");
    wrefresh(outWin);

    vector<string> scripts = {
        "screen.bash - screenshot",
        "sy.sh - start zapret",
        "run-sddm.sh - create symlink for sddm on Void linux"
    };

    int selected = 0;
    bool running = true;
    int ch;

    while (running) {
        werase(menuWin);
        box(menuWin, 0, 0);
        mvwprintw(menuWin, 1, 2, "Menu for changing scripts");

        for (size_t i = 0; i < scripts.size(); ++i) {
            if ((int)i == selected) wattron(menuWin, A_REVERSE);
            mvwprintw(menuWin, 3 + i, 2, "%zu. %s",
                      i + 1, scripts[i].c_str());
            if ((int)i == selected) wattroff(menuWin, A_REVERSE);
        }

        mvwprintw(menuWin, menuH - 2, 2,
                  "↑/↓ – move | Enter – run | q – quit");
        wrefresh(menuWin);

        ch = wgetch(menuWin);
        switch (ch) {
            case KEY_UP:
                if (selected > 0) --selected;
                break;
            case KEY_DOWN:
                if (selected < (int)scripts.size() - 1) ++selected;
                break;
            case 10: {
                string cmd = "~/scripts/" + scripts[selected].substr(0,scripts[selected].find(' '));
                printCommandOutput(outWin, cmd);
                break;
            }
            case 'q':
            case 'Q':
                running = false;
            break;
            
            default:
                break;
        }
    }

    delwin(menuWin);
    delwin(outWin);
    endwin();
    return 0;
}
