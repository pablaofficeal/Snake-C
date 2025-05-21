#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include "snake.h"

int gameOver;
int x, y, fruitX, fruitY, score;
int tailX[MAX_SNAKE_LENGTH], tailY[MAX_SNAKE_LENGTH];
int nTail;
enum Direction dir;

void Setup() {
    gameOver = 0;
    dir = STOP;
    x = WIDTH / 2;
    y = HEIGHT / 2;
    fruitX = rand() % WIDTH;
    fruitY = rand() % HEIGHT;
    score = 0;
    nTail = 0;
}

void Draw() {
    system("cls");
    for (int i = 0; i < WIDTH + 2; i++)
        printf("#");
    printf("\n");

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (j == 0)
                printf("#");
            int isTail = 0;
            for (int k = 0; k < nTail; k++) {
                if (tailX[k] == j && tailY[k] == i) {
                    printf("o");
                    isTail = 1;
                }
            }
            if (!isTail) {
                if (j == x && i == y)
                    printf("O");
                else if (j == fruitX && i == fruitY)
                    printf("F");
                else
                    printf(" ");
            }
            if (j == WIDTH - 1)
                printf("#");
        }
        printf("\n");
    }

    for (int i = 0; i < WIDTH + 2; i++)
        printf("#");
    printf("\nScore: %d\n", score);
}

void Input() {
    if (_kbhit()) {
        switch (_getch()) {
        case 75: // Стрелка влево
            if (dir != RIGHT)
                dir = LEFT;
            break;
        case 77: // Стрелка вправо
            if (dir != LEFT)
                dir = RIGHT;
            break;
        case 72: // Стрелка вверх
            if (dir != DOWN)
                dir = UP;
            break;
        case 80: // Стрелка вниз
            if (dir != UP)
                dir = DOWN;
            break;
        case 'x':
            gameOver = 1;
            break;
        }
    }
}

void Logic() {
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < nTail; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    switch (dir) {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }

    if (x >= WIDTH) x = 0; else if (x < 0) x = WIDTH - 1;
    if (y >= HEIGHT) y = 0; else if (y < 0) y = HEIGHT - 1;

    for (int i = 0; i < nTail; i++) {
        if (tailX[i] == x && tailY[i] == y)
            gameOver = 1;
    }

    if (x == fruitX && y == fruitY) {
        score += 10;
        fruitX = rand() % WIDTH;
        fruitY = rand() % HEIGHT;
        nTail++;
    }
}