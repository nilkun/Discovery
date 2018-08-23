#ifndef GAMEUI_H_
#define GAMEUI_H_
#include <SDL2/SDL.h>
#include <vector>
#include <string>
#include <deque>

#include "../gameEngine/creatorTools/CreatorTools.h"

class GameUI {
public:
    struct UIObject {
        SDL_Rect position;
        SDL_Texture *texture;
    };

    std::vector<UIObject> uiObjects;
    // uiObjects *infoScreen;
    std::deque<std::string> messages;

    GameUI();
    void render();
    void addButton(SDL_Texture *texture, int x, int y, int size_x, int size_y);
    void clickedButton(SDL_Point &mouse);
    // void createInfoScreen();
    void addMessage(const std::string message);
};

#endif