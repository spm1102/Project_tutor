#include"gui.h"

int main() {
    SetTargetFPS(120);
    cell_t** grid = GRID_Create();

    GUI_INIT(grid);
    GRID_Free(grid);

    return 0;
}




