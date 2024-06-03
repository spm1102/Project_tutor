#include"gui.h"

int main() {
    cell_t** grid = GRID_Create();

    GUI_INIT(grid);
    GRID_Free(grid);

    return 0;
}




