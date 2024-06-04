#ifndef GUI_H
#define GUI_H

#include <time.h>
#include "a_star.h"
#include "raylib.h"
#include "raygui.h"

#define MAX_PATH_LENGTH 100
#define TIME_DELAY_MILISECONDS 1

void CELL_Draw(cell_t cell);
bool INDEX_IsValid(int x, int y);
void delay(int numberOfSeconds);
void GUI_displayError(void);
void GUI_displayPath(graph_t *p_graph);
void GUI_findShortestPath(cell_t** grid);
void GUI_INIT(cell_t** grid);

#endif