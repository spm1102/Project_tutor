#define RAYGUI_IMPLEMENTATION
#include "gui.h"

void CELL_Draw(cell_t cell)
{
    if (cell.IS_containWall)
    {
        DrawRectangle(cell.x * cellWidth, cell.y * cellHeight, cellWidth, cellHeight, YELLOW);
    }
    else if (cell.IS_source)
    {
        DrawRectangle(cell.x * cellWidth, cell.y * cellHeight, cellWidth, cellHeight, RED);
    }
    else if (cell.IS_dest)
    {
        DrawRectangle(cell.x * cellWidth, cell.y * cellHeight, cellWidth, cellHeight, BLUE);
    }

    DrawRectangleLines(cell.x * cellWidth, cell.y * cellHeight, cellWidth, cellHeight, BLACK);
}

bool INDEX_IsValid(int x, int y)
{
    return x >= 0 && x < COLS && y >= 0 && y < ROWS;
}

// void delay(int numberOfSeconds) {
//     int milliSeconds = 1000 * numberOfSeconds;
//     clock_t start_time = clock();
//     while (clock() < start_time + milliSeconds)
//         ;
// }

void GUI_displayError(void)
{
    BeginDrawing();
    DrawRectangleRec((Rectangle){195, 195, 20, 20}, GRAY);
    DrawText("Find no path", 195, 195, 14, BLACK);
    EndDrawing();
}

void GUI_displayPath(graph_t *p_graph, cell_t** grid)
{
    for (int i = 0; i < COLS; i++)
    {
        for (int j = 0; j < ROWS; j++)
        {
            if (p_graph->vertices[COLS * i + j].visited == true && grid[i][j].IS_source == false)
            {
                BeginDrawing();
                DrawRectangle(i * cellWidth, j * cellHeight, cellWidth, cellHeight, GREEN);
                DrawRectangleLines(i * cellWidth, j * cellHeight, cellWidth, cellHeight, BLACK);
                EndDrawing();
            }
        }
    }

    BeginDrawing();
}

void GUI_findShortestPath(cell_t **grid)
{
    graph_t *p_graph = GEN_GRAPH_Create((const cell_t **)grid);
    int source = TAKE_source((const cell_t **)grid);
    int dest = TAKE_dest((const cell_t **)grid);
    a_star_queue(p_graph, grid, source, dest, &GUI_displayPath);
    int currentVertex = dest;
    while (currentVertex != source)
    {
        if (p_graph->vertices[currentVertex].preVertex == -1)
        {
            GUI_displayError();
            break;
        }
        currentVertex = p_graph->vertices[currentVertex].preVertex;
        int j = currentVertex % 10;
        int i = (currentVertex - j) / 10;
        grid[i][j].IS_inPath = true;
    }
    GRAPH_Free(p_graph);
}

void GUI_INIT(cell_t **grid)
{
    InitWindow(screenWidth, screenHeight, "Algorithm");

    bool isDrawingWalls = false;
    bool hasSource = false;
    bool hasDest = false;
    int sourceX = -1;
    int sourceY = -1;
    int destX = -1;
    int destY = -1;

    bool isAlgorithmRunning = false;

    while (!WindowShouldClose())
    {
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            isDrawingWalls = true;
        }
        else if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
        {
            isDrawingWalls = false;
        }

        if (isDrawingWalls)
        {
            Vector2 mPos = GetMousePosition();
            int inX = (int)mPos.x / cellWidth;
            int inY = (int)mPos.y / cellHeight;
            Rectangle bound;
            bound.x = (float)(grid[inX][inY].x * cellWidth);
            bound.y = (float)(grid[inX][inY].y * cellHeight);
            bound.width = (float)cellWidth;
            bound.height = (float)cellHeight;
            if (INDEX_IsValid(inX, inY) && CheckCollisionPointRec(mPos, bound))
            {
                grid[inX][inY].IS_containWall = true;
            }
        }
        else if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
        {
            Vector2 mPos2 = GetMousePosition();
            int inX = (int)mPos2.x / cellWidth;
            int inY = (int)mPos2.y / cellHeight;

            if (INDEX_IsValid(inX, inY))
            {
                if (!hasSource)
                {
                    hasSource = true;
                    sourceX = inX;
                    sourceY = inY;
                    grid[inX][inY].IS_source = true;
                }
                else if (!hasDest)
                {
                    hasDest = true;
                    destX = inX;
                    destY = inY;
                    grid[inX][inY].IS_dest = true;
                }
                else
                {
                    // Clear previous source and destination
                    grid[sourceX][sourceY].IS_source = false;
                    grid[destX][destY].IS_dest = false;
                    hasSource = false;
                    hasDest = false;
                }
            }
        }

        BeginDrawing();

        ClearBackground(RAYWHITE);

        // GuiToggleGroup((Rectangle){0, 0 , cellWidth, cellHeight}, "BFS; Dijkstra; A Star", &ToggleGroup001Active);

        for (int i = 0; i < COLS; i++)
        {
            for (int j = 0; j < ROWS; j++)
            {
                CELL_Draw(grid[i][j]);
            }
        }

        if (IsKeyPressed(KEY_ENTER) && sourceX != -1 && sourceY != -1 && destX != -1 && destY != -1)
        {
            isAlgorithmRunning = true;
            GUI_findShortestPath(grid);
        }

        if (isAlgorithmRunning)
        {
            // isAlgorithmRunning = false;
            for (int i = 0; i < COLS; i++)
            {
                for (int j = 0; j < ROWS; j++)
                {
                    if (grid[i][j].IS_inPath)
                    {
                        // delay(TIME_DELAY_MILISECONDS);
                        DrawRectangle(i * cellWidth, j * cellHeight, cellWidth, cellHeight, GRAY);
                        DrawRectangleLines(i * cellWidth, j * cellHeight, cellWidth, cellHeight, BLACK);
                    }
                }
            }
        }
        EndDrawing();
    }

    CloseWindow();
}