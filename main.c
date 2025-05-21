#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "snake.h"

int main() {
    srand(time(0));
    Setup();
    while (!gameOver) {
        Draw();
        Input();
        Logic();
        Sleep(100);
    }
    printf("Game Over! Final Score: %d\n", score);
    return 0;
}