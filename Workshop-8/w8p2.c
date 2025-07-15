/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #8 (P2)
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
#include "w8p2.h"

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
			printf("ERROR: Enter a positive value: ");
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

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)

double convertLbsKg(const double* lbs, double* resultInKg)
{
	double result = *lbs / POUND_TO_KG;

	//checks if the pointer is NULL.
	if (resultInKg != NULL)
	{
		*resultInKg = result;
	}

	return result;
}

// 9. convert lbs: g (call convertKG, then * 1000)

int convertLbsG(const double* lbs, int* resultInGrams)
{
	//calculation of convertiong to kg
	int result = convertLbsKg(lbs, NULL) * 1000;

	//checks if the pointer is NULL.
	if (resultInGrams != NULL)
	{
		*resultInGrams = result;
	}

	return result;
}


// 10. convert lbs: kg and g

void convertLbs(const double* lbs, double* resultInKg, int* resultInGrams)
{
	convertLbsKg(lbs, resultInKg);
	convertLbsG(lbs, resultInGrams);

}

// 11. calculate: servings based on gPerServ

double calculateServings(const int servingSizeGrams, 
	int totalGrams, double* numOfServings)
{
	double report = (double)totalGrams / servingSizeGrams;

	//checks if the pointer is NULL.
	if (numOfServings != NULL)
	{
		*numOfServings = report;
	}

	return report;
}

// 12. calculate: cost per serving

double calculateCostPerServing(const double* price, 
	double* numOfServings, double* result)
{
	double report = *price / *numOfServings;

	//checks if the pointer is NULL.
	if (result != NULL)
	{
		*result = report;
	}

	return report;
}

// 13. calculate: cost per calorie

double calculateCostPerCal(const double* price, 
	double* calories, double* result)
{
	double report = *price / *calories;

	//checks if the pointer is NULL.
	if (result != NULL)
	{
		*result = report;
	}

	return report;
}

// 14. Derive a reporting detail record based on the cat food product data

ReportData detailedReportData(const CatFoodInfo report, ReportData* result)
{
	// Create a local ReportData object
	ReportData rpData;

	// Copy relevant information from the CatFoodInfo object to the ReportData object
	rpData.sku = report.sku;
	rpData.price = report.proPrice;
	rpData.caloriesPerServing = report.calPerServing;
	rpData.weightPounds = report.proWeight;

	// Convert weight from pounds to kilograms and grams
	rpData.weightKilograms = convertLbsKg(&report.proWeight, NULL);
	rpData.weightGrams = convertLbsG(&report.proWeight, NULL);

	// Calculate total servings based on weight in grams
	rpData.totalServings = calculateServings
	(NUMBER_GRAMS, rpData.weightGrams, NULL);

	// Calculate total calories based on total servings
	double totalCalories = rpData.totalServings * rpData.caloriesPerServing;

	// Calculate cost per serving and cost per calorie
	rpData.costPerServing = calculateCostPerServing
	(&report.proPrice, &rpData.totalServings, NULL);
	rpData.costcaloriesPerServing = calculateCostPerCal
	(&report.proPrice, &totalCalories, NULL);

	//checks if the pointer is NULL.
	if (result != NULL)
	{
		*result = rpData;
	}

	// Return the generated detailed report data
	return rpData;
}

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	printf("Analysis Report (Note: Serving = %dg)\n", NUMBER_GRAMS);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g"
		" Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- ---------"
		" -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table

void displayReportData(const ReportData report, const int cheapestProduct)
{
	// Print formatted report data
	printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf",
		report.sku, report.price, report.weightPounds, report.weightKilograms,
		report.weightGrams, report.caloriesPerServing, report.totalServings,
		report.costPerServing, report.costcaloriesPerServing);

	// Check if the product is the cheapest and add an indicator if necessary
	if (cheapestProduct < 1)
	{
		printf(" ***"); // Indicate cheapest product
	}

	// Print newline character to end the line
	printf("\n");
}

// 17. Display the findings (cheapest)

void displayFinalAnalysis(const CatFoodInfo report)
{
	printf("Final Analysis\n");
	printf("--------------\n");
	printf("Based on the comparison data, the PURRR-fect economical"
		" option is:\n");
	printf("SKU:%07d Price: $%4.2lf\n\n", report.sku, report.proPrice);
	printf("Happy shopping!\n");
}

// ----------------------------------------------------------------------------

// 7. Logic entry point
void start(void)
{
	int i;

	CatFoodInfo info[MAX_PRODUCTS] = { {0} };   // Array to store cat food product information

	openingMessage(MAX_PRODUCTS);    // Display opening message indicating the number of products

	// Loop to prompt user for data for each cat food product
	for (i = 0; i < MAX_PRODUCTS; i++)
	{
		info[i] = getCatFoodInfo(i + 1);  // Call getCatFoodInfo to get product data
	}

	displayCatFoodHeader();  // Display header for the table

	// Loop to display data for each cat food product in a formatted table
	for (i = 0; i < MAX_PRODUCTS; i++)
	{
		// Display basic information for each cat food product
		displayCatFoodData(info[i].sku, &info[i].proPrice,
			info[i].calPerServing, &info[i].proWeight);
	}
	printf("\n");

	// Display header for the detailed report data
	displayReportHeader();

	// Loop to generate and display detailed report data for each cat food product
	for (i = 0; i < MAX_PRODUCTS; i++)
	{
		// Generate detailed report data for the current cat food product
		ReportData report = detailedReportData(info[i], NULL);

		// Display detailed report data for the current cat food product
	// Also pass the cost per serving for potential cheapest product indication
		displayReportData(report, report.costPerServing);
	}

	printf("\n");

	// Display final analysis based on the data of a specific cat food product (info[1])
	displayFinalAnalysis(info[1]);
}

