#ifndef INPUT_H
#define INPUT_H

struct cursor_pos {
	int y;
	int x;
};

struct cursor_pos input_move(int key);

#endif // INPUT_H
