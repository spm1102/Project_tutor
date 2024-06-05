#include "cell.h"

const int screenWidth = 400;
const int screenHeight = 400;

const int cellWidth = screenWidth / COLS;
const int cellHeight = screenHeight / ROWS;

cell_t **GRID_Create(void)
{
    cell_t** grid = (cell_t **)malloc(ROWS * sizeof(cell_t *));
    for (int i = 0; i < ROWS; i++)
    {
        grid[i] = (cell_t *)malloc(COLS * sizeof(cell_t));
    }
    int vertexCount = 0;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
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

void GRID_Free(cell_t **grid)
{
    for (int i = 0; i < ROWS; i++)
    {
        free(grid[i]);
    }
    free(grid);
}

bool IS_wall(int x, int y, const cell_t** grid)
{
    if (grid[x][y].IS_containWall)
    {
        return true;
    }
    return false;
}

int TAKE_source(const cell_t** grid)
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

int TAKE_dest(const cell_t** grid)
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