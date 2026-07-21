#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "map.h"

int main(void)
{

    int playerX = 2, playerY = 3; // spawn point.
    int running = 1;

    while (running)
    {
        system("clear");

        printf("Exit: q/Q\n");

        for (int x = 0; x < SIZE; x++) // print player, map, etc.
        {
            for (int y = 0; y < SIZE; y++)
            {
                if (x == playerX && y == playerY)
                    printf("@ ");
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
            if (map[playerX][playerY] != '#') // check to obstacle.
            {
                playerX++;
                playerX--;
                break;
            }
            playerX++;
            break;
        case 'S':
        case 's':
            playerX++;
            if (map[playerX][playerY] != '#') // check to obstacle.
            {
                playerX--;
                playerX++;
                break;
            }
            playerX--;
            break;
        case 'A':
        case 'a':
            playerY--;
            if (map[playerX][playerY] != '#') // check to obstacle.
            {
                playerY++;
                playerY--;
                break;
            }
            playerY++;
            break;
        case 'D':
        case 'd':
            playerY++;
            if (map[playerX][playerY] != '#') // check to obstacle.
            {
                playerY--;
                playerY++;
                break;
            }
            playerY--;
            break;
        case 'Q':
        case 'q':
            running = 0;
            break;
        }
    }
    printf("coordinate: x: %d, y: %d\n", playerX, playerY); // player coordinate.
}
