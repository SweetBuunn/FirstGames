#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 12

int main(void)
{
    char map[SIZE][SIZE] = {
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
        {'#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
        {'#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
        {'#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
        {'#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
        {'#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
        {'#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
        {'#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
        {'#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
        {'#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
        {'#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
        {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    };

    int playerX = 2, playerY = SIZE / 2;
    bool running = true;

    char appleX = SIZE / 2, appleY = SIZE / 2;

    int score = 0;

    while (running)
    {

        system("clear");
        printf("Score:%d\n", score);

        for (int y = 0; y < SIZE; y++)
        {
            for (int x = 0; x < SIZE; x++)
            {
                if (x == playerX && y == playerY)
                    printf("@ ");
                else if (x == appleX && y == appleY)
                    printf("* ");
                else
                    printf("%c ", map[y][x]);
            }
            putchar('\n');
        }

        char input;
        do
        {
            input = getchar();
        } while (input == '\n');

        int newX = playerX;
        int newY = playerY;

        switch (input)
        {
        case 'w':
        case 'W':
            newY--;
            break;
        case 's':
        case 'S':
            newY++;
            break;
        case 'a':
        case 'A':
            newX--;
            break;
        case 'd':
        case 'D':
            newX++;
            break;
        case 'q':
        case 'Q':
            running = false;
            break;
        }

        if (map[newX][newY] != '#')
        {
            playerX = newX;
            playerY = newY;
        }
        if (playerX == appleX && playerY == appleY)
        {
            score++;
            do
            {
                appleX = rand() % SIZE;
                appleY = rand() % SIZE;
            } while (map[appleX][appleY] == '#' || appleX == playerX && appleY == playerY);
        }
    }

    printf("Game over.\n");
    return 0;
}
