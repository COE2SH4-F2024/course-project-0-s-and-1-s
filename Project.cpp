#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "objPosArrayList.h"
#include "Player.h"
#include "GameMechs.h"

using namespace std;
//preprocessor
#define DELAY_CONST 100000
//global
//Player* player = nullptr;
//GameMechs* gameMechs = nullptr;
GameMechs gameMechs;
Player player(&gameMechs);

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(!gameMechs.getExitFlagStatus())  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();
    

}

void GetInput(void)
{
    gameMechs.setInput(gameMechs.getInput());
}

void RunLogic(void)
{
    player.updatePlayerDir();
    player.movePlayer();
}

void DrawScreen(void)
{
    MacUILib_clearScreen();    
    //GameMechs gm;
    //Player player(&gm);
    //int boardWidth = gm.getBoardSizeX();
    //int boardHeight = gm.getBoardSizeY();
    int boardWidth = gameMechs.getBoardSizeX();
    int boardHeight = gameMechs.getBoardSizeY();
    for (int i = 0; i < boardHeight; i++)
   {
        for (int j = 0; j < boardWidth; j++)
        {
            char display = ' ';
            if (i == player.getPlayerPos().pos->x && j == player.getPlayerPos().pos->y )
            {
                display = '*';
            }
            /*
            for(k = 0; k < ITEM_COUNT; k++)
            {
                if (i == itemBin[k].x && j ==itemBin[k].y) // Only display valid items
                {
                    display= itemBin[k].player;
                }
            }
            */
            if (i == 0 || i == boardHeight - 1 || j == 0 || j == boardWidth - 1)
            {
                MacUILib_printf("#");
            }
            else
            {
                //display_string[i][j] = ' ';
                MacUILib_printf("%c", display);
            }
        }
        MacUILib_printf("\n");
   }
   MacUILib_printf("Score: %d", gameMechs.getScore());
    
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    

    MacUILib_uninit();

}
