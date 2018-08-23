#ifndef GAMERENDERER_H_
#define GAMERENDERER_H_

#include <SDL2/SDL.h>
#include "../gameEngine/creatorTools/CreatorTools.h"

class GameRenderer {
public:
    GameRenderer();
    GameRenderer(SDL_Renderer* renderer);
    ~GameRenderer();
    SDL_Renderer *renderer; // Pointer to renderer
    FontAtlas bitfont; // For the 8-bit font
    void draw(); // render to screen;
    void grid(int* grid);
    void clear();
};

#endif