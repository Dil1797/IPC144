/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #4 (P1)
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

int main(void)
{
    // Declaring 2 int type and 1 char type variables.
    int  numberOfIteration;
    int  counter;
    char loop_type;

    printf("+----------------------+\n");
    printf("Loop application STARTED\n");
    printf("+----------------------+\n\n");

    // starting a do while loop, this loop will continue until user input 'Q0" to quit.
    do {
        printf("D = do / while | W = while | F = for | Q = quit\n");
        printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
        scanf(" %c%d", &loop_type, &numberOfIteration); // receiveing user input for 1 char type and 1 int type values using a single scanf function call.

        // Starting if statement, this checks if the char is 'D' or 'F' or 'W'.
        if (loop_type == 'D' || loop_type == 'F' || loop_type == 'W')
        {
            // if the letter maches then it will check if the numbers are within range.
            if (numberOfIteration >= 3 && numberOfIteration <= 20)
            {
                // if the number is within range then it check if the char is 'D'.
                if (loop_type == 'D')
                {
                    //if the char is 'D' then this do while loop will continue.
                    printf("DO-WHILE: ");  
                    do {                  
                        printf("%c", loop_type);
                        numberOfIteration --; // the number will decrease here.
                    } while (numberOfIteration > 0);
                    printf("\n\n");
                }
                //else if statement starts here, if the char is not 'D', it checks if its 'W'
                else if (loop_type == 'W')
                {
                    // if the char is 'W' this while loop will continue.
                    printf("WHILE   : ");
                    while (numberOfIteration > 0)
                    {
                        printf("%c", loop_type);
                        numberOfIteration--; //here the number will decrease.
                   }
                    printf("\n\n");
                }
                // if the char is not 'D' and 'W', then its 'F'. Here else statements starts 
                else
                {
                    printf("FOR     : ");
                    // if the letter is not 'W' and 'F' then this for loop will continue.
                    for (counter = 0; counter < numberOfIteration; counter++)
                    {
                        printf("%c", loop_type);
                    }
                    printf("\n\n");
                }
            }
            // if the number isnt within the range then this else statement will print the error.
            else printf("ERROR: The number of iterations must be between 3-20 inclusive! \n\n");
        }
        // if the letters doesnt matche and the number range doesnt match, then this else statement is true.
        else
        {
            // here if statement starts and it checks if the letter is 'Q'
            if (loop_type == 'Q')
            {
                // if the letter is 'Q' then this if Checks Q's number. if its not 0 then the error prints.
                if (numberOfIteration != 0)
                {
                    printf("ERROR: To quit, the number of iterations should be 0!\n\n");
                }
                // else the code stopped here as the nunber and the letter matches to quit, which s "Q0"
                else break;
            }
            //if the letters doesnt matches to 'D' or 'W' or 'F' then this error prints.
            else printf("ERROR: Invalid entered value(s)! \n\n");
        }
    } while (1);

    printf("\n\n");
    printf("+--------------------+\n");
    printf("Loop application ENDED\n");
    printf("+--------------------+\n");

    return 0;
}
