#include "cell.h"



cell_t (*GRID_Create(void))[ROWS]
{
    cell_t(*grid)[ROWS] = malloc(sizeof(cell_t) * COLS * ROWS);
    int vertexCount = 0;
    for (int i = 0; i < COLS; i++)
    {
        for (int j = 0; j < ROWS; j++)
        {
            grid[i][j].vertex = vertexCount++;
            grid[i][j].x = i;
            grid[i][j].y = j;
            grid[i][j].IS_visited = false;
            grid[i][j].IS_containWall = false;
            grid[i][j].IS_dest = false;
            grid[i][j].IS_source = false;
            grid[i][j].IS_inPath = false;
            grid[i][j].neighbor = NULL;
        }
    }
    return grid;
}

inline void GRID_Free(cell_t (*grid)[ROWS])
{
    free(grid);
}

bool IS_wall(int x, int y, cell_t grid[COLS][ROWS])
{
    if (grid[x][y].IS_containWall)
    {
        return true;
    }
    return false;
}

inline int TAKE_source(cell_t grid[COLS][ROWS])
{
    int source;
    for (int i = 0; i < COLS; i++)
    {
        for (int j = 0; j < ROWS; j++)
        {
            if (grid[i][j].IS_source == true)
            {
                source = grid[i][j].vertex;
                break;
            }
        }
    }
    return source;
}

inline int TAKE_dest(cell_t grid[COLS][ROWS])
{
    int dest;
    for (int i = 0; i < COLS; i++)
    {
        for (int j = 0; j < ROWS; j++)
        {
            if (grid[i][j].IS_dest == true)
            {
                dest = grid[i][j].vertex;
                break;
            }
        }
    }
    return dest;
}