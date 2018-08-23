#ifndef CONSTANTS_H_
#define CONSTANTS_H_

/*  All the constants in the game. Should probably not be compiled, but put in a  text file  */

namespace Constants {

    // Screen initialization
    const int SCREEN_WIDTH = 1024;
    const int SCREEN_HEIGHT = 768;

    // In order to put anything on the map, you need these variables

    // Pixel size of each individual tile
    const int TILESIZE = 16;

    // This is the actual map size in tiles    
    const int GRID_X = 40;
    const int GRID_Y = 40;

    // offset for map
    const int X_OFFSET = 20;
    const int Y_OFFSET = 20;

    // Maximum info messages to display at once
    const int MAX_NO_OF_MESSAGES = 10;
}

#endif