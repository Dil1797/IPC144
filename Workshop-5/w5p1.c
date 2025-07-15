#define _CRT_SECURE_NO_WARNINGS 
#pragma warning(disable:6031)
#include <stdio.h>

//  defining two (2) macros:
#define MIN_YEAR 2012
#define MAX_YEAR 2022

int main(void)
{
	// declaring and initializing two unmodifiable integer variables “JAN = 1” and “DEC = 12”.
	const int JAN = 1;
	const int DEC = 12;

	// declaring and initializing two integer variables "year = 0" and "month = 0".
	int year = 0;
	int month = 0;

	// Displaying the title for the well - being log application.
	printf("General dhiki Well-being Log\n");
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
			printf("   ERROR: The year must be between 2012 and 2022 inclusive\n");
		}
		// starting if statement, it checks if the month matches.
		if (month < JAN || month > DEC)
		{
			//if the month doesnt match then will print this error message.
			printf("   ERROR: Jan.(1) - Dec.(12)\n");
		}
		// else if statement starts, checks if the year and month matches,
		else if ((year >= MIN_YEAR && year <= MAX_YEAR) && (month >= JAN && month <= DEC))
		{
			printf("\n");
			//if the condiion matches then this message will print
			printf("*** Log date set! ***\n\n");
			break;
		}		
	} while (1); // end of while loop, will continue to iterate until a valid year and month value is entered 

	//  map the month integer value to the respective 3 character month representation, using switch break.
	switch (month)
	{
		// this case is for 1st month, if the user input is 1 then this message will print for JAN month.
	case 1 :
		printf("Log starting date: %4d-JAN-01", year);
		break; // if the condition macthes then here the switch break will stop.

		// this case is for 2nd month, if the user input is 2 then this message will print for FEB month.
	case 2 :
		printf("Log starting date: %4d-FEB-01", year);
		break; // if the condition macthes then here the switch break will stop.

		// this case is for 3rd month, if the user input is 3 then this message will print for MAR month.
	case 3:
		printf("Log starting date: %4d-MAR-01", year);
		break; // if the condition macthes then here the switch break will stop.

		// this case is for 4th month, if the user input is 4 then this message will print for APR month.
	case 4 :
		printf("Log starting date: %4d-APR-01", year);
		break; // if the condition macthes then here the switch break will stop.

		// this case is for 5th month, if the user input is 5 then this message will print for MAY month.
	case 5 :
		printf("Log starting date: %4d-MAY-01", year);
		break; // if the condition macthes then here the switch break will stop.

		// this case is for 6th month, if the user input is 6 then this message will print for JUN month.
	case 6 :
		printf("Log starting date: %4d-JUN-01", year);
		break; // if the condition macthes then here the switch break will stop.

		// this case is for 7th month, if the user input is 7 then this message will print for JUL month.
	case 7 :
		printf("Log starting date: %4d-JUL-01", year);
		break; // if the condition macthes then here the switch break will stop.

		// this case is for 8th month, if the user input is 8 then this message will print for AUG month.
	case 8 :
		printf("Log starting date: %4d-AUG-01", year);
		break; // if the condition macthes then here the switch break will stop.

		// this case is for 9th month, if the user input is 9 then this message will print for SEP month.
	case 9:
		printf("Log starting date: %4d-SEP-01", year);
		break; // if the condition macthes then here the switch break will stop.

		// this case is for 10th month, if the user input is 1 then this message will print for OCT month.
	case 10:
		printf("Log starting date: %4d-OCT-01", year);
		break; // if the condition macthes then here the switch break will stop.

		// this case is for 11th month, if the user input is 1 then this message will print for NOV month.
	case 11:
		printf("Log starting date: %4d-NOV-01", year);
		break; // if the condition macthes then here the switch break will stop.

		// this case is for 12th month, if the user input is 1 then this message will print for DEC month.
	case 12:
		printf("Log starting date: %4d-DEC-01", year);
		break; // if the condition macthes then here the switch break will stop.
	}

	return 0;
}
