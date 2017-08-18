#include <stdio.h>
#include <ncurses.h>
#include <signal.h>

#define CTRL(c) ((c) & 037)

void* resizeHandler(int);
void printStatus();

int x,y = 0;

int main()
{
    // initialize stuff
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    int sideStatusWidth = 10;

    move(0, sideStatusWidth);

    int q = 0;

    int ch = 0;

    do
    {
        getyx(stdscr, y, x);

        ch = getch();

        switch (ch)
        {
            case KEY_UP:
                y--;

                if (y < 0)
                    y = 0;

                move(y,x);
                break;
            case KEY_DOWN:
                y++;
                move(y,x);
                break;
            case KEY_LEFT:
                x--;
                if (x < 0)
                    x = 0;

                move(y,x);
                break;
            case KEY_RIGHT:
                x++;
                move(y,x);
                break;
            case CTRL('x') :
                q = 1;
                break;
            default:
                echochar(ch);
                break;
        }

        printStatus();
    }
    while(q != 1);


    // restore terminal settings
    endwin();

    return 0;
}

void printStatus()
{
    getyx(stdscr, y, x);
    move(LINES-1, 0);
    printw("x: %d, y: %d", x, y);
    move(y,x);
}

void* resizeHandler(int sig)
{
    int nh, nw;
    getmaxyx(stdscr, nh, nw);
}
