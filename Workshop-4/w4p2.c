/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #4 (P2)
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
    //declaring variables where the value will be stored that needs to be shopped.
    int apples;
    int oranges;
    int pears;
    int tomatoes;
    int cabbages;

    //declaring the variable where the picking values will be stored
    int pick;

    //declaring variable for keep going to shop or not.
    int yesNo;

    printf("Grocery Shopping\n");
    printf("================\n");

    // Started the do while loop for selecting the value of apples that needs to be shopped
    do {
        printf("How many APPLES do you need? : ");
        scanf("%d", &apples); //entered the value using the scanf.

        // Here if statement starts, that checks if the value is less than 0.
        if (apples < 0)
        {
            printf("ERROR: Value must be 0 or more.\n"); //if the value is less than 0 then this error message will print.
        }
    } while (apples < 0); // while loop will continued unless the entered value is less than 0.
    printf("\n");

    // Started the do while loop for selecting the value of oranges that needs to be shopped
    do {
        printf("How many ORANGES do you need? : ");
        scanf("%d", &oranges); //entered the value using the scanf.

        // Here if statement starts, that checks if the value is less than 0.
        if (oranges < 0)
        {
            printf("ERROR: Value must be 0 or more.\n"); //if the value is less than 0 then this error message will print.
        }
    } while (oranges < 0); // while loop will continued unless the entered value is less than 0.
    printf("\n");

    // Started the do while loop for selecting the value of pears that needs to be shopped
    do {
        printf("How many PEARS do you need? : ");
        scanf("%d", &pears); //entered the value using the scanf.

        // Here if statement starts, that checks if the value is less than 0.
        if (pears < 0)
        {
            printf("ERROR: Value must be 0 or more.\n"); //if the value is less than 0 then this error message will print.
        }
    } while (pears < 0); // while loop will continued unless the entered value is less than 0.
    printf("\n");

    // Started the do while loop for selecting the value of tomatoes that needs to be shopped
    do {
        printf("How many TOMATOES do you need? : ");
        scanf("%d", &tomatoes); //entered the value using the scanf.

        // Here if statement starts, that checks if the value is less than 0.
        if (tomatoes < 0)
        {
            printf("ERROR: Value must be 0 or more.\n"); //if the value is less than 0 then this error message will print.
        }
    } while (tomatoes < 0); // while loop will continued unless the entered value is less than 0.
    printf("\n");

    // Started the do while loop for selecting the value of cabbages that needs to be shopped
    do {
        printf("How many CABBAGES do you need? : ");
        scanf("%d", &cabbages); //entered the value using the scanf.

        // Here if statement starts, that checks if the value is less than 0.
        if (cabbages < 0)
        {
            printf("ERROR: Value must be 0 or more.\n"); //if the value is less than 0 then this error message will print.
        }
    } while (cabbages < 0); // while loop will continued unless the entered value is less than 0.
    printf("\n\n");

    printf("--------------------------\n");
    printf("Time to pick the products!\n");
    printf("--------------------------\n\n");

    //do while starts to pick the correct amount.
    do {
        printf("Pick some APPLES... how many did you pick? : ");
        scanf("%d", &pick); //entered the picking value using scanf

        // if statement starts, checks if the picking value is less then or equal to 0.
        if (pick <= 0)
        {
            printf("ERROR: You must pick at least 1!\n"); // will print this error message if the "if statement" is true.
        }
        // else if statement starts, if the "if statement" is not true then check if the picking value is more than needs to be shopped value.
        else if (pick > apples)
        {
            printf("You picked too many... only %d more APPLE(S) are needed.\n", apples); // if the "else if statement" is true then this message will be printed.
        }
        // else if statement starts, if the previous conditions/statements are not true then checks if the picking value is less than needs to be shopped value.
        else if (pick < apples)
        {
            printf("Looks like we still need some APPLES...\n"); //if its true then, will print this message, that need to pick more.
            apples = apples - pick; // calculate the remaining value that needs to be picked more to make the correct amount to shop.
        }
        // else statement starts, if no conditions/statements are true then checks this statement.
        else
        {
            apples = apples - pick; // calculate the remaining value that needs to be picked more to make the correct amount to shop. if no need to pick more then will print the message and will check the while condition.
            printf("Great, that's the apples done!");
        }
    } while (apples != 0); //check the while condition, this loop will continue unless the valus is not 0.
    printf("\n\n");

    //do while starts to pick the correct amount.
    do {
        printf("Pick some PEARS... how many did you pick? : ");
        scanf("%d", &pick); //entered the picking value using scanf

        // if statement starts, checks if the picking value is less then or equal to 0.
        if (pick <= 0)
        {
            printf("ERROR: You must pick at least 1!\n"); // will print this error message if the "if statement" is true.
        }
        // else if statement starts, if the "if statement" is not true then check if the picking value is more than needs to be shopped value.
        else if (pick > pears)
        {
            printf("You picked too many... only %d more PEAR(S) are needed.\n", pears); // if the "else if statement" is true then this message will be printed.
        }
        // else if statement starts, if the previous conditions/statements are not true then checks if the picking value is less than needs to be shopped value.
        else if (pick < pears)
        {
            printf("Looks like we still need some PEARS...\n"); //if its true then, will print this message, that need to pick more.
            pears = pears - pick; // calculate the remaining value that needs to be picked more to make the correct amount to shop.
        }
        // else statement starts, if no conditions/statements are true then checks this statement.
        else
        {
            pears = pears - pick; // calculate the remaining value that needs to be picked more to make the correct amount to shop. if no need to pick more then will print the message and will check the while condition.
            printf("Great, that's the pears done!");
        }
    } while (pears != 0); //check the while condition, this loop will continue unless the valus is not 0.
    printf("\n\n");

    //do while starts to pick the correct amount.
    do {
        printf("Pick some CABBAGES... how many did you pick? : ");
        scanf("%d", &pick); //entered the picking value using scanf

        // if statement starts, checks if the picking value is less then or equal to 0.
        if (pick <= 0)
        {
            printf("ERROR: You must pick at least 1!\n"); // will print this error message if the "if statement" is true.
        }
        // else if statement starts, if the "if statement" is not true then check if the picking value is more than needs to be shopped value.
        else if (pick > cabbages)
        {
            printf("You picked too many... only %d more CABBAGE(S) are needed.\n", cabbages); // if the "else if statement" is true then this message will be printed.
        }
        // else if statement starts, if the previous conditions/statements are not true then checks if the picking value is less than needs to be shopped value.
        else if (pick < cabbages)
        {
            printf("Looks like we still need some CABBAGES...\n"); //if its true then, will print this message, that need to pick more.
            cabbages = cabbages - pick; // calculate the remaining value that needs to be picked more to make the correct amount to shop.
        }
        // else statement starts, if no conditions/statements are true then checks this statement.
        else
        {
            cabbages = cabbages - pick; // calculate the remaining value that needs to be picked more to make the correct amount to shop. if no need to pick more then will print the message and will check the while condition.
            printf("Great, that's the cabbages done!");
        }
    } while (cabbages != 0); //check the while condition, this loop will continue unless the valus is not 0.
    printf("\n\n");

    printf("All the items are picked!\n\n");

    // do while loop starts
    do
    {
        printf("Do another shopping? (0=NO): ");
        scanf("%d", &yesNo); // using scanf to enter the value of shopping more.
        printf("\n");

        // if statements starts here. Here checks if the keep gping shop variables value is equal to 0.
        if (yesNo == 0)
        {
            printf("Your tasks are done for today - enjoy your free time!\n"); // if the value is 0 then this mmessage wil print.
        }
        //else statements starts, if the value is not 0 then will entered to this else statement. need to entered the value that wants to shop
        else
        {
            printf("Grocery Shopping\n");
            printf("================\n");

            printf("How many APPLES do you need? : ");
            scanf("%d", &apples); //entered the value using the scanf.
            printf("\n");

            printf("How many ORANGES do you need? : "); 
            scanf("%d", &oranges); //entered the value using the scanf.
            printf("\n");
            
            printf("How many PEARS do you need? : ");
            scanf("%d", &pears); //entered the value using the scanf.
            printf("\n");

            printf("How many TOMATOES do you need? : ");
            scanf("%d", &tomatoes); //entered the value using the scanf.
            printf("\n");
            
            printf("How many CABBAGES do you need? : ");
            scanf("%d", &cabbages); //entered the value using the scanf.
            printf("\n");

            printf("--------------------------\n");
            printf("Time to pick the products!\n");
            printf("--------------------------\n\n");

            //do while starts to pick the correct amount.
            do {
                printf("Pick some ORANGES... how many did you pick? : ");
                scanf("%d", &pick); //entered the picking value using scanf

                // if statement starts, checks if the picking value is less then or equal to 0.
                if (pick <= 0)
                {
                    printf("ERROR: You must pick at least 1!\n"); // will print this error message if the "if statement" is true.
                }
                // else if statement starts, if the "if statement" is not true then check if the picking value is more than needs to be shopped value.
                else if (pick > oranges)
                {
                    printf("You picked too many... only %d more ORANGE(S) are needed.\n", oranges); // if the "else if statement" is true then this message will be printed.
                }
                // else if statement starts, if the previous conditions/statements are not true then checks if the picking value is less than needs to be shopped value.
                else if (pick < oranges)
                {
                    printf("Looks like we still need some ORANGES...\n"); //if its true then, will print this message, that need to pick more.
                    oranges = oranges - pick; // calculate the remaining value that needs to be picked more to make the correct amount to shop.
                }
                // else statement starts, if no conditions/statements are true then checks this statement.
                else
                {
                    oranges = oranges - pick; // calculate the remaining value that needs to be picked more to make the correct amount to shop. if no need to pick more then will print the message and will check the while condition.
                    printf("Great, that's the oranges done!");
                }
            } while (oranges != 0); //check the while condition, this loop will continue unless the valus is not 0.
            printf("\n\n");

            //do while starts to pick the correct amount.
            do {
                printf("Pick some TOMATOES... how many did you pick? : ");
                scanf("%d", &pick); //entered the picking value using scanf

                // if statement starts, checks if the picking value is less then or equal to 0.
                if (pick <= 0)
                {
                    printf("ERROR: You must pick at least 1!\n"); // will print this error message if the "if statement" is true.
                }
                // else if statement starts, if the "if statement" is not true then check if the picking value is more than needs to be shopped value.
                else if (pick > tomatoes)
                {
                    printf("You picked too many... only %d more TOMATO(ES) are needed.\n", tomatoes); // if the "else if statement" is true then this message will be printed.
                }
                // else if statement starts, if the previous conditions/statements are not true then checks if the picking value is less than needs to be shopped value.
                else if (pick < tomatoes)
                {
                    printf("Looks like we still need some TOMATOES...\n"); //if its true then, will print this message, that need to pick more.
                    tomatoes = tomatoes - pick; // calculate the remaining value that needs to be picked more to make the correct amount to shop.
                }
                // else statement starts, if no conditions/statements are true then checks this statement.
                else
                {
                    tomatoes = tomatoes - pick; // calculate the remaining value that needs to be picked more to make the correct amount to shop. if no need to pick more then will print the message and will check the while condition.
                    printf("Great, that's the tomatoes done!");
                }
            } while (tomatoes != 0); //check the while condition, this loop will continue unless the valus is not 0.
            printf("\n\n");

            printf("All the items are picked!\n\n");
        }
    } while (yesNo != 0); // do while will continue unless the keep going to shop values is not 0.

    return 0;
}
