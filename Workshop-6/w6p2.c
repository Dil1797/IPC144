/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #6 (P2)
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
#include <math.h>

// Defining a macro, the maximum number of items limited to 10. 
#define MAX_WISH_LIST 10

int main(void)
{
	// matching (parallel) arrays for cost, priority, finance options.
	double itemCost[MAX_WISH_LIST];
	char   financeOption[MAX_WISH_LIST];
	int    itemPriority[MAX_WISH_LIST];

	// The minimum and maximum values, minimum costs are stored in unmodifiable variables.
	const double maxValue = 400000.00;
	const double minValue = 500.00;
	const double minCost = 100.00;

	// declaring and initializing variables.
	double totalCost = 0.00;
	double monthlyIncome = 0.00;
	int    wishList = 0;
	int    selection;
	int	   flag = 0;
	int    years;
	int    months;
	double cost_priorities_1 = 0;
	double cost_priorities_2 = 0;
	double cost_priorities_3 = 0;
	int    isFinanced;
	double print_by_category;
	int filter_priority;

	// variable for iteration number.
	int    i;

	printf("+--------------------------+\n");
	printf("+   Wish List Forecaster   |\n");
	printf("+--------------------------+\n\n");

	// started do while loop, this loop will continue until a valid value entered for monthly income.
	do
	{
		// prompting the user for their NET monthly income.
		printf("Enter your monthly NET income: $");
		scanf("%lf", &monthlyIncome);

		// if statement starts here, it checks if the condition matcehs for the income
		if (monthlyIncome < minValue)
		{
			// error message will prompt if the condition matches
			printf("ERROR: You must have a consistent monthly"
				" income of at least $500.00\n\n");
		}
		// if the first condition doesnt match, will check this else if statement condition.
		else if (monthlyIncome > maxValue)
		{
			// if the else if condition matches the error message will prompt.
			printf("ERROR: Liar! I'll believe you if you enter a value"
				" no more than $400000.00\n\n");
		}
	} while (monthlyIncome < minValue || monthlyIncome > maxValue); //do while loop ends here.
	printf("\n");

	// started do while loop, this loop will continue until a valid value entered for number of wish list item.
	do
	{
		//  prompting the user to specify the number of wish list items they want to use in the forecast.
		printf("How many wish list items do you want to forecast?: ");
		scanf("%d", &wishList);

		// if statement starts here, it checks if the condition matcehs for the wish list.
		if (wishList < 1 || wishList > MAX_WISH_LIST)
		{
			// error message will prompt if the condition matches
			printf("ERROR: List is restricted to between 1 and 10 items.\n\n");
		}
	} while (wishList < 1 || wishList > MAX_WISH_LIST); // //do while loop ends here.
	printf("\n");

	// using for loop iteration construct to store the wish list iteam details.
	for (i = 0; i < wishList; i++)
	{
		// printing the item details number for eatch time, while the loop will iterate the item number will increase.
		printf("Item-%d Details:\n", i + 1);

		// do while loop start, will continue unless a valid cost entered.
		do
		{
			// prompt for user input for the cost.
			printf("   Item cost: $");
			scanf("%lf", &itemCost[i]);

			// if statement starts, checks the condition for the cost.
			if (itemCost[i] < minCost)
			{
				// if the condition matches this error message will prompt.
				printf("      ERROR: Cost must be at least $100.00\n");
			}
		} while (itemCost[i] < minCost); // do while loop ends here.

		// here eatch time of the iteration, total cost will be calculating for items.
		totalCost = itemCost[i] + totalCost;

		// do while loop start, will continue unless a valid priority entered.
		do
		{
			// prompt to enter the priority for the user.
			printf("   How important is it to you? [1=must have,"
				" 2=important, 3=want]: ");
			scanf("%d", &itemPriority[i]);

			// if statements starts, checks the condition for the valid priority.
			if (itemPriority[i] < 1 || itemPriority[i] > 3)
			{
				// if this condition matches then this error message will prompt.
				printf("      ERROR: Value must be between 1 and 3\n");
			}
		} while (itemPriority[i] < 1 || itemPriority[i] > 3); // do while loop ends here.

		// Here check the conditions for each item priority if it matches with the priority then it will calculate the total price of all same categories product.
	if (itemPriority[i] == 1) cost_priorities_1 = itemCost[i] + cost_priorities_1;
	if (itemPriority[i] == 2) cost_priorities_2 = itemCost[i] + cost_priorities_2;
	if (itemPriority[i] == 3) cost_priorities_3 = itemCost[i] + cost_priorities_3;

		// do while loop start, will continue unless a valid finance option entered.
		do
		{
			// prompt to enter the finance option for the user.
			printf("   Does this item have financing options? [y/n]: ");
			scanf(" %c", &financeOption[i]);

			// if statements starts, checks the condition for the valid finance option.
			if (financeOption[i] != 'y' && financeOption[i] != 'n')
			{
				// if this condition matches then this error message will prompt.
				printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
			}
		} while (financeOption[i] != 'y' && financeOption[i] != 'n'); // do while loop ends here.
		printf("\n");
	}
	printf("\n");

	printf("Item Priority Financed        Cost\n");
	printf("---- -------- -------- -----------\n");

	// for loop starts here to prompt the formated table of the data entered
	for (i = 0; i < wishList; i++)
	{
		printf("%3d  %5d    %5c    %11.2lf"
			"\n", i + 1, itemPriority[i], financeOption[i], itemCost[i]);
	}

	// here it will print the total cost of items.
	printf("---- -------- -------- -----------\n");
	printf("                      $%11.2lf\n\n", totalCost);
	
	// do while starts here, will continue ultil the user input is 0 t quit.
	do
	{
		printf("How do you want to forecast your wish list?\n");
		printf(" 1. All items (no filter)\n");
		printf(" 2. By priority\n");
		printf(" 0. Quit/Exit\n");
		printf("Selection: ");
		scanf("%d", &selection);
		printf("\n");

		// if statements checks if the selection is valid
		if (selection < 0 || selection > 2)
		{
			// if the selection is not valid then print this error message.
			printf("ERROR: Invalid menu selection.\n\n");
		}

		// if else statement checks if the selection is 1.
		else if (selection == 1)
		{
			printf("====================================================\n");
			printf("Filter:   All items\n");
			printf("Amount:   $%1.2lf\n", totalCost);

			// here calculate the total cost based on monthly income and calculate the time into years annd month.
			months = (int) ceil(totalCost / monthlyIncome);
			years = months / 12;
			months = months % 12;
			printf("Forecast: %d years, %d months\n", years, months);

			// for loop, checks if any item was financed or not.
			for (i = 0; i < wishList; i++) {
				if (financeOption[i] == 'y') {
					printf("NOTE: Financing options are available on some items.\n");
					printf("      You can likely reduce the estimated months.\n");
					break;
				}
			}
			
			printf("====================================================\n\n");
		}

		// if else statement checks if the selection is 2.
		else if (selection == 2)
		{
			printf("What priority do you want to filter by? [1-3]: ");
			scanf("%d", &filter_priority);
			
			// Here check the conditions for each item priority if it matches with the priority then it will calculate the total price of all same categories product.
			if (filter_priority == 1) print_by_category = cost_priorities_1;
			if (filter_priority == 2) print_by_category = cost_priorities_2;
			if (filter_priority == 3) print_by_category = cost_priorities_3;

			printf("====================================================\n");
			printf("Filter:   by priority (%d)\n", filter_priority);
			printf("Amount:   $%1.2f\n", print_by_category);

			// here calculate the total cost based on monthly income and calculate the time into years annd month.
			months = (int) ceil(print_by_category / monthlyIncome);
			years = months / 12;
			months = months % 12;
			printf("Forecast: %d years, %d months\n", years, months);
			for (i = 0; i < wishList; i++) {
				if (itemPriority[i] == filter_priority) {
					if (financeOption[i] == 'y') {
						printf("NOTE: Financing options are available on some items.\n");
						printf("      You can likely reduce the estimated months.\n");
						break;
					}

				}
			}
			printf("====================================================\n\n");
		}

		// else if statement checks if the selection is 0
		else if (selection == 0)
		{
			flag = 1;
		}
	} while (flag != 1); // do while ends here.

	// before ending the application, displaying an exit message 
	printf("Best of luck in all your future endeavours!\n");

	return 0;
}
