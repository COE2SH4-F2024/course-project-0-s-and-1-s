#include "Player.h"


Player::Player(GameMechs* thisGMRef) //constructor
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    playerPos.symbol = '*';
    playerPos.pos->x = 5;
    playerPos.pos->y = 5;
}


Player::~Player() //destructor
{
    // delete any heap members here
}

objPos Player::getPlayerPos() const
{
    // return the reference to the playerPos array list
    return playerPos;
}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic       
    char input = mainGameMechsRef->getInput();
    if(input!= 0)  // if not null character
    {
        switch(input)
        {                      
            case ' ':  // exit
                mainGameMechsRef->setExitTrue();
                break;

            // Add more key processing here          
            case 'W':
                if(myDir != DOWN) {
                    myDir = UP;
                }
                break;
            // Add more key processing here 
            case 'A':
                if(myDir != RIGHT) {
                    myDir = LEFT;
                }
                break;
            // Add more key processing here 
            case 'S':
                if(myDir != UP) {
                    myDir = DOWN;
                }
                break;
            case 'D':
                if(myDir != LEFT) {
                    myDir = RIGHT;
                }
                break;
            /*
            case 43: // "+" increase speed
                if(game_speed < speed_4) {
                    game_speed++;
                }
                break;
            case 45: // "-" decrease speed
                if(game_speed > speed_0) {
                    game_speed--;
                }
                break;
            */
            default:
                break;
        }
        
        input = 0;
    }   
}

void Player::movePlayer()
{
    int boardSizeX = mainGameMechsRef->getBoardSizeX();
    int boardSizeY = mainGameMechsRef->getBoardSizeY();
    // PPA3 Finite State Machine logic
    char input = mainGameMechsRef->getInput();
    switch(myDir) 
    {
        case UP:
            playerPos.pos->x--;
            break;
        case DOWN:
            playerPos.pos->x++;
            break;
        case LEFT:
            playerPos.pos->y--;
            break;
        case RIGHT:
            playerPos.pos->y++;
            break;
        default:
            break; 
    }
    if (playerPos.pos->x <= 0) 
    {
        playerPos.pos->x = boardSizeY - 2; // Wrap to bottom
    }
    else if (playerPos.pos->x >= boardSizeY - 1) 
    {
        playerPos.pos->x = 1; // Wrap to top
    }
    else if (playerPos.pos->y <= 0) 
    {
        playerPos.pos->y = boardSizeX - 2; // Wrap to right
    }
    else if (playerPos.pos->y >= boardSizeX - 1) 
    {
        playerPos.pos->y = 1; // Wrap to left
    }   
    if (myDir != 0)
    {
        //moveCount++;
    }
    
}

// More methods to be added