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

cell_t (*GRID_Create(void))[ROWS];
void GRID_Free(cell_t (*grid)[ROWS]);
bool IS_wall(int x, int y, cell_t grid[COLS][ROWS]);
int TAKE_source(cell_t grid[COLS][ROWS]);
int TAKE_dest(cell_t grid[COLS][ROWS]);

#endif