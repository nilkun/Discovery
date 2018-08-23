#ifndef GRID_H_
#define GRID_H_
#include "Tile.h"

class Grid {
public:
    const int x_size;
    const int y_size;
    Grid(int x, int y);
    ~Grid();
    Tile *map;
    void show();
    int *createGrid();
};

#endif