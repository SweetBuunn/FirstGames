#ifndef PLAYER_H
#define PLAYER_H
#include "map.h"

void movePlayer(char input, char map[][WIDTH], int *playerX, int *playerY);
void changeMap(int *currentMap, int *playerX, int *playerY, int *trigger);
void isDoor(int playerX, int playerY, int currentMap, int *trigger);
void controlMenu(int input, int *t, int *t2);

#endif