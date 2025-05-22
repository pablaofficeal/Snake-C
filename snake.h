#ifndef SNAKE_H
#define SNAKE_H

#define WIDTH 20
#define HEIGHT 15
#define MAX_SNAKE_LENGTH 200

extern int gameOver;
extern int x, y, fruitX, fruitY, score;
extern int tailX[MAX_SNAKE_LENGTH], tailY[MAX_SNAKE_LENGTH];
extern int nTail;
enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };
extern enum Direction dir;

void Setup();
void Draw();
void Input();
void Logic();

#endif