#include "GameUI.h"
#include "Constants.h"
#include "Factory.h"
#include <iostream>
GameUI::GameUI() {

};

void GameUI::render() {

    Factory* factory = Factory::getInstance();
    
    SDL_Renderer *renderer = factory -> getRenderer();

    for(auto const& object: uiObjects) 
    {
        SDL_RenderCopy(renderer, object.texture, NULL, &object.position );
    }

    SDL_Rect msgPosition = { 800, 500, 0, 0 };
    SDL_Texture* msgTexture = factory -> createTextBox(messages);
    SDL_QueryTexture(msgTexture, NULL, NULL, &msgPosition.w, &msgPosition.h);
    // std::cout << theTexture << std::endl;
    // memory leak
        SDL_RenderCopy(renderer, msgTexture, NULL, &msgPosition );
    // Render messages
   // create -> fromAtlasToTextbox(renderer, messages, FontAtlas *fontAtlas);



    // int no_of_messages = messages.size;


    // for(auto const& message: messages) {
    //     SDL_RenderCopy(renderer, object.texture, NULL, &object.position );
    // }

};

void GameUI::addButton(SDL_Texture *texture, int x, int y, int size_x, int size_y) {
    UIObject temp;
    temp.texture = texture;
    temp.position = { x, y, size_x, size_y };
    uiObjects.push_back(temp);

};

void GameUI::clickedButton(SDL_Point &mouse) {

}

void GameUI::addMessage(const std::string message) {
    messages.push_back(message);
    if(messages.size() > Constants::MAX_NO_OF_MESSAGES) messages.pop_front();
}

// void GameUI::createInfoScreen() {
//     // SDL_Rect info = { 800, 400, 100, 200 };
//     // UIObject temp;
//     // temp.texture = nullptr;
//     // temp.position = info;
//     // uiObjects.push_back(temp);
//     // infoScreen = 
// }
// void GameUI::updateInfo(std::string message) {


// }

