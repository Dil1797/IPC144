/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P2)
Full Name  : Dil Humyra Sultana Borna
Student ID#: 139166227
Email      : dhsborna@myseneca.ca
Section    : NEE

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// defining macros for maximum and minimum path length, max and min lives, 
#define MINIMUM_PATH_LENGTH 10
#define MAXIMUM_PATH_LENGTH 70
#define MINIMUM_LIVES 1
#define MAXIMUM_LIVES 10

// data type groups in player configuration.
typedef struct {
    int numLives;     // The number of lives a player can have.
    char repPlayer;   // Character symbol representing the player.
    int numTreasure;   //Counterfor the number of treasures found.
    int history[MAXIMUM_PATH_LENGTH];  //History of past entered positions (1's & 0's).
} PlayerInfo;

// data type groups in game configuration
typedef struct {
    int pathLength;     // The path length (number of positions) the game path will have.
    int numMoves;        // The maximum number of “moves” a player can make
    int bombs[MAXIMUM_PATH_LENGTH];    // Buried bombs path
    int treasure[MAXIMUM_PATH_LENGTH];     // Buried tresure path
} GameInfo;

int main(void)
{
    // declaring variables of struct
    PlayerInfo player;
    GameInfo game;

    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n\n");

    // PlayerInfo
    printf("PLAYER Configuration\n");
    printf("--------------------\n");
    // Prompt to set the player’s character symbol
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &player.repPlayer); // single char player symbol

    // Using do while loop to set the number players of lives
    do {
        printf("Set the number of lives: ");
        scanf("%d", &player.numLives);
        // checking the if condition, if this condition matvh then print the error message
        if (player.numLives < MINIMUM_LIVES || player.numLives > MAXIMUM_LIVES)
        {
            printf("     Must be between 1 and 10!\n");
        }
        // if the if statement doesnt match that means its valid value and will print this message.
        else
        {
            printf("Player configuration set-up is complete\n\n");
        }
    } while (player.numLives < MINIMUM_LIVES || player.numLives > MAXIMUM_LIVES);


    // GameInfo
    printf("GAME Configuration\n");
    printf("------------------\n");

    // starting of do while loop to set the path length until user enter the valid value.
    do {
        printf("Set the path length (a multiple of 5 between 10-70): ");
        scanf("%d", &game.pathLength);
        // if statement checks the condition, if matches then print the messages.
        if (!(game.pathLength >= MINIMUM_PATH_LENGTH && game.pathLength <= MAXIMUM_PATH_LENGTH && game.pathLength % 5 == 0))
        {
            printf("     Must be a multiple of 5 and between 10-70!!!\n");
        }
    } while (!(game.pathLength >= MINIMUM_PATH_LENGTH && game.pathLength <= MAXIMUM_PATH_LENGTH && game.pathLength % 5 == 0));

    // starting of do while loop to set the number of moves allowed for thr player until user enter the valid value.
    do {
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &game.numMoves);
        // if statement checks the condition, if matches then print the messages.
        if (game.numMoves < player.numLives || game.numMoves >(int)(0.75 * game.pathLength))
        {
            printf("    Value must be between %d and %d\n", player.numLives, (int)(0.75 * game.pathLength));
        }
    } while (game.numMoves < player.numLives || game.numMoves >(int)(0.75 * game.pathLength));
    printf("\n");

    int i;

    // entering bomb positions in sets of 5
    printf("BOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of 5 where a value\n");
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathLength);

    // storing values in bombs array
    // starting for loop to set the bomb position, here i will increase by 5 each time in the condition
    for (i = 0; i < game.pathLength; i += 5)
    {
        printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
        // in this scanf, the index of the array is increasing each time as it is set to 5
        scanf("%d %d %d %d %d",
            &game.bombs[i],
            &game.bombs[i + 1],
            &game.bombs[i + 2],
            &game.bombs[i + 3],
            &game.bombs[i + 4]);
    }
    printf("BOMB placement set\n\n");

    // entering treasure placements in sets of 5
    printf("TREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of 5 where a value\n");
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathLength);

    // storing values in treasure array
    // starting for loop to set the treasure position, here i will increase by 5 each time in the condition
    for (i = 0; i < game.pathLength; i += 5)
    {
        printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
        // in this scanf, the index of the array is increasing each time as it is set to 5
        scanf("%d %d %d %d %d",
            &game.treasure[i],
            &game.treasure[i + 1],
            &game.treasure[i + 2],
            &game.treasure[i + 3],
            &game.treasure[i + 4]);
    }
    printf("TREASURE placement set\n\n");

    printf("GAME configuration set-up is complete...\n\n");

    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");

    // display a summary
    // PlayerInfo
    printf("Player:\n");
    printf("   Symbol     : %c\n", player.repPlayer); // single char player symbol
    printf("   Lives      : %d\n", player.numLives); // player's lives
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n\n");

    // GameInfo
    printf("Game:\n");
    printf("   Path Length: %d\n", game.pathLength); // path length for bombs and treasure
    printf("   Bombs      : ");
    // starting for loop for bomb
    for (i = 0; i < game.pathLength; i++)
    {
        printf("%d", game.bombs[i]); // displaying bombs stored array
    }
    printf("\n");
    printf("   Treasure   : ");
    // starting for loop for treausre
    for (i = 0; i < game.pathLength; i++)
    {
        printf("%d", game.treasure[i]); // displaying treasure stored array
    }
    printf("\n\n");

    printf("====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n\n");

    int n, x, y, z;
    int move = 0, history_index = 0;
    player.numTreasure = 0;
    char sign[game.pathLength];

    // for player.history loop
    for (x = 0; x < game.pathLength; x++)
    {
        player.history[x] = 0;
    }

    // for changing the "-" sign
    for (y = 0; y < game.pathLength; y++)
    {
        sign[y] = '-';
    }

    // loop for the whole gameplay
    do
    {

        if (move != 0)
        {
            printf("  ");
            // for the movement of player.repPlayer symbol
            for (y = 1; y <= game.pathLength; y++)
            {
                if (move == y)
                {
                    printf("%c", player.repPlayer);
                    break;
                }
                else
                {
                    printf(" ");
                }
            }
            printf("\n");
        }
        printf("  ");

        // to assign and display each representative sign
        for (z = 0; z < game.pathLength; z++)
        {
            printf("%c", sign[z]);
        }
        printf("\n");

        // for "|" symbol
        printf("  ");
        for (i = 1; i <= game.pathLength; i++)
        {
            // for displaying another number for each 0
            if (i % 10 == 0)
            {
                printf("%d", (int)i / 10);
            }
            else
            {
                printf("|");
            }
        }
        printf("\n");

        printf("  ");
        for (i = 0; i < game.pathLength; i += 10) // adding more numbers based on game.pathLength
        {
            printf("1234567890");
        }

        // displaying the table and current status
        printf("\n");
        printf("+---------------------------------------------------+\n");
        printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", player.numLives, player.numTreasure, game.numMoves);
        printf("+---------------------------------------------------+\n");

        // ends the game
        if (player.numLives == 0)
        {
            break;
        }
        else if (game.numMoves == 0)
        {
            break;
        }

        // entering the next move of the player
        do
        {
            printf("Next Move [1-%d]: ", game.pathLength);
            scanf("%d", &move);
            if (move < 1 || move > game.pathLength)
            {
                printf("  Out of Range!!!\n");
            }
        } while (move < 1 || move > game.pathLength);

        printf("\n");

        int isRepeated = 0; // for validation if move is repeated

        /*demo how player.history works*/
        /* 1st move = 8
           2nd move = 5
           3rd move = 8
           4th move = 10
           5th move = 5
        */
        // if the player already entered the same move
        for (n = 0; n <= history_index; n++)
            /* 1st move
               0 <= 0; n++
               2nd move
               0 <= 1; n++
               1 <= 1; n++
               3rd move
               0 <= 2; n++ stops here because if becomes true
               4th move
               0 <= 2; n++
               1 <= 2; n++
               2 <= 2; n++
               5th move
               0 <= 3; n++
               1 <= 3; n++ stops here because if becomes true
            */
        {
            if (player.history[n] == move)
                /* 1st move
                   [0] == 8? false
                   2nd move
                   [0] == 5? false
                   [1] == 5? false
                   3rd move
                   [0] == 8? true
                   4th move
                   [0] == 10? false
                   [1] == 10? false
                   [2] == 10? false
                   5th move
                   [0] == 5? false
                   [1] == 5? true
                */
            {
                isRepeated = 1; // [0] == 8 true, [1] == 5 true
                printf("===============> Dope! You've been here before!\n\n");
            }
        }

        // if move is not repeated
        if (isRepeated == 0)
        {
            // storing moves history_index into array
            player.history[history_index] = move; // [0] = 8, [1] == 5, [2] == 10
            history_index++; // 1, 2, 3
            if (game.bombs[move - 1] == 1 && game.treasure[move - 1] == 0)
            {
                printf("===============> [!] !!! BOOOOOM !!! [!]\n\n");
                sign[move - 1] = '!';
                player.numLives--;
                game.numMoves--;
            }
            // bomb
            else if (game.bombs[move - 1] == 1 && game.treasure[move - 1] == 1)
            {
                printf("===============> [&] !!! BOOOOOM !!! [&]\n");
                printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n\n");
                sign[move - 1] = '&';
                player.numLives--;
                player.numTreasure++;
                game.numMoves--;
            }
            //treasure
            else if (game.treasure[move - 1] == 1 && game.bombs[move - 1] == 0)
            {
                printf("===============> [$] $$$ Found Treasure! $$$ [$]\n\n");
                sign[move - 1] = '$';
                player.numTreasure++;
                game.numMoves--;
            }
            // both bomb and treasure
            else if (game.bombs[move - 1] == 0 && game.treasure[move - 1] == 0)
            {
                printf("===============> [.] ...Nothing found here... [.]\n\n");
                sign[move - 1] = '.';
                game.numMoves--;
            }
        }

        // remaining number of lives
        if (player.numLives == 0)
        {
            printf("No more LIVES remaining!\n\n");
        }
        // remaining number of moves
        if (game.numMoves == 0)
        {
            printf("No more MOVES remaining!\n\n");
        }

    } while (game.numMoves != 0 || player.numLives != 0);

    // end message
    printf("\n##################\n");
    printf("#   Game over!   #\n");
    printf("##################\n\n");
    printf("You should play again and try to beat your score!\n");

    return 0;
}
