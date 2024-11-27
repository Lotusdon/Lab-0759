#include "raylib.h"
#include <stdio.h>

#define EMPTY 0
#define X_PLAYER 1
#define O_PLAYER 2

Sound mark;
Sound wins;
Sound victory;

int grid[3][3] = { {EMPTY, EMPTY, EMPTY}, {EMPTY, EMPTY, EMPTY}, {EMPTY, EMPTY, EMPTY} };
int currentPlayer = X_PLAYER;
int space = 0;
int isSinglePlayer = 0; // 0 = Multiplayer, 1 = Single Player

// Function Prototypes
void DrawMenu(int *menuActive, int *singlePlayer);
void ResetGame();
int Winner();
void mainMenu();
void hardMove();

// Function: Main Menu
void mainMenu() {
    int menuActive = 1;     // Menu state (active/inactive)

    while (menuActive && !WindowShouldClose()) {
        DrawMenu(&menuActive, &isSinglePlayer);  // Pass by reference for state management
    }
}

// Function: Draw Menu
void DrawMenu(int *menuActive, int *singlePlayer) {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    // Title
    DrawText("TACTIX ", 200, 50, 50, BLACK);

    // Single Player Option
    DrawRectangle(150, 200, 300, 100, BLACK);
    DrawText("SINGLE PLAYER", 175, 230, 30, WHITE);

    // Multiplayer Option
    DrawRectangle(150, 350, 300, 100, BLACK);
    DrawText("MULTIPLAYER", 195, 380, 30, WHITE);

    // Check for mouse clicks on menu options
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
        Vector2 mousePos = GetMousePosition();
        if (mousePos.x > 150 && mousePos.x < 450 && mousePos.y > 200 && mousePos.y < 300) {
            *singlePlayer = 1;    // Set game mode to Single Player
            *menuActive = 0;      // Exit menu and start the game
        }
        if (mousePos.x > 150 && mousePos.x < 450 && mousePos.y > 350 && mousePos.y < 450) {
            *singlePlayer = 0;    // Set game mode to Multiplayer
            *menuActive = 0;      // Exit menu and start the game
        }
    }

    EndDrawing();
}

// Function: Reset Game
void ResetGame() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            grid[i][j] = EMPTY;
        }
    }
    space = 0;
    currentPlayer = X_PLAYER;
}

// Function: Determine Winner
int Winner() {
    for (int i = 0; i < 3; i++) {
        if (grid[i][0] != EMPTY && grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2]) {
            return grid[i][0];
        }
    }
    for (int j = 0; j < 3; j++) {
        if (grid[0][j] != EMPTY && grid[0][j] == grid[1][j] && grid[1][j] == grid[2][j]) {
            return grid[0][j];
        }
    }
    if (grid[0][0] != EMPTY && grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]) {
        return grid[0][0];
    }
    if (grid[0][2] != EMPTY && grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0]) {
        return grid[0][2];
    }
    return EMPTY;
}

// Placeholder for Hard AI Move
void hardMove() {
    
    // Check if computer can win in this move
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (grid[row][col] == EMPTY) {
                grid[row][col] = currentPlayer; // Temporarily make the move
                if (Winner() == currentPlayer) {
                    space++;
                    return; // Keep the winning move
                }
                grid[row][col] = EMPTY; // Undo the move
            }
        }
    }

    // Check if opponent can win in the next move and block it
    int opponent = (currentPlayer == X_PLAYER) ? O_PLAYER : X_PLAYER;
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            if (grid[row][col] == EMPTY) {
                grid[row][col] = opponent; // Temporarily make the opponent's move
                if (Winner() == opponent) {
                    grid[row][col] = currentPlayer; // Block the move
                    space++;
                    return;
                }
                grid[row][col] = EMPTY; // Undo the move
            }
        }
    }

    // Take the center if available
    if (grid[1][1] == EMPTY) {
        grid[1][1] = currentPlayer;
        space++;
        return;
    }

    // Take one of the corners if available
    int corners[4][2] = {{0, 0}, {0, 2}, {2, 0}, {2, 2}};
    for (int i = 0; i < 4; i++) {
        int row = corners[i][0];
        int col = corners[i][1];
        if (grid[row][col] == EMPTY) {
            grid[row][col] = currentPlayer;
            space++;
            return;
        }
    }

    // Take one of the sides if available
    int sides[4][2] = {{0, 1}, {1, 0}, {1, 2}, {2, 1}};
    for (int i = 0; i < 4; i++) {
        int row = sides[i][0];
        int col = sides[i][1];
        if (grid[row][col] == EMPTY) {
            grid[row][col] = currentPlayer;
            space++;
            return;
        }
    }
}

// Main Function
int main(void) {
    const int screenWidth = 600;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Tactix");
    InitAudioDevice();

    mark = LoadSound("move.wav");
    wins = LoadSound("start.wav");
    victory = LoadSound("wins.wav");

    PlaySound(wins);
    SetTargetFPS(60);

    int gridSize = 3;
    int cellSize = screenWidth / gridSize;

    // Show Main Menu
    mainMenu();

    // Game Loop
    while (!WindowShouldClose()) {
        int win = Winner();

        if (space < 9 && win == EMPTY) {
            if (isSinglePlayer && currentPlayer == O_PLAYER) {
                hardMove();
                currentPlayer = X_PLAYER;
            } else if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                int mouseX = GetMouseX();
                int mouseY = GetMouseY();
                int row = mouseY / cellSize;
                int col = mouseX / cellSize;

                if (grid[row][col] == EMPTY) {
                    grid[row][col] = currentPlayer;
                    PlaySound(mark);
                    space++;
                    currentPlayer = (currentPlayer == X_PLAYER) ? O_PLAYER : X_PLAYER;
                }
            }
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        if (space < 9 && win == EMPTY) {
            for (int i = 1; i < gridSize; i++) {
                DrawLine(i * cellSize, 0, i * cellSize, screenHeight, BLACK);
                DrawLine(0, i * cellSize, screenWidth, i * cellSize, BLACK);
            }
            for (int row = 0; row < gridSize; row++) {
                for (int col = 0; col < gridSize; col++) {
                    if (grid[row][col] == X_PLAYER) {
                        DrawText("X", col * cellSize + cellSize / 3, row * cellSize + cellSize / 3, 80, DARKBLUE);
                    } else if (grid[row][col] == O_PLAYER) {
                        DrawText("O", col * cellSize + cellSize / 3, row * cellSize + cellSize / 3, 80, DARKGREEN);
                    }
                }
            }
            char turnText[20];
            snprintf(turnText, sizeof(turnText), "Player %s's turn", currentPlayer == X_PLAYER ? "X" : "O");
            DrawText(turnText, screenWidth / 2 - MeasureText(turnText, 20) / 2, screenHeight - 40, 20, DARKGRAY);
        } else if (space == 9 && win == EMPTY) {
            DrawText("Grid is full, press 1 to reset", screenWidth / 2 - MeasureText("Grid is full, press 1 to reset", 20) / 2, screenHeight / 2, 20, BLUE);
            if (IsKeyPressed(KEY_ONE)) {
                ResetGame();
            }
        } else if (win != EMPTY) {
            PlaySound(victory);
            const char *winnerText = (win == X_PLAYER) ? "Player X Wins" : "Player O Wins";
            DrawText(winnerText, screenWidth / 2 - MeasureText(winnerText, 40) / 2, screenHeight / 2, 40, GREEN);
            DrawText("Press 1 to reset", screenWidth / 2 - MeasureText("Press 1 to reset", 20) / 2, screenHeight / 2 + 50, 20, DARKGRAY);
            if (IsKeyPressed(KEY_ONE)) {
                ResetGame();
            }
        }

        EndDrawing();
    }

    UnloadSound(mark);
    UnloadSound(wins);
    UnloadSound(victory);
    CloseAudioDevice();
    CloseWindow();

    return 0;
}
