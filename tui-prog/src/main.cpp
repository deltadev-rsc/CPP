#include <ncurses.h>
#include <string>

using namespace std;

int main() 
{
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    
    int height = 15;
    int width = 55;
    int starty = (LINES - height) / 4;
    int startx = (COLS - width) / 4;

    WINDOW * win = newwin(height, width, starty, startx);
    box(win, 0, 0);
    mvwprintw(win, 1, 1, "Welcome to the ncurses program!");
    mvwprintw(win, 3, 1, "Please, input a 2 strings:");
    wrefresh(win);

    string input;
    string input2;
    char ch;
    char ch2;
    int y = 6, x = 3;
    int y2 = 7, x2 = 3;

    while ((ch = wgetch(win)) != '\n') {
        if (ch == KEY_BACKSPACE || ch == 127) {
            if (!input.empty()) {
                input.pop_back();
                mvwprintw(win, y, x + input.size(), " ");
                wmove(win, y, x + input.size());
            }
        } 
        else if (ch != 'q') {
            input.push_back(ch);
            mvwprintw(win, y, x + input.size() - 1, "%c", ch);
        }
        wrefresh(win);
    }

    while ((ch2 = wgetch(win)) != '\n') {
        if (ch2 == KEY_BACKSPACE || ch2 == 255) {
            if (!input2.empty()) {
                input2.pop_back();
                mvwprintw(win, y2, x2 + input2.size(), "");
                wmove(win, y2, x2 + input2.size());
            }
        }

        else if (ch2 != 'q') {
            input2.push_back(ch2);
            mvwprintw(win, y2, x2 + input2.size() - 1, "%c", ch2);
        }

        wrefresh(win);
    }

    mvwprintw(win, 9, 1, "Enter 'q' for exit...");
    wrefresh(win);
    while (wgetch(win) != 'q') {}

    delwin(win);
    endwin();
    return 0;
}
