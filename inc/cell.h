#ifndef CELL_H
#define CELL_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define COLS 10
#define ROWS 10
#define NUM_VERTICES 100

#define MAX_NEIGHBOR 4

extern const int screenHeight;
extern const int screenWidth;

extern const int cellWidth;
extern const int cellHeight;

struct cell_t
{
    int vertex;
    int x;
    int y;
    bool IS_visited;
    bool IS_containWall;
    bool IS_source;
    bool IS_dest;
    bool IS_inPath;
    struct cell_t *neighbor;
};

typedef struct cell_t cell_t;

cell_t** GRID_Create(void);
void GRID_Free(cell_t** grid);
bool IS_wall(int x, int y, const cell_t** grid);
int TAKE_source(const cell_t** grid);
int TAKE_dest(const cell_t** grid);

#endif