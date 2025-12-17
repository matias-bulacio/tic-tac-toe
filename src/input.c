#include <include/coords.h>
#include <include/input.h>
#include <curses.h>

coords input_move(int key, coords c) {
	int y = c.y;
	int x = c.x;
	// getyx(stdscr, y, x);

	int begy = 0, begx = 0;
	// getbegyx(stdscr, begy, begx);

	int maxy = 2, maxx = 2;
	// getmaxyx(stdscr, maxy, maxx);


	switch (key) {
		case 'k':
		case KEY_UP:
			if(y > begy) y--;
			break;
		case 'j':
		case KEY_DOWN:
			if(y < maxy) y++;
			break;
		case 'h':
		case KEY_LEFT:
			if(x > begx) x--;
			break;
		case 'l':
		case KEY_RIGHT:
			if(x < maxx) x++;
			break;
	}

	coords ret = {
		.y = y,
		.x = x,
	};
	return ret;
}
