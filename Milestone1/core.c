/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 1
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

// These sizes include null terminator
#define CH_ARRAY_SIZE 6 
#define USER_STR_SIZE 7

#include<stdio.h>
#include "core.h"

// Clear the standard input buffer 
void clearInputBuffer(void)
{ // Discard all remaining char's from the standard input buffer: 
    while (getchar() != '\n')
    {
        ; // do nothing! 
    }
}

// Wait for user to input the "enter" key to continue 
void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}

// To accept an integer input from user
int inputInt(void) {
    int intgr;
    char newLine = 'x';

    do
    {
        scanf("%d%c", &intgr, &newLine);
        if (newLine != '\n')
        {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }

    } while (newLine != '\n');

    return intgr;
}

// Test-1, Test-2
// To accept a positive integer from user
int inputIntPositive(void) {
    int posInt;
    char newLine = 'x';

    do
    {
        scanf("%d%c", &posInt, &newLine);
        if (newLine != '\n')
        {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }
        if (posInt <= 0)
        {
            printf("ERROR! Value must be > 0: ");
        }
    } while (newLine != '\n' || posInt <= 0);

    return posInt;
}

// Test-3, Test-4
int inputIntRange(int lowerBound, int upperBound)
{
    int value;
    char newLine = 'x';
    do
    {
        scanf("%d%c", &value, &newLine);
        if (newLine != '\n')
        {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }
        else if (value < lowerBound || value > upperBound)
        {
            printf("ERROR! Value must be between -3 and 11 inclusive: ");
        }
    } while ((newLine != '\n') || (value < lowerBound || value > upperBound));

    return value;
}

// Test-5
char inputCharOption(char validChars[]) {

    char input;
    int i, c = 0;

    do
    {
        scanf(" %c", &input);
        for (i = 0; i != CH_ARRAY_SIZE; i++)
        {
            if (input == validChars[i])
            {
                c++;
            }
        }
        if (c == 0)
        {
            printf("ERROR: Character must be one of [qwErty]: ");
        }

    } while (c == 0);

    clearInputBuffer();
    return input;
}

// Test-6, Test-7, Test-8
void inputCString(char Cstring[], int min, int max)
{
    int flag = 1;
    char ch = 'x';

    do
    {
        int len = 0;
        // Takes a string as input until it sees a newline character
        while (ch != '\n' && len <= max)
        {
            ch = getchar();
            Cstring[len] = ch;
            len++;
        };

        // If the string is less than or equal to the maximum chars, add '\0' to the end of string
        if (ch == '\n' && len <= (max + 1))
        {
            len--;
            Cstring[len] = '\0';
        }
        // If length is more than maximum chars,  add '\0' to the end
        // Also clear input buffer
        else
        {
            Cstring[max] = '\0';
            clearInputBuffer();
        }

        if (min == max && len != min)
        {
            printf("ERROR: String length must be exactly %d chars: ", min);
            ch = 'x';
        }
        else if (len < min || len > max)
        {
            if (len > max)
            {
                printf("ERROR: String length must be no more than %d chars: ",
                    max);
                ch = 'x';
            }
            else if (len < min)
            {
                printf("ERROR: String length must be between %d and %d"
                    " chars: ", min, max);
                ch = 'x';
            }
        }
        else
        {
            flag = 0;
        }
    } while (flag == 1);
}

// Test - 9
// To display an array of 10-character digits as a formatted phone number
void displayFormattedPhone(const char* phoneNumber) {

    int len = 0;
    int flag = 0;

    if (phoneNumber != NULL)
    {
        for (len = 0; phoneNumber[len] != '\0'; len++)
        {
            if (phoneNumber[len] < '0' || phoneNumber[len] > '9')
            {
                flag = 1;
            }
        }
        if (len != 10)
        {
            flag = 1;
        }
        if (flag == 1)
        {
            printf("(___)___-____");
        }
        else
        {
            printf("(%c%c%c)%c%c%c-%c%c%c%c", 
                phoneNumber[0], 
                phoneNumber[1], 
                phoneNumber[2],
                phoneNumber[3],
                phoneNumber[4],
                phoneNumber[5],
                phoneNumber[6],
                phoneNumber[7],
                phoneNumber[8],
                phoneNumber[9]);
        }
    }
    else
    {
        printf("(___)___-____");
    }
}