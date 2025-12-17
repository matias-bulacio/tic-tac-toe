#ifndef COORDS_H
#define COORDS_H

struct coords {
	int y;
	int x;
};

typedef struct coords coords;
#define COORDS_YX(c) (c).y, (c).x
#define cmove(c) move((c).y, (c).x)


#endif // COORDS_H
