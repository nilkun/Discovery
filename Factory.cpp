#include <SDL2/SDL_image.h>
#include "Factory.h"

void Factory::init() { 
  font = create8bitAtlas(); 
};      

SDL_Texture* Factory::createTextBox(std::deque<std::string> messages)
{
  // ERROR CHECKING
  if(!renderer) std::cout << "Error with renderer in AtlasToTextbox";
  // if(!font) std::cout << "Error with fontAtlas in AtlasToTextbox";
  // Initialize temporary variables and textures
  SDL_Texture* processing;
  SDL_Texture* temp;
  SDL_Rect letterPosition = { 0, 0, 0, font.fontMap[33].h };
  int textureWidth = 100;
  int padding = 2;
  int textureHeight = messages.size() * letterPosition.h + (messages.size() - 1) * padding;
  int nextLine = letterPosition.h + padding;
  int maxWidth = 0;

  // Set the color of the font
  // SDL_SetTextureColorMod(font.texture, color.r, color.g, color.b);
  SDL_SetTextureColorMod(font.texture, 255, 0, 0);
  // Instantiation
  processing = SDL_CreateTexture(renderer,
    SDL_PIXELFORMAT_RGBA8888,
    SDL_TEXTUREACCESS_TARGET,
    textureWidth,
    textureHeight);
  SDL_SetRenderTarget(renderer, processing);
  for(auto text : messages) {
    for(char& c : text) {
      letterPosition.w = font.fontMap[(int) c].w;
      if((letterPosition.w + letterPosition.x) > maxWidth) maxWidth = letterPosition.w + letterPosition.x;
      // Resize if necessary
      if(textureWidth < letterPosition.w+letterPosition.x) // While oob
      {
        SDL_Rect targetTexture = { 0, 0, textureWidth, textureHeight }; // target location of temp texture
        while(textureWidth < letterPosition.w+letterPosition.x) textureWidth *= 2; // In the unlikely case that the letters are bigger than the texture!
        temp = processing;
        processing = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, textureWidth, textureHeight);
        SDL_SetRenderTarget(renderer, processing);
        SDL_RenderCopy(renderer, temp, NULL, &targetTexture);
        SDL_DestroyTexture(temp);
      }
      SDL_RenderCopy(renderer, font.texture, &font.fontMap[(int) c], &letterPosition);
      // std::cout << "Processing '" << text << std::endl;
      letterPosition.x += letterPosition.w;
    }
    letterPosition.y += nextLine;
    letterPosition.x = 0;
  }
  SDL_Texture* returnTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, maxWidth, textureHeight);
  SDL_SetRenderTarget(renderer, returnTexture);
  // Recycle letterPosition for placing in texture
  letterPosition = { 0, 0, maxWidth, textureHeight };
  SDL_RenderCopy(renderer, processing, &letterPosition, &letterPosition);
  SDL_DestroyTexture(processing);
  SDL_SetRenderTarget(renderer, NULL);
  return returnTexture;
}

Font Factory::create8bitAtlas()
{
  Font bitfont;
  bitfont.texture = fromImage("resources/alphabet.png");
  SDL_Rect destination = { 0, 0, 7, 9 };
  for(int i = 32; i <= 128; i++) {
    /* set location data in atlas */
    bitfont.fontMap[i] = destination;
    destination.x += 6;
  }
  return bitfont;
}

void Factory::setRenderer(SDL_Renderer *r) 
{
    renderer = r;
}
SDL_Renderer* Factory::getRenderer() {
    return renderer;
}

SDL_Texture* Factory::fromImage(const char* imageLocation)
{
  SDL_Texture *texture = nullptr;
  SDL_Surface* loadImage = IMG_Load(imageLocation);
  if( loadImage == NULL )
  {
      std::cout << "Unable to load file. (@ getTexture.loadImage)"<< std::endl;
  }

  texture = SDL_CreateTextureFromSurface(renderer, loadImage);
  if(texture == NULL)
  {
      std::cout << "Unable to load file. (@ getTexture.texture) REASON:" << SDL_GetError() << std::endl;
  }

  // Clean up
  SDL_FreeSurface(loadImage);
  return texture;
}

