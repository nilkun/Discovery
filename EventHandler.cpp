#include "EventHandler.h"

EventHandler::EventHandler() {  };

void EventHandler::poll(Unit *unit, GameUI *ui, Game *game)
{
  while(SDL_PollEvent(&event)) 
  {
    switch (event.type) 
    {
      case SDL_QUIT: 
      {
        exit(1);
      }

      case SDL_MOUSEBUTTONDOWN:
        switch (event.button.button)
        {
          case SDL_BUTTON_LEFT:
          {
            SDL_GetMouseState(&mouse.x, &mouse.y);
            unit -> moved(mouse);

          }
          case SDL_BUTTON_RIGHT:
          {
             SDL_GetMouseState(&mouse.x, &mouse.y);
             unit -> moved(mouse);
          }
        }

      case SDL_KEYDOWN:
        switch(event.key.keysym.sym)
        {
          case SDLK_ESCAPE:
          {
            exit(1);
          }
          case SDLK_UP:
          {
            unit -> moveUp();
            ui -> addMessage("Moved up...");
            break;
          }
          case SDLK_DOWN:
          {
            unit -> moveDown();
            ui -> addMessage("Moved down...");
            break;
          }
          case SDLK_LEFT:
          {
            unit -> moveLeft();
            ui -> addMessage("Moved left...");
            break;
          }
          case SDLK_RIGHT:
          {
            unit -> moveRight();
            ui -> addMessage("Moved right...");
            break;
          }
          case SDLK_b:
          {
            ui -> addMessage("Making camp...");
            break;
          }
          case SDLK_e:
          {
            game -> endturn();
            break;
          } 
        }
    }
  }
}



