#include<ncurses.h>
#include"tui.h"

int main()
{
    initscr();
    keypad(stdscr, TRUE);
    noecho();

    int height, width, start_y, start_x, key, i;
    height = 15;
    width = 40;
    start_y = start_x = 10;

    WINDOW *mainBox = newwin(height, width, start_y, start_x);
    box(mainBox, 0, 0);
    mvwprintw(mainBox, 1, 1, "My main box");

    WINDOW *coordinatesBox = newwin(height, width, start_y, start_x + width + 1);
    box(coordinatesBox, 0, 0);
    mvwprintw(coordinatesBox, 1, 1, "My coordinates box");

    WINDOW *currentWindow = mainBox;


    while((key = getch()) != 'q'){
      wrefresh(coordinatesBox);
      wrefresh(mainBox);
  
      if(key == '\t'){
        if(currentWindow == mainBox){
          currentWindow = coordinatesBox;
          i = 2;
        }else{
          currentWindow = mainBox;
          i = 1;
        }
      }

      //wattron(currentWindow, A_STANDOUT);
      //box(currentWindow, 0, 0);
      mvwprintw(currentWindow, 2, 1, "My %d box", i);
      //wattroff(currentWindow, A_STANDOUT);
      wrefresh(currentWindow);
    }


    delwin(mainBox);
    delwin(coordinatesBox);
    endwin();
    return 0;
}
