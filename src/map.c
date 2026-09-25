#include <stdio.h>
#include <stdlib.h>

#include "map.h"

void loadMap(char map[][WIDTH], int mapNumber)
{
    char filename[45];
    snprintf(filename, sizeof(filename), "maps/map%d.txt", mapNumber);

    FILE *fmap = fopen(filename, "r");
    if (fmap == NULL)
    {
        perror("fopen");
        return;
    }

    for (int x = 0; x < HEIGHT; x++)
    {
        for (int y = 0; y < WIDTH; y++)
        {
            map[x][y] = fgetc(fmap);
        }
        fgetc(fmap);
    }

    fclose(fmap);
}

void drawMap(char map[][WIDTH], int playerX, int playerY, int enemyX, int enemyY)
{
    for (int x = 0; x < HEIGHT; x++) // print player, map, etc.
    {
        for (int y = 0; y < WIDTH; y++)
        {
            if (x == playerX && y == playerY)
                printf("@ ");
            else if (x == enemyX && y == enemyY)
                printf("& ");
            else
                printf("%c ", map[x][y]);
        }
        putchar('\n');
    }
}

void fightMenu(char fmenu[][MWIDTH], int *playerX, int *playerY, int enemyX, int enemyY)
{

    FILE *menu = fopen("Menu/menuP2.txt", "r");
    if (menu == NULL)
    {
        perror("fopen");
        return;
    }

    for (int x = 0; x < MHIEGHT; x++)
    {
        for (int y = 0; y < MWIDTH; y++)
        {
            fmenu[x][y] = fgetc(menu);
        }
        fgetc(menu);
    }

    fclose(menu);
}

void drawMenu(char fmenu[][MWIDTH], char options1[], char options2[], int *t, int *t2, int *hph, int *hpe)
{
    if (*t == 1)
        options1 = ">Attack";
    else if (*t2 == 1)
        options2 = ">Mercy";
    for (int x = 0; x < MHIEGHT; x++)
    {
        for (int y = 0; y < MWIDTH; y++)
        {
            if (x == 2 && y == 2)
                printf("%d", *hph);
            else if (x == 2 && y == 8)
            {
                printf("%d", *hpe);
                y = 9;
            }
            else if (x == 4 && y == 4)
            {
                printf("%s", options1);
                y = 6;
            }
            else if (x == 5 && y == 4)
            {
                printf("%s ", options2);
                y = 6;
            }
            else
                printf("%c ", fmenu[x][y]);
        }
        putchar('\n');
    }
}