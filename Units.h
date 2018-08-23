#ifndef UNITS_H_
#define UNITS_H_

#include <SDL2/SDL.h>

// #include "UnitTypes.h"

/* Currently there is only one type, the explorer */
enum UnitType { EXPLORER };

struct Unit {
    int x_loc;
    int y_loc;
    UnitType type;
    int movesLeft;
    SDL_Texture *texture;

    Unit();
    void render(SDL_Renderer *renderer);
    void setTexture(SDL_Texture* t);
    void moveUp(); 
    void moveDown();
    void moveLeft();
    void moveRight();
    void moved(SDL_Point &mouse);
};

#endif