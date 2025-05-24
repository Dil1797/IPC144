/******************************************************************************
                       Workshop - #2 (Part - 1)
Full Name   :Dil Humyra Sultana Borna
Student ID# :139166227
Email       :dhsborna@myseneca.ca
Section     :NEE

Authenticity Declaration :
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider.This submitted
piece of work is entirely of my own creation.
******************************************************************************/

#define _CRT_SECURE_NO_WARNINGS  //for avoiding the scanf error.
#pragma warning(disable:6031)
#include <stdio.h>
#include <math.h> //including math library to do the round.

int main(void)
{
    //Creating variables with the appropiate datatype, these will store values.   
    const double  TAX = 0.13;
    const char    patSize = 'S';
    const char    tommySize = 'L';
    const char    sallySize = 'M';
    double        priceSmall;
    double        priceMedium;
    double        priceLarge;
    int           shirtsQuantityPatty;
    int           shirtsQuantityTommy;
    int           shirtsQuantitySally;
    double        subTotal;
    double        tax;
    double        total;
    double        subTotalCentsPatty;
    double        taxCentsPatty;
    double        subTotalCentsSally;
    double        taxCentsSally;
    double        subTotalCentsTommy;
    double        taxCentsTommy;
    int           priceSmallCents;
    int           priceMediumCents;
    int           priceLargeCents;
    double        totalPatty;
    double        totalSally;
    double        totalTommy;
    int           Toonies;
    int           Loonies;
    int           Quarters;
    int           Dimes;
    int           Nickels;
    int           Pennies;
    int           remaining;
    double        remaining_decimal;
    double        averageExcludeTax;
    double        averageIncludeTax;
    int           totalShirts;

    printf("Set Shirt Prices\n");
    printf("================\n");

    printf("Enter the price for a SMALL shirt: $");
    scanf("%lf", &priceSmall); //Using scanf to input the price of the small size shirt.
    priceSmallCents = (int) round(priceSmall * 100.0); //rounding the price and multiplying with 100 to make it cents.

    printf("Enter the price for a MEDIUM shirt: $");
    scanf("%lf", &priceMedium); //Using scanf to input the price of the medium size shirt.
    priceMediumCents = (int) round(priceMedium * 100.0); //rounding the price and multiplying with 100 to make it cents.

    printf("Enter the price for a LARGE shirt: $");
    scanf("%lf", &priceLarge); //Using scanf to input the price of the large size shirt.
    priceLargeCents = (int) round(priceLarge * 100.0);//rounding the price and multiplying with 100 to make it cents.
    printf("\n");

    //Displaying the shirt price list using the standard two-decimal precision(%.2lf) representation for the prices.
    printf("Shirt Store Price List\n");
    printf("======================\n");
    printf("SMALL  : $%.2lf\n", priceSmall);
    printf("MEDIUM : $%.2lf\n", priceMedium);
    printf("LARGE  : $%.2lf\n\n", priceLarge);

    printf("Patty's shirt size is '%c' \n", patSize);
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &shirtsQuantityPatty); //Using the scanf for the user to input the number of buying shirts.
    printf("\n");

    printf("Tommy's Shirt size is '%c'\n", tommySize);
    printf("Number of shirts Tomy is buying: ");
    scanf("%d", &shirtsQuantityTommy); //Using the scanf for the user to input the number of buying shirts.
    printf("\n");

    printf("Sally's Shirt size is '%c'\n", sallySize);
    printf("Number of shirts Sally is buying: ");
    scanf("%d", &shirtsQuantitySally); //Using the scanf for the user to input the number of buying shirts.
    printf("\n");

    //Patty's purchasing calculation-
    subTotalCentsPatty = priceSmallCents * shirtsQuantityPatty; //caculating subtotal in cents.
    taxCentsPatty = (double) subTotalCentsPatty * TAX; // calculating tax
    taxCentsPatty = (int) round(taxCentsPatty); //making round of the tax
    totalPatty = subTotalCentsPatty + taxCentsPatty; // calculating tax with subtotal in cents.

    //Sally's purchasing calculation-
    subTotalCentsSally = priceMediumCents * shirtsQuantitySally; //caculating subtotal in cents.
    taxCentsSally = (double)subTotalCentsSally * TAX; // calculating tax
    taxCentsSally = (int)round(taxCentsSally);  //making round of the tax
    totalSally = subTotalCentsSally + taxCentsSally; // calculating tax with subtotal in cents.

    //Tommyy's purchasing calculation-
    subTotalCentsTommy = priceLargeCents * shirtsQuantityTommy; //caculating subtotal in cents.
    taxCentsTommy = (double)subTotalCentsTommy * TAX; // calculating tax
    taxCentsTommy = (int)round(taxCentsTommy); //making round of the tax
    totalTommy = subTotalCentsTommy + taxCentsTommy; // calculating tax with subtotal in cents.

    printf("Customer Size Price Qty Sub-Total       Tax     Total\n");
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    printf("Patty    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", 
        patSize, 
        priceSmall, 
        shirtsQuantityPatty, 
        (double) subTotalCentsPatty / 100.0, 
        (double) taxCentsPatty / 100, 
        (double) totalPatty / 100);

    printf("Sally    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n",
        sallySize,
        priceMedium,
        shirtsQuantitySally,
        (double)subTotalCentsSally / 100.0,
        (double)taxCentsSally / 100,
        (double)totalSally / 100);

    printf("Tommy    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n",
        tommySize,
        priceLarge,
        shirtsQuantityTommy,
        (double)subTotalCentsTommy / 100.0,
        (double)taxCentsTommy / 100,
        (double)totalTommy / 100);
    printf("-------- ---- ----- --- --------- -------- ----------\n");

    //calculation of sub-total , tax and total price of Patty, Sally and Tommy.
    subTotal = subTotalCentsPatty + subTotalCentsSally + subTotalCentsTommy;
    tax = taxCentsPatty + taxCentsSally + taxCentsTommy;
    total = totalPatty + totalSally + totalTommy;

    printf("% 33.4lf % 9.4lf % 9.4lf\n\n", (double) subTotal / 100, (double) tax / 100.0, (double)total /100.0);

    printf("Daily retail sales represented by coins\n");
    printf("=======================================\n\n");

    printf("Sales EXCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("%22.4lf\n", (double)subTotal / 100); //using printf specifier to show the subtotal amount.

    //Toonies calculation excluding tax-
    Toonies = (int) subTotal / 200; //applying integer division (/) to obtain the number of coins
    remaining = (int) subTotal % 200; //applying operator (%) to obtain the new remaining amount to be used in the Loonies.
    remaining_decimal = (double) remaining / 100;
    printf("Toonies  %3d %9.4lf\n", Toonies, remaining_decimal);

    //Loonies calculation excluding tax-
    Loonies = (int) remaining / 100; //applying integer division (/) to obtain the number of coins
    remaining = (int)remaining % 100; //applying operator (%) to obtain the new remaining amount to be used in the Quarters.
    remaining_decimal = (double)remaining / 100;
    printf("Loonies  %3d %9.4lf\n", Loonies, remaining_decimal);

    //Quarters calculation excluding tax-
    Quarters = (int)remaining / 25; //applying integer division (/) to obtain the number of coins
    remaining = (int)remaining % 25; //applying operator (%) to obtain the new remaining amount to be used in the Dimes.
    remaining_decimal = (double)remaining / 100;
    printf("Quarters %3d %9.4lf\n", Quarters, remaining_decimal);

    //Dimes calculation excluding tax-
    Dimes = (int)remaining / 10; //applying integer division (/) to obtain the number of coins
    remaining = (int)remaining % 10; //applying operator (%) to obtain the new remaining amount to be used in the Nickles.
    remaining_decimal = (double)remaining / 100;
    printf("Dimes    %3d %9.4lf\n", Dimes, remaining_decimal);

    //Nickles calculation excluding tax-
    Nickels = (int)remaining / 5; //applying integer division (/) to obtain the number of coins
    remaining = (int)remaining % 5; //applying operator (%) to obtain the new remaining amount to be used in the Pennies.
    remaining_decimal = (double)remaining / 100;
    printf("Nickels  %3d %9.4lf\n", Nickels, remaining_decimal);

    //Pennies calculation excluding tax-
    Pennies = (int)remaining / 1; //applying integer division (/) to obtain the number of coins
    remaining = (int)remaining % 1; //applying operator (%) to obtain the new remaining amount if there is any.
    remaining_decimal = (double)remaining / 100;
    printf("Pennies  %3d %9.4lf\n\n", Pennies, remaining_decimal);

    //Average calculation excluding tax-
    totalShirts = shirtsQuantityPatty + shirtsQuantityTommy + shirtsQuantitySally;
    averageExcludeTax = subTotal / totalShirts;
    averageExcludeTax = (double) averageExcludeTax / 100;
    printf("Average cost/shirt: $%9.4lf\n\n", averageExcludeTax);

    printf("Sales INCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("%22.4lf\n", (double)total / 100);  //using printf specifier to show the total amount.

    //Toonies calculation including tax-
    Toonies = (int) total / 200;
    remaining = (int) total % 200;
    remaining_decimal = (double)remaining / 100;
    printf("Toonies  %3d %9.4lf\n", Toonies, remaining_decimal);

    //Loonies calculation including tax-
    Loonies = (int)remaining / 100;
    remaining = (int)remaining % 100;
    remaining_decimal = (double)remaining / 100;
    printf("Loonies  %3d %9.4lf\n", Loonies, remaining_decimal);

    //Quarters calculation including tax-
    Quarters = (int)remaining / 25;
    remaining = (int)remaining % 25;
    remaining_decimal = (double)remaining / 100;
    printf("Quarters %3d %9.4lf\n", Quarters, remaining_decimal);

    //Dimes calculation including tax-
    Dimes = (int)remaining / 10;
    remaining = (int)remaining % 10;
    remaining_decimal = (double)remaining / 100;
    printf("Dimes    %3d %9.4lf\n", Dimes, remaining_decimal);

    //Nickles calculation including tax-
    Nickels = (int)remaining / 5;
    remaining = (int)remaining % 5;
    remaining_decimal = (double)remaining / 100;
    printf("Nickels  %3d %9.4lf\n", Nickels, remaining_decimal);

    //Pennies calculation including tax-
    Pennies = (int)remaining / 1;
    remaining = (int)remaining % 1;
    remaining_decimal = (double)remaining / 100;
    printf("Pennies  %3d %9.4lf\n\n", Pennies, remaining_decimal);

    //Average calculation including tax including tax-
    averageIncludeTax = total / totalShirts;
    averageIncludeTax = (double)averageIncludeTax / 100;
    printf("Average cost/shirt: $%9.4lf\n", averageIncludeTax);

    return 0;
}

