#include "my.hpp"
#include <iostream>


void first_bucle()
{}

int main(int ac, char **av)
{
    init_pair(1, COLOR_BLUE, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_WHITE, COLOR_BLACK);
    init_pair(4, COLOR_RED, COLOR_BLACK);

    (void)ac;
    (void)av;
    initscr();
    keypad(stdscr, TRUE);
    curs_set(0);
    noecho();
    int height, width, start_y,  start_x;
    height = LINES;
    width = COLS;
    start_y = start_x = 0;
    WINDOW *win = newwin(height, width, start_y, start_x);
    box(win, 0, 0);
    WINDOW *maVersion = newwin(height/2.9, width/2.07, height/40, width/50);
    box(maVersion, 0, 0);
    Version ver;
    WINDOW *Hostname = newwin(height/2.9, width/2.07, height/40, width/2);
    box(Hostname, 0, 0);
    WINDOW *box3 = newwin(height/2.9, width/2.07, height/2.8, width/50);
    box(box3, 0, 0);
    WINDOW *box4 = newwin(height/2.9, width/2.07, height/2.8, width/2);
    box(box4, 0, 0);
    WINDOW *box5 = newwin(height/3.2, width/2.07, height/1.45, width/50);
    box(box5, 0, 0);
    WINDOW *box6 = newwin(height/3.2, width/2.07, height/1.45, width/2);
    box(box6, 0, 0);
    int key = 0;
    while ((key = getch()) != 27) { // Go sigaction pour fermer pas de getch de merde merci
        Process b;
        Date_Time a;
        Name n;
        Version ver;
        if (key == KEY_RESIZE);
        //wresize(win, LINES/2, COLS/2);
        wrefresh(win);
        wrefresh(Hostname);
        wrefresh(maVersion);
        wrefresh(box3);
        wrefresh(box4);
        wrefresh(box5);
        wrefresh(box6);
        attron(COLOR_PAIR(2));
        mvwprintw(win, height/5, width/6, "Version : %s", ver.getVersion().c_str());
   	    mvwprintw(win, height/5, width/1.5, "Date is %s", a.getDate().c_str());
   	    mvwprintw(win, height/2, width/6, "Cpu Usage is at %s", b.getCpuUsage().c_str());
   	    mvwprintw(win, height/2, width/1.5, "It is %s hour O'Clock", a.getTime().c_str());
   	    mvwprintw(win, height/1.2, width/6, "The Host of the machine is %s", n.getHostname().c_str());
   	    mvwprintw(win, height/1.2, width/1.5, "The User using currently this machine is %s", n.getUsername().c_str());
        refresh();
    }
    endwin();
    return (0);
}
