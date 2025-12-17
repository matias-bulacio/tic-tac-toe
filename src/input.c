#include <include/input.h>
#include <curses.h>

struct cursor_pos input_move(int key) {
		int y, x;
		getyx(stdscr, y, x);

		int begy, begx;
		getbegyx(stdscr, begy, begx);

		int maxy, maxx;
		getmaxyx(stdscr, maxy, maxx);


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

		struct cursor_pos ret = {
			.y = y,
			.x = x,
		};
		return ret;
}
