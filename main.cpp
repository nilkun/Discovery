#include <SDL2/SDL.h>
#include "Constants.h"

// Game Engine
#include "../gameEngine/creatorTools/CreatorTools.h"

#include "../gameEngine/window/window.h"

// Game files
#include "GameRenderer.h"
#include "Grid.h"
#include "EventHandler.h"
#include "Units.h"
#include "GameUI.h"
#include "Factory.h"
#include "Game.h"

#include <string>

int main()
{
  EventHandler events;
  TextureCreator create;
  int *theGrid;


  Screen screen("Discovery!!! See the World", Constants::SCREEN_WIDTH, Constants::SCREEN_HEIGHT);
  GameRenderer renderer(screen.getRenderer());
  Grid grid(Constants::GRID_X, Constants::GRID_Y);

  Factory *factory = Factory::getInstance();

  factory -> setRenderer(renderer.renderer);
  factory -> init();

  Game *game = new Game();
  theGrid = grid.createGrid();

  // setup some unit
  Unit *explorer = new Unit();
  Unit *currentUnit = explorer;


  SDL_Texture *exptext = create.fromImage(renderer.renderer, "assets/explorer.png");

  explorer -> setTexture(exptext);

  FontAtlas bitfont;
  bitfont = create.create8bitAtlas(renderer.renderer);
  GameUI *gameUI = new GameUI();

  std::string build = "(B)uild";
  std::string endturn = "(E)ND TURN";
  std::string quit = "(Q)UIT GAME";
  // gameUI -> addButton(create.fromAtlasToText(renderer.renderer, hello, &bitfont), x, y, size_x, size_y);
  gameUI -> addButton(create.fromAtlasToText(renderer.renderer, build, &bitfont, { 0, 255, 0, 0 }), 800, 200, 50, 15);
  gameUI -> addButton(create.fromAtlasToText(renderer.renderer, endturn, &bitfont, { 0, 255, 0, 0 }), 800, 220, 100, 15);
  gameUI -> addButton(create.fromAtlasToText(renderer.renderer, quit, &bitfont, { 0, 255, 0, 0 }), 800, 240, 100, 15);
  // showMessage(renderer, "DEBUG WINDOW", &bitfont, 10, 10);
  while(true) {
    events.poll(currentUnit, gameUI, game);
    renderer.clear();
    renderer.grid(theGrid);
    explorer -> render(renderer.renderer);
    gameUI -> render();
    renderer.draw();
  }
  return 0;
}

// void showMessage(SDL_Renderer *renderer, std::string message, FontAtlas *bitfont, int yPos, int xPos) {
//   SDL_Texture *messageTexture = nullptr;
//   images.setColor(0, 0, 0, 255);
//   messageTexture = images.fromAtlasToText(renderer, message.c_str(), bitfont, isRed);

//   int texW = 0;
//   int texH = 0;
//   SDL_QueryTexture(messageTexture, NULL, NULL, &texW, &texH);
//   if(xPos == -1) xPos = (1024 - texW)/2; //centered
//   SDL_Rect messageLocation = { xPos, yPos, texW, texH };
// //  SDL_RenderSetViewport(renderer, NULL);
//   SDL_RenderCopy(renderer, messageTexture, NULL, &messageLocation);
//   SDL_DestroyTexture(messageTexture);
// }
