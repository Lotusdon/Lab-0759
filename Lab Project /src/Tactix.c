#include "raylib.h"
#include <stdio.h>


#define EMPTY 0
#define X_PLAYER 1
#define O_PLAYER 2
 Sound mark ;
    Sound wins;
    Sound victory ;


int grid[3][3] = {{EMPTY, EMPTY, EMPTY},
                  {EMPTY, EMPTY, EMPTY},
                  {EMPTY, EMPTY, EMPTY}};


int currentPlayer = X_PLAYER;
int space = 0;  

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



void ResetGame()
{
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            grid[i][j] = EMPTY;
        }
    }
    space = 0;  
    currentPlayer = X_PLAYER;  
}

int main(void)
{
   
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

    
    while (!WindowShouldClose())
    { int win =Winner();

       
        if (space < 9 && IsMouseButtonPressed(MOUSE_BUTTON_LEFT) ) {
            
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

        
        BeginDrawing();
        
      
        ClearBackground(RAYWHITE);
        

        if (space < 9 && win == EMPTY) {
           
            for (int i = 1; i < gridSize; i++)  
            {
                DrawLine(i * cellSize, 0, i * cellSize, screenHeight, BLACK);
            }

            for (int i = 1; i < gridSize; i++) 
            {
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

        } else if (space ==9 && win== EMPTY) {
            
            DrawText("Grid is full, press 1 to reset", screenWidth / 2 - MeasureText("Grid is full, press 1 to reset", 20) / 2, screenHeight / 2, 20, BLUE);

            
            if (IsKeyPressed(KEY_ONE)) {
                ResetGame();  
            }
        } else if (win != EMPTY && space != 0){
            PlaySound(victory);
            
            if (win ==1 ){
            
             DrawText("Player 1 Wins", screenWidth / 2 - MeasureText("Player 1 Wins", 40) / 2, screenHeight / 2, 40, GREEN);
             
            }
            else {
                
                DrawText("Player 2 Wins", screenWidth / 2 - MeasureText("Player 2 Wins", 40) / 2, screenHeight / 2, 40, GREEN);
               
            }
       
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
