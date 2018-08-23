#include "Grid.h"
#include "Constants.h"
#include <SDL2/SDL.h>

Grid::Grid(int x, int y): x_size(x), y_size(y) {
    map = new Tile[x*y];

}

Grid::~Grid() {

}

// void Grid::show() {
//     for(int i = 0; i < x_size; i++){
//         SDL_RenderDrawLine(renderer, i*TILESIZE, 0, i*TILESIZE, 768)
//     };

//     for(int i = 0; i = y_size; i++) {
//         SDL_RenderDrawLine(renderer, 0, i*TILESIZE, 1024, i*TILESIZE)
    
//     };
// }

// void Grid::createGrid() {
    
//     int x_grid[x_size];
//     int y_grid[y_size];

//     for(int i = 0; i < x_size; i++){
//         x_grid[i] = i*TILESIZE;
//     };

//     for(int i = 0; i = y_size; i++) {
//         y_grid[i] = i*TILESIZE;
    
//     };

// }

int *Grid::createGrid() {
    
    int *grid = new int[x_size+y_size];
    // int y_grid[y_size];

    for(int i = 0; i < x_size; i++){
        grid[i] = i*Constants::TILESIZE;
    };

    for(int i = 0; i < y_size; i++) {
        grid[x_size+i] = i*Constants::TILESIZE;
    
    };
    return grid;
}