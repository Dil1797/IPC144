/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #3 (P1)
Full Name   :Dil Humyra Sultana Borna
Student ID# :139166227
Email       :dhsborna@myseneca.ca
Section     :NEE

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS 
#pragma warning(disable:6031)
#include <stdio.h>
#include <ctype.h> //we can use the upper case and lower case with this header file.

int main(void)
{
	// You will need this when converting from grams to pounds (lbs)
	const double GRAMS_IN_LBS = 453.5924;

	// Variable declarations (selecting the appropriate data type and self-describing names):
	char		 coffeeType1;
	int			 weight1;
	char		 withCream1;

	char		 coffeeType2;
	int			 weight2;
	char		 withCream2;

	char		 coffeeType3;
	int			 weight3;
	char		 withCream3;

	//3 preferences
	char		 coffeeStrength;
	int			 dailyServings;
	char		 coffeeWithCream;

	//I recommend to lower()
	//get 3 buyers preferences
	//we have product and preferances, product what they have and preference is what i want.

	//Product data input:
	printf("Take a Break - Coffee Shop\n");
	printf("==========================\n\n");

	printf("Enter the coffee product information being sold today...\n\n");

	//Product 1 (Coffee - 1):
	printf("COFFEE - 1...\n");
	printf("Type ([L]ight, [M]edium, [R]ich): ");
	scanf(" %c", &coffeeType1); //using scanf to user input the Coffee 1 type.
	printf("Bag weight (g): ");
	scanf("%d", &weight1); //using scanf to user input the product 1, Coffee weight.
	printf("Best served with cream ([Y]es, [N]o): ");
	scanf(" %c", &withCream1); //using scanf to user input the product 1, with cream.
	printf("\n\n");

	//Product 2 (Coffee - 2):
	printf("COFFEE - 2...\n");
	printf("Type ([L]ight, [M]edium, [R]ich): ");
	scanf(" %c", &coffeeType2); //using scanf to user input the Coffee 2 type.
	printf("Bag weight (g): ");
	scanf("%d", &weight2); //using scanf to user input the product 2, Coffee weight.
	printf("Best served with cream ([Y]es, [N]o): ");
	scanf(" %c", &withCream2); //using scanf to user input the product 2, with cream.
	printf("\n\n");

	//Product 3 (Coffee - 3):
	printf("COFFEE - 3...\n");
	printf("Type ([L]ight, [M]edium, [R]ich): ");
	scanf(" %c", &coffeeType3); //using scanf to user input the Coffee 3 type.
	printf("Bag weight (g): ");
	scanf("%d", &weight3); //using scanf to user input the product 3, Coffee weight.
	printf("Best served with cream ([Y]es, [N]o): ");
	scanf(" %c", &withCream3); //using scanf to user input the product 3, with cream.
	printf("\n\n");

	//Display product data using logical expressions (in a tabular format):
	printf("---+------------------------+---------------+-------+\n");
	printf("   |	 Coffee             |  Packaged     | Best  |\n");
	printf("   |      Type              | Bag Weight    | Served|\n");
	printf("   +------------------------+---------------+ With  |\n");
	printf("ID | Light | Medium | Rich  | (G) | Lbs     | Cream |\n");
	printf("---+------------------------+---------------+-------|\n");
	printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n",
		coffeeType1 == 'l', 
		coffeeType1 == 'm', 
		coffeeType1 == 'R', 
		weight1, 
		(double) weight1 / GRAMS_IN_LBS, //making the type double as weight is int type.
		withCream1 == 'y');
	printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n",
		coffeeType2 == 'l',
		coffeeType2 == 'm',
		coffeeType2 == 'R',
		weight2,
		(double) weight2 / GRAMS_IN_LBS, //making the type double as weight is int type.
		withCream2 == 'y');
	printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n\n",
		coffeeType3 == 'l',
		coffeeType3 == 'm',
		coffeeType3 == 'R',
		weight3,
		(double) weight3 / GRAMS_IN_LBS, //making the type double as weight is int type.
		withCream3 == 'y');

	// Customer preference input:
	printf("Enter how you like your coffee...\n\n");

	printf("Coffee strength([L]ight, [M]edium, [R]ich) : ");
	scanf(" %c", &coffeeStrength); // using scanf to user input customer's coffee strength.
	printf("Do you like your coffee with cream([Y]es, [N]o) : ");
	scanf(" %c", &coffeeWithCream); // using scanf to user input customer's coffee with cream.
	printf("Typical number of daily servings : ");
	scanf("%d", &dailyServings); // using scanf to user input customer's daily serving coffee.
	printf("\n\n");

	// Display summary of results using logical expressions (tabular format): 
	printf("The below table shows how your preferences align to the available products:\n\n");

	printf("--------------------+-------------+-------+\n");
	printf("  |      Coffee     |  Packaged   | With  |\n");
	printf("ID|       Type      | Bag Weight  | Cream |\n");
	printf("--+-----------------+-------------+-------+\n");
	printf(" 1|       %d         |      %d      |   %d   |\n",
		(coffeeStrength == 'L' && coffeeType1 == 'l'), //for large coffee
		(dailyServings >= 1 && dailyServings <= 4 && weight1),
		coffeeWithCream == withCream1);

	printf(" 2|       %d         |      %d      |   %d   |\n",
		(coffeeStrength == 'R' && coffeeType2 == 'r'), //For rich coffee
		dailyServings >= 10 && weight2,
		coffeeWithCream == withCream2);

	printf(" 3|       %d         |      %d      |   %d   |\n\n",
		(coffeeStrength == 'M' && coffeeType3 == 'm'), //For medium coffee
		(dailyServings >= 5 && dailyServings <= 9) && weight3,
		coffeeWithCream == withCream3);

	// Repeat (Customer preference input):
	printf("Enter how you like your coffee...\n\n");

	printf("Coffee strength([L]ight, [M]edium, [R]ich) : ");
	scanf(" %c", &coffeeStrength); // using scanf to user input customer's coffee strength.
	printf("Do you like your coffee with cream([Y]es, [N]o) : ");
	scanf(" %c", &coffeeWithCream); // using scanf to user input customer's coffee with cream.
	printf("Typical number of daily servings : ");
	scanf("%d", &dailyServings); // using scanf to user input customer's daily serving coffee.
	printf("\n\n");

	printf("The below table shows how your preferences align to the available products :\n\n");

	// Repeat (Display summary of results using logical expressions): 
	printf("--------------------+-------------+-------+\n");
	printf("  |      Coffee     |  Packaged   | With  |\n");
	printf("ID|       Type      | Bag Weight  | Cream |\n");
	printf("--+-----------------+-------------+-------+\n");
	printf(" 1|       %d         |      %d      |   %d   |\n",
		(coffeeStrength == 'L' && coffeeType1 == 'l'), //Large Coffee
		(dailyServings >= 1 && dailyServings <= 4),
		coffeeWithCream == withCream1);

	printf(" 2|       %d         |      %d      |   %d   |\n",
		(coffeeStrength == 'R' && coffeeType2 == 'r'), //Rich coffee
		(dailyServings >= 5 && dailyServings <= 9),	
		coffeeWithCream == withCream3);

	printf(" 3|       %d         |      %d      |   %d   |\n\n",
		(coffeeStrength == 'M' && coffeeType3 == 'm'),
		dailyServings >= 10,		
		coffeeWithCream == withCream3); //Medium coffee

	printf("Hope you found a product that suits your likes!\n");

	return 0;

}


/*

Provided formatting parts for printf statements:

As described in step-7
======================
printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n",

As described in step-10
=======================
printf(" 1|       %d         |      %d      |   %d   |\n",

*/