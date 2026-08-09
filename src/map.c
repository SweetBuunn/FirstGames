#include <stdio.h>
#include <stdlib.h>

#include "map.h"

void loadMap(char map[][WIGHT])
{
    int nmap = 1;

    FILE *fmap = fopen("Map/map1.txt", "r");
    if (nmap == 1)
    {
    }
    if (fmap == NULL)
    {
        perror("fopen");
        return;
    }

    for (int i = 0; i < HIGHT; i++)
    {
        fread(map[i], sizeof(char), WIGHT, fmap);
        fgetc(fmap);
    }

    fclose(fmap);
}

drawMap(char map[][WIGHT], int playerX, int playerY, int doorX, int doorY)
{
    for (int x = 0; x < HIGHT; x++) // print player, map, etc.
    {
        for (int y = 0; y < WIGHT; y++)
        {
            if (x == playerX && y == playerY)
            {
                printf("@ ");
            }
            else if (x == doorX && y == doorY)
                printf("| ");
            else
                printf("%c ", map[x][y]);
        }
        putchar('\n');
    }
}