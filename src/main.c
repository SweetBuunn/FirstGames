#include <stdio.h>
#include <stdlib.h>

#include "map.h"
#include "player.h"

int main(void)
{
    //--initial coordinates--
    int playerX = 3, playerY = 1;
    int running = 1, running2 = 0, currentMap = 1, trigger = 0;
    int enemyX = 5, enemyY = 5;
    int *t = 0, *t2 = 0;
    int *hpe = 100, *hph = 100;
    char options1[] = {"Attack"};
    char options2[] = {"Mercy"};
    char map[HEIGHT][WIDTH];
    char fmenu[MHIEGHT][MWIDTH];

    while (running)
    {
        system("clear");

        loadMap(map, currentMap);

        printf("Exit: q/Q\n");

        drawMap(map, playerX, playerY, enemyX, enemyY);

        char input = getchar();

        if (input == 'q' || input == 'Q')
        {
            running = 0;
            continue;
        }

        movePlayer(input, map, &playerX, &playerY);

        isDoor(playerX, playerY, currentMap, &trigger);

        changeMap(&currentMap, &playerX, &playerY, &trigger);

        if (playerX == enemyX && playerY == enemyY)
        {
            running--;
            running2++;
        }
    }
    while (running2)
    {
        system("clear");

        fightMenu(fmenu, &playerX, &playerY, enemyX, enemyY);
        drawMenu(fmenu, options1, options2, &t, &t2, &hph, &hpe);

        char input = getchar();
        controlMenu(input, &t, &t2);

        if (t == 1)
        {
            char input = getchar();
        }

        if (input == 'q' || input == 'Q')
        {
            running2 = 0;
            continue;
        }
    }
    printf("coordinate player: x: %d, y: %d\ncurrentMap: %d\ntrigger: %d\n", playerX, playerY, currentMap, trigger); // player coordinate.
}
