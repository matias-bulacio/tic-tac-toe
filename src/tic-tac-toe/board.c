#include <assert.h>
#include <include/tic-tac-toe/board.h>
#include <curses.h>

BOARD ttt_new_board(int y, int x) {
	BOARD b = {
		.base_x = x,
		.base_y = y,
		.pieces = {0},
	};

	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			b.pieces[i][j] = PLAYER_NONE;

	return b;
}

void ttt_draw_board(BOARD *b){
	/*
	 *
	 * +---+---+---+
	 * |   | O | X |
	 * +---+---+---+
	 * | O | X |   |
	 * +---+---+---+
	 * | O |   |   |
	 * +---+---+---+
	 *
	 * */

	int prev_y, prev_x;
	getyx(stdscr, prev_y, prev_x);

	move(b->base_y, b->base_x);
	for(int i = b->base_y; i < b->base_y + 3*2; i+=2) {
		mvaddstr(i, b->base_x,   "+---+---+---+");
		mvaddstr(i+1, b->base_x, "|   |   |   |");
	}
	mvaddstr(b->base_y + 3*2, b->base_x,   "+---+---+---+");

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			mvaddch(b->base_y + 1 + i*2, b->base_x + 1 + j*2, (char)b->pieces[i][j]);
		}
	}
	move(prev_y, prev_x);
}

void ttt_add_piece(BOARD *b, board_row y, board_column x, player p) {
	assert(y < 3 && x < 3);

	b->pieces[y][x] = p;
}
