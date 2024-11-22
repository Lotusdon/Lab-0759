#include "raylib.h"
#include <stdio.h>

// Game state
#define EMPTY 0
#define X_PLAYER 1
#define O_PLAYER 2

// Game grid
int grid[3][3] = {{EMPTY, EMPTY, EMPTY},
                  {EMPTY, EMPTY, EMPTY},
                  {EMPTY, EMPTY, EMPTY}};

// Current player (1 for "X", 2 for "O")
int currentPlayer = X_PLAYER;
int space;

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
void ResetGame()
{
    // Clear the grid and reset the player
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            grid[i][j] = EMPTY;
        }
    }
    space = 0;  // Reset the filled spaces counter
    currentPlayer = X_PLAYER;  // Reset to Player X's turn
}






int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 600;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Tic-Tac-Toe");
    int space=0;

    // Set target FPS
    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    // Define the grid size and cell size
    int gridSize = 3;
    int cellSize = screenWidth / gridSize;

    // Main game loop
    while (!WindowShouldClose())
    {
        // Update
        //----------------------------------------------------------------------------------
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            // Get mouse position
            int mouseX = GetMouseX();
            int mouseY = GetMouseY();

            // Calculate the row and column based on mouse position
            int row = mouseY / cellSize;
            int col = mouseX / cellSize;

            // Only update the cell if it's empty
            if (grid[row][col] == EMPTY) {
                // Set the cell based on the current player
                if (currentPlayer == X_PLAYER) {
                    grid[row][col] = X_PLAYER;
                    space++;
                } else {
                    grid[row][col] = O_PLAYER;
                    space++;
                }

                // Switch player after each move
                currentPlayer = (currentPlayer == X_PLAYER) ? O_PLAYER : X_PLAYER;
            }
        }
       }
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);  // Clear the background to white

        // Draw the Tic-Tac-Toe grid (3x3)
        for (int i = 1; i < gridSize; i++)  // Draw vertical lines
        {
            DrawLine(i * cellSize, 0, i * cellSize, screenHeight, BLACK);
        }

        for (int i = 1; i < gridSize; i++)  // Draw horizontal lines
        {
            DrawLine(0, i * cellSize, screenWidth, i * cellSize, BLACK);
        }

        // Draw the "X" and "O" marks based on the grid state
        for (int row = 0; row < gridSize; row++) {
            for (int col = 0; col < gridSize; col++) {
                if (grid[row][col] == X_PLAYER) {
                    DrawText("X", col * cellSize + cellSize / 3, row * cellSize + cellSize / 3, 80, DARKBLUE);
                    
                } else if (grid[row][col] == O_PLAYER) {
                    DrawText("O", col * cellSize + cellSize / 3, row * cellSize + cellSize / 3, 80, DARKGREEN);
                    
                }
            }
        }

        // Display whose turn it is
        char turnText[20];
        if (currentPlayer == X_PLAYER) {
            snprintf(turnText, sizeof(turnText), "Player X's turn");
        } else {
            snprintf(turnText, sizeof(turnText), "Player O's turn");
        }
        DrawText(turnText, screenWidth / 2 - MeasureText(turnText, 20) / 2, screenHeight - 40, 20, DARKGRAY);
        if (space == 9) {
            ClearBackground(RAYWHITE);
            DrawText("Grid is full", screenWidth / 2 - MeasureText("Grid is full", 20) / 2, screenHeight / 2, 20, BLUE);
            DrawText("Click anywhere to reset", screenWidth / 2 - MeasureText("Click anywhere to reset", 20) / 2, screenHeight / 2 + 30, 20, DARKGRAY);

            
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                ResetGame();  
            }
                    
        }
        
        EndDrawing();
        //----------------------------------------------------------------------------------
    

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();  // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
