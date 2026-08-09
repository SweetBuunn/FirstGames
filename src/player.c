#include "player.h"
#include "map.h"

void movePlayer(char input, char map[][WIGHT], int *playerX, int *playerY)
{
    int newX = *playerX;
    int newY = *playerY;
    switch (input) // movement.
    {
    case 'W':
    case 'w':
        newX--;
        break;
    case 'S':
    case 's':
        newX++;
        break;
    case 'A':
    case 'a':
        newY--;
        break;
    case 'D':
    case 'd':
        newY++;
        break;
    }
    if (map[newX][newY] != '#')
    {
        *playerX = newX;
        *playerY = newY;
    }
}