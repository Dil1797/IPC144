/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #5 (P2)
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
#include <stdlib.h>

//  defining two (3) macros for minimum and maximum year log.
#define MIN_YEAR 2012
#define MAX_YEAR 2022

// defining the maximum days(3) of data to collect from the user
#define LOG_DAYS 3

int main(void)
{
	// declaring and initializing two unmodifiable integer variables “JAN = 1” and “DEC = 12”.
	const int JAN = 1;
	const int DEC = 12;

	// declaring and initializing 3 integer variables for the log date.
	int year = 0;
	int month = 0;
	int date = 0;

	// declaring two double floating-point user input values that represent a morning and an evening self - diagnosis rating value.
	double morning;
	double evening;

	// declaring and initializing 3 variables to sum the morning, evening and the combined self-diagnosis rating value.
	double sumMorning = 0.0;
	double sumEvening = 0.0;
	double sumCombined = 0.0;

	// declaring 3 variables to average the morning, evening and the combined self-diagnosis rating value.
	double averageMorning;
	double averageEvening;
	double averageCombined;

	// Displaying the title for the well - being log application.
	printf("General Well-being Log\n");
	printf("======================\n");

	// starting of do while loop, this loop will continue unless the user input valid time.
	do
	{
		printf("Set the year and month for the well-being log (YYYY MM): ");
		scanf("%d %d", &year, &month); // using scanf to user input for year and month.

		// starting if statement, it checks if the year matches.
		if (year < MIN_YEAR || year > MAX_YEAR)
		{
			//if the year doesnt match then will print this error message.
			printf("   ERROR: The year must be between 2012 and "
				"2022 inclusive\n");
		}
		// starting if statement, it checks if the month matches.
		if (month < JAN || month > DEC)
		{
			//if the month doesnt match then will print this error message.
			printf("   ERROR: Jan.(1) - Dec.(12)\n");
		}
		// else if statement starts, checks if the year and month matches,
		else if ((year >= MIN_YEAR && year <= MAX_YEAR) &&
			(month >= JAN && month <= DEC))
		{
			printf("\n");
			//if the condiion matches then this message will print
			printf("*** Log date set! ***\n\n");
			break;
		}
	} while (1); // end of while loop, will continue to iterate until a valid year and month value is entered 


	// starting the for loop, this loop will continue till the LOG_DAYS is 3 as this is the maximum value.
	for (date = 1; date <= LOG_DAYS; date++)
	{
		//  map the month integer value to the respective 3 character month representation, using switch break.
		switch (month)
		{
			// this case is for 1st month, as the date starts with 1st day, this message will print for JAN month date and will contnue to change the date as the for loop continues untill it matches the date condition. this will happen with all the months from JAN to DEC.
		case 1:
			printf("%4d-JAN-0%d", year, date);
			break; // if the condition macthes then here the switch break will stop.

		case 2:
			printf("%4d-FEB-0%d", year, date);
			break;

		case 3:
			printf("%4d-MAR-%d", year, date);
			break;

		case 4:
			printf("%4d-APR-%d", year, date);
			break;

		case 5:
			printf("%4d-MAY-%d", year, date);
			break;

		case 6:
			printf("%4d-JUN-%d", year, date);
			break;

		case 7:
			printf("%4d-JUL-%d", year, date);
			break;

		case 8:
			printf("%4d-AUG-%d", year, date);
			break;

		case 9:
			printf("%4d-SEP-%d", year, date);
			break;

		case 10:
			printf("%4d-OCT-%d", year, date);
			break;

		case 11:
			printf("%4d-NOV-%d", year, date);
			break;

		case 12:
			printf("%4d-DEC-%d", year, date);
			break;
		} // here the switch break ends.
		printf("\n");

		// using the scanf to enter the user input for the morning log
		printf("   Morning rating (0.0-5.0): ");
		scanf("%lf", &morning);

		// starting while loop (nesting), this loop will continue until the log value matched with the while condition for the morning value.
		while (morning < 0.00 || morning > 5.00)
		{
			// if the user input is unvalid then this error message will display.
			printf("      ERROR: Rating must be between 0.0 and 5.0"
				"inclusive!\n");
			printf("   Morning rating (0.0-5.0): ");
			scanf("%lf", &morning);
		}

		// calculation of the sum of the morning logs of total days, this value will be updated as the for loop and the while loop continues.
		sumMorning = morning + sumMorning;

		// using the scanf to enter the user input for the evening log
		printf("   Evening rating (0.0-5.0): ");
		scanf("%lf", &evening);

		// starting while loop (nesting), this loop will continue until the log value matched with the while condition for the evening values.
		while (evening < 0.00 || evening > 5.00)
		{
			// if the user input is unvalid then this error message will display.
			printf("      ERROR: Rating must be between 0.0 and 5.0"
				"inclusive!\n");
			printf("   Evening rating (0.0-5.0): ");
			scanf("%lf", &evening);
		}
		printf("\n");

		// calculation of the sum of the evening logs of total days, this value will be updated as the for loop and the while loop continues.
		sumEvening = evening + sumEvening;
	}

	// calculation of the sum of the combined log
	sumCombined = sumMorning + sumEvening;

	// calculation of the average log of the total morning log.
	averageMorning = sumMorning / LOG_DAYS;

	// calculation of the average log of the total morning log.
	averageEvening = sumEvening / LOG_DAYS;

	// calculation of the average combined log of the total morning and total evening log.
	averageCombined = ((averageMorning + averageEvening) / 2);

	printf("\n");
	printf("Summary\n");
	printf("=======\n");

	// displaying all sums to 3-decimal precision points.
	printf("Morning total rating: %.3lf\n", sumMorning);
	printf("Evening total rating:  %.3lf\n", sumEvening);
	printf("----------------------------\n");
	printf("Overall total rating: %.3lf\n\n", sumCombined);

	// Displaying all averages to 1-decimal precision point 
	printf("Average morning rating: %.1lf\n", averageMorning);
	printf("Average evening rating: %.1lf\n", averageEvening);
	printf("----------------------------\n");
	printf("Average overall rating: %.1lf\n", averageCombined);

	return 0;
}