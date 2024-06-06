#include "GRAPH_GEN.h"

graph_t *GEN_GRAPH_Create(const cell_t **grid)
{

    graph_t *p_graph = GRAPH_Create(grid);

    bool EDGE_Added[COLS][ROWS];
    for (int i = 0; i < COLS; i++)
    {
        for (int j = 0; j < ROWS; j++)
        {
            EDGE_Added[i][j] = false;
        }
    }

    for (int i = 0; i < COLS; i++)
    {
        for (int j = 0; j < ROWS; j++)
        {
            int currentVertex = grid[i][j].vertex;
            EDGE_Added[i][j] = true;
            // Add edges to the adjacent vertices

            if(!IS_wall(i, j, grid)) {
                if (i > 0 && !IS_wall(i - 1, j, grid) && EDGE_Added[i - 1][j] == false)
                {
                    int topVertex = grid[i - 1][j].vertex;
                    EDGE_Add(p_graph, currentVertex, topVertex, 1);
                }
                if (i < COLS - 1 && !IS_wall(i + 1, j, grid) && EDGE_Added[i + 1][j] == false)
                {
                    int bottomVertex = grid[i + 1][j].vertex;
                    EDGE_Add(p_graph, currentVertex, bottomVertex, 1);
                }
                if (j > 0 && !IS_wall(i, j - 1, grid) && EDGE_Added[i][j - 1] == false)
                {
                    int leftVertex = grid[i][j - 1].vertex;
                    EDGE_Add(p_graph, currentVertex, leftVertex, 1);
                }
                if (j < ROWS - 1 && !IS_wall(i, j + 1, grid) && EDGE_Added[i][j + 1] == false)
                {
                    int rightVertex = grid[i][j + 1].vertex;
                    EDGE_Add(p_graph, currentVertex, rightVertex, 1);
                }
            }
        }
    }

    return p_graph;
}