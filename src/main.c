#include <stdio.h>
#include <stdlib.h>

#include "map.h"
#include "player.h"

int main(void)
{
    //--initial coordinates--
    int playerX = 3, playerY = 1;
    int running = 1;
    int doorX = 5, doorY = 11;
    while (running)
    {
        system("clear");

        char (*map)[WIGHT];

        loadMap(map);

        printf("Exit: q/Q\n");

        drawMap(map, playerX, playerY, doorX, doorY);

        char input = getchar();

        if (input == 'q' || input == 'Q')
        {
            running = 0;
            continue;
        }

        movePlayer(input, map, &playerX, &playerY);

        if (playerX == doorX && playerY == doorY) // change map
        {
        }
    }

    printf("coordinate player: x: %d, y: %d\n", playerX, playerY); // player coordinate.
    printf("door: x:%d y:%d\n", doorX, doorY);                     // door coordinate.
}
