/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #7 (P1)
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
#pragma warning(disable:6031)

#include <stdio.h>

// defining macros for maximum and minimum path length, max and min lives, 
// max and min move, path length multiple and max move percentage.
#define MAX_PATH_LENGTH 70
#define MIN_PATH_LENGTH 10
#define MAX_LIVE 10
#define MIN_LIVE 1
#define MAX_MOVE 26
#define MIN_MOVE 3
#define PATH_LENGTH_MULTIPLE 5
#define MAX_MOVE_PERCENTAGE 0.75

// Defining the PlayerInfo structure
struct PlayerInfo
{
	int lives;                         // The number of lives a player can have.
	char playerSymbol;                 // Character symbol representing the player.
	int treasureCounter;               //Counterfor the number of treasures found.
	int pathHistory[MAX_PATH_LENGTH];  //History of past entered positions (1's & 0's).
};

// Defining the GameInfo structure
struct GameInfo
{
	int playerMove;                     // The maximum number of “moves” a player can make
	int pathLength;                     // The path length (number of positions) the game path will have.
	int bombs[MAX_PATH_LENGTH];         // Buried bombs path
	int treasure[MAX_PATH_LENGTH];      // Buried tresure path
};

int main(void)
{
	// declaring variables of struct
	struct PlayerInfo player;
	struct GameInfo game;

	printf("================================\n"); 
	printf("         Treasure Hunt!\n");
	printf("================================\n\n");
	
	printf("PLAYER Configuration\n");
	printf("--------------------\n");

	// Prompt to set the player’s character symbol
	printf("Enter a single character to represent the player: ");
	scanf(" %c", &player.playerSymbol);

	// Using do while loop to set the number of lives
	do
	{
		printf("Set the number of lives: ");
		scanf("%d", &player.lives);

		// checking the if condition, if this condition matvh then print the error message
		if (player.lives < MIN_LIVE || player.lives > MAX_LIVE)
		{
			printf("     Must be between %d and %d!\n", MIN_LIVE, MAX_LIVE);
		}
		// if the if statement doesnt match that means its valid value and will print this message.
		else
		{
			printf("Player configuration set-up is complete\n\n");
		}

	} while (player.lives < MIN_LIVE || player.lives > MAX_LIVE);

	printf("GAME Configuration\n");
	printf("------------------\n");

	// starting of do while loop to set the path length until user enter the valid value.
	do
	{
		printf("Set the path length (a multiple of %d between %d-%d): ", 
			PATH_LENGTH_MULTIPLE, MIN_PATH_LENGTH, MAX_PATH_LENGTH);
		scanf("%d", &game.pathLength);
		// if statement checks the condition, if matches then print the messages.
		if (game.pathLength % PATH_LENGTH_MULTIPLE != 0 || 
			game.pathLength < MIN_PATH_LENGTH || game.pathLength > MAX_PATH_LENGTH)
		{
			printf("     Must be a multiple of %d and between %d-%d!!!\n", 
				PATH_LENGTH_MULTIPLE, MIN_PATH_LENGTH, MAX_PATH_LENGTH);
		}
	} while (game.pathLength % PATH_LENGTH_MULTIPLE != 0 || 
		game.pathLength < MIN_PATH_LENGTH || game.pathLength > MAX_PATH_LENGTH);

	// starting of do while loop to set the number of moves allowed for thr player until user enter the valid value.
	do
	{
		printf("Set the limit for number of moves allowed: ");
		scanf("%d", &game.playerMove);
		// if statement checks the condition, if matches then print the messages.
		if (game.playerMove < MIN_MOVE || 
			game.playerMove > (int)(game.pathLength * MAX_MOVE_PERCENTAGE))
		{
		printf("     Value must be between %d and %d\n", MIN_MOVE, MAX_MOVE);
		}
	} while (game.playerMove < MIN_MOVE ||
		game.playerMove >(int)(game.pathLength * MAX_MOVE_PERCENTAGE));

	printf("\n");

	// Set BOMB positions in sets of 5
	printf("BOMB Placement\n");
	printf("--------------\n\n");
	printf("Enter the bomb positions in sets of 5 where a value\n");
	printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
	printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathLength);

	// starting for loop to set the bomb position, here i will increase by 5 each time in the condition
	// storing values in bomb array
	for (int i = 0; i < game.pathLength; i += 5)
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

	// Set treaure positions in sets of 5
	printf("TREASURE Placement\n");
	printf("------------------\n");
	printf("Enter the treasure placements in sets of 5 where a value\n");
	printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
	printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathLength);

	// starting for loop to set the treasure position, here i will increase by 5 each time in the condition
	// storing values in treasure array
	for (int i = 0; i < game.pathLength; i += 5)
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
	printf("   Symbol     : %c\n", player.playerSymbol); // single char player symbol
	printf("   Lives      : %d\n", player.lives); // player's lives
	printf("   Treasure   : [ready for gameplay]\n");
	printf("   History    : [ready for gameplay]\n\n");

	// GameInfo
	printf("Game:\n");
	printf("   Path Length: %d\n", game.pathLength); // path length for bombs and treasure
	printf("   Bombs      : ");

	// starting for loop 
	for (int i = 0; i < game.pathLength; i++)
	{
		printf("%d", game.bombs[i]); // displaying bombs stored array
	}
	printf("\n");
	printf("   Treasure   : ");
	for (int i = 0; i < game.pathLength; i++)
	{
		printf("%d", game.treasure[i]); // displaying treasure stored array
	}
	printf("\n\n");

	printf("====================================\n");
	printf("~ Get ready to play TREASURE HUNT! ~\n");
	printf("====================================\n");


	return 0;
}