#ifndef TIC_TAC_TOE_BOARD
#define TIC_TAC_TOE_BOARD

#include <include/coords.h>
#include <stdint.h>
struct board {
	int base_x;
	int base_y;
	char pieces[3][3];
};

typedef struct board BOARD;

typedef char player;

#define PLAYER_X ((player)'X')
#define PLAYER_O ((player)'O')
#define PLAYER_NONE ((player)' ')

#define TTT_COLOR_X 1
#define TTT_COLOR_O 2

BOARD ttt_new_board(int y, int x);
void ttt_draw_board(BOARD *b);
void ttt_add_piece(BOARD *b, coords c, player p);
coords ttt_board_to_term_coords(BOARD *b, coords board_coords);

#endif // TIC_TAC_TOE_BOARD
