#include <curses.h>
#include <include/app.h>
#include <locale.h>
#include <stdlib.h>

void endwin_(void) {endwin();}

int app(void) {
	setlocale(LC_ALL, "C");

	initscr(); cbreak(); noecho();

	intrflush(stdscr, false);
	keypad(stdscr, true);
	curs_set(2);

	// Using atexit so we cover all posible calls to exit()
	atexit(endwin_);

	bool keep_open = true;
	while (keep_open) {
		int c = getch();
		int y = 0, x = 0;
		int begy = 0, begx = 0;
		int maxy = 0, maxx = 0;
		getyx(stdscr, y, x);
		getbegyx(stdscr, begy, begx);
		getmaxyx(stdscr, maxy, maxx);

		switch (c) {
		case 'k':
		case KEY_UP:
			if(y > begy) y--;
			move(y, x);
			break;
		case 'j':
		case KEY_DOWN:
			if(y < maxy) y++;
			move(y, x);
			break;
		case 'h':
		case KEY_LEFT:
			if(x > begx) x--;
			move(y, x);
			break;
		case 'l':
		case KEY_RIGHT:
			if(x < maxx) x++;
			move(y, x);
			break;
		case 'q':
			keep_open = false;
			break;
		}
		
		refresh();
	}

	return 0;
}
