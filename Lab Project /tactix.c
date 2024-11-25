#include "raylib.h"
#include <stdio.h>

// Game state
#define EMPTY 0
#define X_PLAYER 1
#define O_PLAYER 2
 Sound mark ;
    Sound wins;
    Sound victory ;

// Game grid
int grid[3][3] = {{EMPTY, EMPTY, EMPTY},
                  {EMPTY, EMPTY, EMPTY},
                  {EMPTY, EMPTY, EMPTY}};

// Current player (1 for "X", 2 for "O")
int currentPlayer = X_PLAYER;
int space = 0;  // Tracks how many spaces are filled

int Winner() {
    // Check rows
    
    for (int i = 0; i < 3; i++) {
        if (grid[i][0] != EMPTY && grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2]) {
           
            return grid[i][0]; // Return the winning player (X_PLAYER or O_PLAYER)
        }
    }

    // Check columns
    for (int j = 0; j < 3; j++) {
        if (grid[0][j] != EMPTY && grid[0][j] == grid[1][j] && grid[1][j] == grid[2][j]) {
            
            return grid[0][j]; // Return the winning player (X_PLAYER or O_PLAYER)
        }
    }

    // Check diagonals
    if (grid[0][0] != EMPTY && grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]) {
       
        return grid[0][0]; // Return the winning player (X_PLAYER or O_PLAYER)
    }
    if (grid[0][2] != EMPTY && grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0]) {
        
        return grid[0][2]; // Return the winning player (X_PLAYER or O_PLAYER)
    }

    // No winner
    return EMPTY;
}


// Function to reset the game
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
    const int screenWidth = 600;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Tactix");
    InitAudioDevice();
    
     mark = LoadSound("move.wav");
     wins = LoadSound("start.wav");
     victory = LoadSound("wins.wav");
    PlaySound(wins);

    // Set target FPS
    SetTargetFPS(60);

    // Define the grid size and cell size
    int gridSize = 3;
    int cellSize = screenWidth / gridSize;

    // Main game loop
    while (!WindowShouldClose())
    { int win =Winner();

        // Update
        if (space < 9 && IsMouseButtonPressed(MOUSE_BUTTON_LEFT) ) {
            // Get mouse position
            int mouseX = GetMouseX();
            int mouseY = GetMouseY();

            // Calculate the row and column based on mouse position
            int row = mouseY / cellSize;
            int col = mouseX / cellSize;

            // Only update the cell if it's empty
            if (grid[row][col] == EMPTY) {
                // Set the cell based on the current player
                grid[row][col] = currentPlayer;
                 PlaySound(mark);
                space++;  // Increment the filled spaces count

                // Switch player after each move
                currentPlayer = (currentPlayer == X_PLAYER) ? O_PLAYER : X_PLAYER;
            }
            
            
            
        }

        // Draw
        BeginDrawing();
        
        // Clear the screen
        ClearBackground(RAYWHITE);
        

        if (space < 9 && win == EMPTY) {
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
            snprintf(turnText, sizeof(turnText), "Player %s's turn", currentPlayer == X_PLAYER ? "X" : "O");
            DrawText(turnText, screenWidth / 2 - MeasureText(turnText, 20) / 2, screenHeight - 40, 20, DARKGRAY);

        } else if (space ==9 && win== EMPTY) {
            // Display the full-screen message when the grid is full
            DrawText("Grid is full, press 1 to reset", screenWidth / 2 - MeasureText("Grid is full, press 1 to reset", 20) / 2, screenHeight / 2, 20, BLUE);

            // Wait for key press to reset the game
            if (IsKeyPressed(KEY_ONE)) {
                ResetGame();  // Reset the game
            }
        } else if (win != EMPTY && space != 0){
            PlaySound(victory);
            
            if (win ==1 ){
            
             DrawText("Player 1 Wins", screenWidth / 2 - MeasureText("Player 1 Wins", 40) / 2, screenHeight / 2, 40, GREEN);
             
            }
            else {
                
                DrawText("Player 2 Wins", screenWidth / 2 - MeasureText("Player 2 Wins", 40) / 2, screenHeight / 2, 40, GREEN);
               
            }
        // Wait for reset
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

    // De-Initialization
    CloseWindow();  // Close window and OpenGL context

    return 0;
}
