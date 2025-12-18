#include <include/coords.h>
#include <include/tic-tac-toe/board.h>
#include <include/input.h>
#include <curses.h>
#include <include/app.h>
#include <locale.h>
#include <stdlib.h>

void endwin_(void) {endwin();}

void setup(void) {
	setlocale(LC_ALL, "C");

	initscr(); cbreak(); noecho();

	start_color();
	init_pair(TTT_COLOR_X, COLOR_RED, COLOR_BLACK);
	init_pair(TTT_COLOR_O, COLOR_BLUE, COLOR_BLACK);

	intrflush(stdscr, false);
	keypad(stdscr, true);
	curs_set(2);

	// Using atexit so we cover all posible calls to exit()
	atexit(endwin_);
}

int app(void) {
	setup();

	BOARD b = ttt_new_board(5, 5);

	coords bc = {
		.x = 1,
		.y = 1,
	};

	coords pos = ttt_board_to_term_coords(&b, bc);
	cmove(pos);

	player turn = PLAYER_X;
	bool keep_open = true;
	bool should_refresh = true;

	while (keep_open) {
		// Draw
		if(should_refresh) {
			ttt_draw_board(&b);

			refresh();
			should_refresh = false;
		}

		// Fetch
		int c = getch();

		// Compute
		bc = input_move(c, bc);
		pos = ttt_board_to_term_coords(&b, bc);

		cmove(pos);
		if(c == (char)turn) {
			ttt_add_piece(&b, bc, turn);

			if(turn == PLAYER_X) turn = PLAYER_O;
			else if(turn == PLAYER_O) turn = PLAYER_X;

			cmove(pos);

			should_refresh = true;
		}

		if (c == 'q') {
			keep_open = false;
		}
	}

	return 0;
}
