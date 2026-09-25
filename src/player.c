#include "player.h"
#include "map.h"

void movePlayer(char input, char map[][WIDTH], int *playerX, int *playerY)
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

void changeMap(int *currentMap, int *playerX, int *playerY, int *trigger)
{
    if (*trigger != 1)
        return;

    if (*currentMap == 1 && *playerX == 5 && *playerY == 11)
    {
        *currentMap = 2;
        *playerX = 5;
        *playerY = 0;
        *trigger = 0;
    }
    else if (*currentMap == 2 && *playerX == 5 && *playerY == 0)
    {
        *currentMap = 1;
        *playerX = 5;
        *playerY = 11;
        *trigger = 0;
    }
    else if (*currentMap == 1 && *playerX == 0 && *playerY == 5)
    {
        *currentMap = 3;
        *playerX = 11;
        *playerY = 5;
        *trigger = 0;
    }
    else if (*currentMap == 3 && *playerX == 11 && *playerY == 5)
    {
        *currentMap = 1;
        *playerX = 0;
        *playerY = 5;
        *trigger = 0;
    }
    else if (*currentMap == 1 && *playerX == 11 && *playerY == 5)
    {
        *currentMap = 4;
        *playerX = 0;
        *playerY = 5;
        *trigger = 0;
    }
    else if (*currentMap == 4 && *playerX == 0 && *playerY == 5)
    {
        *currentMap = 1;
        *playerX = 11;
        *playerY = 5;
        *trigger = 0;
    }
}

void isDoor(int playerX, int playerY, int currentMap, int *trigger)
{
    if (currentMap == 1)
    {
        if (playerX == 5 && playerY == 10)
            *trigger = 1;

        else if (playerX == 1 && playerY == 5)
            *trigger = 1;

        else if (playerX == 10 && playerY == 5)
            *trigger = 1;
    }

    else if (currentMap == 2)
    {
        if (playerX == 5 && playerY == 1)
            *trigger = 1;
    }

    else if (currentMap == 3)
    {
        if (playerX == 10 && playerY == 5)
            *trigger = 1;
    }

    else if (currentMap == 4)
    {
        if (playerX == 1 && playerY == 5)
            *trigger = 1;
    }
}

void controlMenu(int input, int *t, int *t2)
{
    switch (input)
    {
    case 'W':
    case 'w':
        *t = 1;
        *t2 = 0;
        break;
    case 'S':
    case 's':
        *t2 = 1;
        *t = 0;
        break;
    }
}
