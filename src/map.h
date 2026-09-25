#ifndef MAP_H
#define MAP_H

#define HEIGHT 12
#define WIDTH 12
#define MHIEGHT 7
#define MWIDTH 14

void drawMap(char map[][WIDTH], int playerX, int playerY, int enemyX, int enemyY);
void loadMap(char map[][WIDTH], int mapNumber);
void fightMenu(char fmenu[][MWIDTH], int *playerX, int *playerY, int enemyX, int enemyY);
void drawMenu(char fmenu[][MWIDTH], char options1[], char options2[], int *t, int *t2, int *hph, int *hpe);

#endif
