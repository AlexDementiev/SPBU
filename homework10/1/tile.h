#pragma once

struct Tile;

Tile *newTile(bool isFree, int i, int j);
void deleteTile(Tile *tile);

void setVisited(Tile *tile);
void setPrevios(Tile *tile, Tile *previous);
void setInPath(Tile *tile);
void setPriority(Tile *tile, int priority);
void setDistance(Tile *tile, int distance);

bool isVisited(Tile *tile);
bool isInPath(Tile *tile);
bool isFree(Tile *tile);
int priority(Tile *tile);
int distance(Tile *tile);
int tileX(Tile *tile);
int tileY(Tile *tile);
Tile *previous(Tile *tile);
