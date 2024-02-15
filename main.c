#include<ncurses.h>

int main()
{
    initscr();

    int height, width, start_y, start_x;
    height = 15;
    width = 40;
    start_y = start_x = 10;
    WINDOW *win = newwin(height, width, start_y, start_x);
    refresh();

    box(win, 0, 0);
    mvwprintw(win, 1, 1, "This is my box");
    wrefresh(win);



    int x = getch();  
    endwin();
    return 0;
}
