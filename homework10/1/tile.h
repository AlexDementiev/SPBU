#pragma once

struct Tile;

Tile *createTile(bool isFree, int x, int y);
void deleteTile(Tile *tile);

void setVisited(Tile *tile);
void setInPath(Tile *tile);
void setPrevious(Tile *tile, Tile *previous);
void setDistance(Tile *tile, int distance);
void setPriority(Tile *tile, int priority);

bool isFree(Tile *tile);
bool isVisited(Tile *tile);
bool isInPath(Tile *tile);

int priority(Tile *tile);
int distance(Tile *tile);
int getX(Tile *tile);
int getY(Tile *tile);

Tile *previous(Tile *tile);
