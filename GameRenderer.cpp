#include "GameRenderer.h"
#include "Constants.h"

GameRenderer::GameRenderer() : 
    renderer(nullptr)
{

}
GameRenderer::GameRenderer(SDL_Renderer *renderer): renderer(renderer)
{

}
GameRenderer::~GameRenderer()
{
    if(renderer) delete renderer;
    // delete bitfont;
}
void GameRenderer::grid(int* grid) {

    int x_length = Constants::GRID_X * Constants::TILESIZE;
    int y_length = Constants::GRID_Y * Constants::TILESIZE;

    int x_offset = Constants::X_OFFSET;
    int y_offset = Constants::Y_OFFSET;
    
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    for(int i = 0; i < Constants::GRID_X; i++) {
        SDL_RenderDrawLine(renderer, x_offset, grid[i] + y_offset, x_length + x_offset, grid[i] + y_offset);
    };
        for(int i = Constants::GRID_X; i < Constants::GRID_X+Constants::GRID_Y; i++) {
        SDL_RenderDrawLine(renderer, grid[i] + x_offset, y_offset, grid[i] + x_offset, y_length + y_offset);
    };

    // Draw border
    SDL_RenderDrawLine(renderer, x_length + x_offset, y_offset, x_length + x_offset, y_length + y_offset);
    SDL_RenderDrawLine(renderer, x_offset, y_length + y_offset, x_length + x_offset, y_length + y_offset);
}

void GameRenderer::draw() {
    SDL_SetRenderDrawColor(renderer, 255, 128, 0, 0);
    SDL_RenderPresent(renderer);
}

void GameRenderer::clear() {
    SDL_RenderClear(renderer);
}

//Set end to size of tile * no of tiles!
// create outer frame
// SDL_quit