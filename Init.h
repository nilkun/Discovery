#include "Constants.h"

static class Init {
private:

public:
  SDL_Renderer *renderer = nullptr; // Pointer to renderer
  SDL_Texture *infoText = nullptr; // Used for "press any key..."
  SDL_Texture* logoText = nullptr;
  SDL_Texture *mousePointer = nullptr;
  SDL_Rect mousePosition = { 0, 0, 5, 5 };
  FontAtlas bitfont; // For the 8-bit font
  int logoSizeX = 5 * 7 * 20;
  int logoSizeY = 5 * 9;
  SDL_Rect logo = { (Constants::SCREENWIDTH - logoSizeX)/2, 350, logoSizeX, logoSizeY };

}