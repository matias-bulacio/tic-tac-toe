#include <include/input.h>
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
		struct cursor_pos cursor_pos = input_move(c);

		addch('#');
		move(cursor_pos.y, cursor_pos.x);

		if (c == 'q') {
			keep_open = false;
		}

		refresh();
	}

	return 0;
}
