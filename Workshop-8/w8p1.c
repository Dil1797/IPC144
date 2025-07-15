/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #8 (P1)
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

// System Libraries
#include <stdio.h>

// User Libraries
#include "w8p1.h"

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* intPointer)
{
	int userInput;

	do
	{
		// Keep prompting until a positive integer is entered
		scanf("%d", &userInput);

		// Check if the entered value is positive
		if (userInput <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
	} while (userInput <= 0);

	//checks if the pointer is null.
	if (intPointer != NULL)
	{
		//assigned the value to the pointer if its not null.
		*intPointer = userInput;
	}

	//return the userInput
	return userInput;
}

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* doublePointer)
{
	double userInput;

	do
	{
		// Keep prompting until a positive double float point is entered
		scanf("%lf", &userInput);

		// Check if the entered value is positive
		if (userInput <= 0)
		{
			printf("ERROR: Enter a positive value : ");
		}		

	} while (userInput <= 0);

	//checks if the pointer is null.
	if (doublePointer != 0)
	{
		//assigned the value to the pointer if its not null.
		*doublePointer = userInput;
	}

	return userInput;
}

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int numProducts)
{
	printf("Cat Food Cost Analysis\n");
	printf("======================\n\n");
	printf("Enter the details for %d dry food bags of product data for"
		" analysis.\n", MAX_PRODUCTS);
	printf("NOTE: A 'serving' is %dg\n\n", NUMBER_GRAMS);

	return;
}

// 4. Get user input for the details of cat food product
CatFoodInfo getCatFoodInfo(const int proSequenceNum)
{
	//declaring structure
	CatFoodInfo info;

	printf("Cat Food Product #%d\n", proSequenceNum);
	printf("--------------------\n");

	//sku information
	printf("SKU           : ");
	getIntPositive(&info.sku);

	//price information
	printf("PRICE         : $");
	getDoublePositive(&info.proPrice);

	//weight information
	printf("WEIGHT (LBS)  : ");
	getDoublePositive(&info.proWeight);

	//calories information
	printf("CALORIES/SERV.: ");
	getIntPositive(&info.calPerServing);

	printf("\n");

		return info;
}

// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int sku, const double* proPrice, 
	const int calPerServing, const double* proWeight)
{
	printf("%07d %10.2lf %10.1lf %8d\n", sku, *proPrice,
		*proWeight, calPerServing);
}

// 7. Logic entry point
void start(void)
{
	int i;
	CatFoodInfo info[MAX_PRODUCTS] = { {0} };  // Array to store cat food product information
	openingMessage(MAX_PRODUCTS);  // Display opening message indicating the number of products

	// Loop to prompt user for data for each cat food product
	for (i = 0; i < MAX_PRODUCTS; i++)
	{
		info[i] = getCatFoodInfo(i + 1); // Call getCatFoodInfo to get product data
	}

	displayCatFoodHeader(); // Display header for the table

	// Loop to display data for each cat food product in a formatted table
	for (i = 0; i < MAX_PRODUCTS; i++)
	{
		displayCatFoodData(info[i].sku, &info[i].proPrice,
			info[i].calPerServing, &info[i].proWeight);
	}
}
