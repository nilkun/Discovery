#include "Units.h"
#include "Constants.h"
#include "Factory.h"

Unit::Unit(): x_loc(5), y_loc(5), type(EXPLORER), movesLeft(10) {}

void Unit::render(SDL_Renderer *renderer) {

    int x_render = Constants::X_OFFSET + Constants::TILESIZE * (x_loc);
    int y_render = Constants::Y_OFFSET + Constants::TILESIZE * (y_loc);
    SDL_Rect position = {x_render, y_render, Constants::TILESIZE, Constants::TILESIZE };

    SDL_RenderCopy(renderer, texture, NULL, &position );
}

void Unit::setTexture(SDL_Texture* t)
{
  texture = t;
}

void Unit::moveUp() {
    y_loc--;
    if(y_loc < 0) y_loc = 0;   
}
void Unit::moveDown() {
    y_loc++; 
    if(y_loc >= Constants::GRID_Y) y_loc = Constants::GRID_Y - 1;
}
void Unit::moveLeft() {
    x_loc--;
    if(x_loc < 0) x_loc = 0;
}
void Unit::moveRight() {
    x_loc++;
    if(x_loc >= Constants::GRID_X) x_loc = Constants::GRID_X - 1;
}

void Unit::moved(SDL_Point &mouse) {
    int size = Constants::TILESIZE;
    int x_bottom = Constants::X_OFFSET + Constants::TILESIZE * (x_loc);
    int y_top = Constants::Y_OFFSET + Constants::TILESIZE * (y_loc);
    int x_top = size + Constants::X_OFFSET + Constants::TILESIZE * (x_loc);
    int y_bottom = size + Constants::Y_OFFSET + Constants::TILESIZE * (y_loc);

    if(mouse.x > (x_bottom - size) && mouse.y > ((y_top) - size) && (mouse.x < (x_top + size)) && (mouse.y < (y_bottom) + size)) // If it is in the box 3x3
    {
        if(mouse.x < x_bottom) x_loc--;
        else if(mouse.x > x_top) x_loc++;

        if(mouse.y > y_bottom) y_loc++;
        else if(mouse.y < y_top) y_loc--;
    }
}