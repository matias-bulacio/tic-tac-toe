#include <include/coords.h>
#include <include/tic-tac-toe/board.h>
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
	BOARD b = ttt_new_board(5, 5);

	ttt_draw_board(&b);

	coords bc = {
		.x = 1,
		.y = 1,
	};
	coords pos = ttt_board_to_term_coords(&b, bc);
	cmove(pos);


	bool keep_open = true;
	while (keep_open) {
		// Draw
		refresh();

		// Fetch
		int c = getch();

		// Compute
		bc = input_move(c, bc);
		pos = ttt_board_to_term_coords(&b, bc);
		cmove(pos);

		if (c == 'q') {
			keep_open = false;
		}
	}

	return 0;
}
