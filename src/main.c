#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "map.h"

int main(void)
{
    //--initial coordinates--
    int playerX = 3, playerY = 1;
    int running = 1;
    int doorX = 5, doorY = 11;
    int cmap = 1;
    while (running)
    {

        char (*map)[SIZE];

        if (cmap == 1) // chage map and coordinate door
        {
            map = nmap;
            doorX = 5;
            doorY = 11;
        }
        else if (cmap == 2)
        {
            map = nmap2;
            doorX = 5;
            doorY = 0;
        }

        system("clear");

        printf("Exit: q/Q\n");

        system("clear");
        for (int x = 0; x < SIZE; x++) // print player, map, etc.
        {
            for (int y = 0; y < SIZE; y++)
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

        char input;

        do
        {
            input = getchar();
        } while (input == '\n');

        switch (input) // movment.
        {
        case 'W':
        case 'w':
            playerX--;
            if (map[playerX][playerY] == '#')
            {
                playerX++;
                break;
            }
            break;
        case 'S':
        case 's':
            playerX++;
            if (map[playerX][playerY] == '#')
            {
                playerX--;
                break;
            }
            break;
        case 'A':
        case 'a':
            playerY--;
            if (map[playerX][playerY] == '#')
            {
                playerY++;
                break;
            }
            break;
        case 'D':
        case 'd':
            playerY++;
            if (map[playerX][playerY] == '#')
            {
                playerY--;
                break;
            }
            break;
        case 'Q':
        case 'q':
            running = 0;
            break;
        }

        if (playerX == doorX && playerY == doorY) // change map
        {
            if (cmap == 1)
                cmap = 2;
            else if (cmap == 2)
                cmap = 1;
        }
    }
    printf("coordinate player: x: %d, y: %d\n", playerX, playerY); // player coordinate.
    printf("door: x:%d y:%d\n", doorX, doorY);                     // door coordinate.
    printf("map:%d\n", cmap);                                      // number map.
}
