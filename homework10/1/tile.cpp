#include "tile.h"


int const infinity = 1000000000;

struct Tile
{
    bool isFree;
    bool isVisited;
    bool isInPath;

    int priority;
    int distance;
    int x;
    int y;

    Tile *previous;
};

Tile *createTile(bool isFree, int x, int y)
{
    Tile *newTile = new Tile;
    newTile->isFree = isFree;
    newTile->isInPath = false;
    newTile->isVisited = false;
    newTile->distance = infinity;
    newTile->priority = infinity;
    newTile->x = x;
    newTile->y = y;
    newTile->previous = nullptr;

    return newTile;
}

void deleteTile(Tile *tile)
{
    delete tile;
}

void setVisited(Tile *tile)
{
    tile->isVisited = true;
}

void setInPath(Tile *tile)
{
    tile->isInPath = true;
}

void setPrevious(Tile *tile, Tile *previous)
{
    tile->previous = previous;
}

void setDistance(Tile *tile, int distance)
{
    tile->distance = distance;
}

void setPriority(Tile *tile, int priority)
{
    tile->priority = priority;
}

bool isFree(Tile *tile)
{
    return tile->isFree;
}

bool isVisited(Tile *tile)
{
    return tile->isVisited;
}

bool isInPath(Tile *tile)
{
    return tile->isInPath;
}

int priority(Tile *tile)
{
    return tile->priority;
}

int distance(Tile *tile)
{
    return tile->distance;
}

int getX(Tile *tile)
{
    return tile->x;
}

int getY(Tile *tile)
{
    return tile->y;
}

Tile *previous(Tile *tile)
{
    return tile->previous;
}
