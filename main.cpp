#include <iostream>
#include <stdio.h>
#include <thread>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <iostream>

#include "colors.h"

bool gameOver = false;
int score = 0;
int startingBlock = 2;
#define WIDTH 25
#define HEIGHT 25

HANDLE hConsole = NULL;
CONSOLE_SCREEN_BUFFER_INFO consoleInfo;

void ClearScreen() {
    COORD cursorPosition;
    cursorPosition.X = 0;
    cursorPosition.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

void draw(const char* text, int color) {
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    SetConsoleTextAttribute(hConsole, color);
    printf(text);
    SetConsoleTextAttribute(hConsole, consoleInfo.wAttributes);
}


void setTitle() {
    system("title 2048");
}

void setup() {
    int buffer[] = { WIDTH * 2 + 1, HEIGHT + 8 };
    SMALL_RECT windowSize = { 0, 0, buffer[0] - 1, buffer[1] - 1 };
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleWindowInfo(hConsole, true, &windowSize);
    setTitle();
    srand(time(NULL));
}

//         r   c
int matrix[4][4] = {
    { 0, 0, 0, 0 },

    { 0, 0, 0, 0 },

    { 0, 0, 0, 0 },

    { 0, 0, 0, 0 }
};

void printMatrices() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", matrix[j][i]);
        }
    }
}

void checkGameOver() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (matrix[i][j] == 0) {
                return; 
            }
        }
    }
    gameOver = true;
}



void addNewBlock() {
    int randRow, randCol;
    do {
        randRow = rand() % 4;
        randCol = rand() % 4;
    } while (matrix[randRow][randCol] != 0);

    matrix[randRow][randCol] = (rand() % 2 + 1) * 2;
}

void moveUp() {
    addNewBlock();
}

void moveDown() {
    addNewBlock();
}

void moveLeft() {
    addNewBlock();
}

void moveRight() {
    addNewBlock();
}

void performAction(const char* direction) {
    if (strcmp(direction, "up") == 0) {
        printf("up ");
        moveUp();
    } else if (strcmp(direction, "down") == 0) {
        printf("down ");
        //moveDown();
    } else if (strcmp(direction, "left") == 0) {
        printf("left ");
        //moveLeft();
    } else if (strcmp(direction, "right") == 0) {
        printf("right ");
        //moveRight();
    }
}

void keypressCheck() {
    int keys[4] = { VK_UP, VK_DOWN, VK_LEFT, VK_RIGHT };
    const char* directions[4] = { "up", "down", "left", "right" };
    bool pressed[4] = { false };

    while (true) {
        for (int i = 0; i < 4; ++i) {
            bool state = GetAsyncKeyState(keys[i]) & 0x8000;
            if (state && !pressed[i]) {
                pressed[i] = true;
                performAction(directions[i]);
            } else if (!state && pressed[i]) {
                pressed[i] = false;
            }
        }
        checkGameOver();
        Sleep(25);
    }
}

void renderTiles() {
    setTitle();
    printf("\n  ------------------------------\n\n");
    for (int i = 0; i < 4; i++) {
        printf("  |"); // divider at start of row
        for (int j = 0; j < 4; j++) {
            int value = matrix[j][i];
            if (value == 0) {
                printf("   ", value); // print empty space is the value at the matrix's index is 0
            } else if (value == 2) {
                printf(" "); draw(std::to_string(value).c_str(), BACKGROUND_YELLOW); printf(" ");
            } else if (value == 4) {
                printf(" "); draw(std::to_string(value).c_str(), BACKGROUND_LIGHT_YELLOW); printf(" ");
            } else if (value == 8) {
                printf(" "); draw(std::to_string(value).c_str(), BACKGROUND_LIGHT_BLUE); printf(" ");
            } else if (value == 16) {
                printf(" "); draw(std::to_string(value).c_str(), BACKGROUND_LIGHT_GREEN); printf(" ");
            } else if (value == 32) {
                printf(" "); draw(std::to_string(value).c_str(), BACKGROUND_LIGHT_CYAN); printf(" ");
            } else if (value == 64) {
                printf(" "); draw(std::to_string(value).c_str(), BACKGROUND_LIGHT_RED); printf(" ");
            } else if (value == 128) {
                printf(" "); draw(std::to_string(value).c_str(), BACKGROUND_LIGHT_MAGENTA); printf(" ");
            } else if (value == 256) {
                printf(" "); draw(std::to_string(value).c_str(), BACKGROUND_BLUE); printf(" ");
            } else if (value == 512) {
                printf(" "); draw(std::to_string(value).c_str(), BACKGROUND_CYAN); printf(" ");
            } else if (value == 1024) {
                printf(" "); draw(std::to_string(value).c_str(), BACKGROUND_LIGHT_YELLOW); printf(" ");
            } else if (value == 2048) {
                printf(" "); draw(std::to_string(value).c_str(), BACKGROUND_BRIGHT_WHITE); printf(" ");
            }


            if (j < 3) {
                printf("  |  "); // divider between each matrices
            }
        }
        printf(" |\n"); // divider at end of row
        if (i < 3) {
            printf("  \n  ------------------------------\n\n"); // Divider between rows
        }
    }
    printf("\n  ------------------------------\n\n");
}

int main() {
    setup(); std::thread myThread(keypressCheck);
    int randRow = rand() % 4;       int randRow2 = rand() % 4;
    int randCol = rand() % 4;       int randCol2 = rand() % 4;
    matrix[randCol][randRow] = startingBlock;   matrix[randCol2][randRow2] = startingBlock; // set 2 random matrices to startingBlock

    while (!gameOver) {
        printf("              "); draw("2048", BACKGROUND_LIGHT_YELLOW); printf("\n");
        renderTiles();
        printf("  ");
        draw("Score: ", BACKGROUND_WHITE);
        draw(std::to_string(score).c_str(), BACKGROUND_WHITE); printf("\n");
        Sleep(100);
        ClearScreen();
        if (gameOver) {
            system("cls"); renderTiles();
            printf("  "); draw("Score: ", BACKGROUND_WHITE); draw(std::to_string(score).c_str(), BACKGROUND_WHITE); printf("\n"); // show score
            printf("  "); draw("Game Over! ", BACKGROUND_LIGHT_RED);
            exit(0);
            break;
        }
    }


    myThread.join();
    return 0;
}