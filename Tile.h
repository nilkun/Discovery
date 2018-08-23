#ifndef TILE_H_
#define TILE_H_

struct Tile {
public:
    int x;
    int y;
    Tile();
    Tile(int x, int y);
    ~Tile();

public:
    // properties of the tile;
    bool isVisible;
    unsigned char type;
};

#endif