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
#include <stdio.h>
#include <math.h> //including math library to do the round.

int main(void)
{
 //Creating variables with the appropiate datatype, these will store values.   
    const double  TAX = 0.13;
    const char    patSize = 'S';
    double        priceSmall;
    double        priceMedium;
    double        priceLarge;
    int           numberOfShirts;
    double        subTotal;
    int           subTotalCents;
    double        totalTax;
    int           totalTaxCents;
    double        total;
    int           totalCents;

    printf("Set Shirt Prices\n");
    printf("================\n");

    printf("Enter the price for a SMALL shirt: $");
    scanf("%lf", &priceSmall); //Using scanf to input the price of the small size shirt.
   // priceSmallCents = (int)round(priceSmall * 100.0); prof work.

    printf("Enter the price for a MEDIUM shirt: $");
    scanf("%lf", &priceMedium); //Using scanf to input the price of the medium size shirt.

    printf("Enter the price for a LARGE shirt: $");
    scanf("%lf", &priceLarge); //Using scanf to input the price of the large size shirt.
    printf("\n");

    //Displaying the shirt price list using the standard two-decimal precision(%.2lf) representation for the prices.
    printf("Shirt Store Price List\n");
    printf("======================\n");
    printf("SMALL : $%.2lf\n", priceSmall);
    printf("Medium: $%.2lf\n", priceMedium);
    printf("LARGE : $%.2lf\n\n", priceLarge);

    printf("Patty's shirt size is '%c' \n", patSize);
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &numberOfShirts); //Using the scanf for the user to input the number of buying shirts.
    printf("\n");

    printf("Patty's shopping cart...\n");
    printf("Contains  : %d shirts\n", numberOfShirts);//Using the printf format specifier to show the number of buying shirt.

    //Sub-total calculation:
    subTotal = numberOfShirts * priceSmall; //calculating the subtotal of the price of byuing shirts.
    subTotalCents = (subTotal * 100);
   // subTotalCents = (int) round(subTotal * 100); //multiplying with 100 to convert the subtotal in cents, adding (int) before round to make it int type.
    subTotal = (int)round(subTotalCents * 100) / 100; //rounding the subtotal in cents
    subTotal = subTotal / 100; //dividing by 100 to convert the cents to dollar.
    printf("Sub-Totals: $%8.4lf\n", subTotal); //Using the printf format specifier to show the subtotal of buying shirts.

    //Total-tax calculation:
    totalTax = TAX * subTotal; //calculating the total tax of the byuing shirts.
    totalTaxCents = (totalTax * 100);
   // totalTaxCents = (int) round(totalTax * 100); //multiplying with 100 to convert the tax in cents, adding (int) before round to make it int type.
    totalTax = (int) round(totalTaxCents * 100) / 100; //rounding the total tax in cents.
    totalTax = totalTax / 100; //dividing by 100 to convert the cents to dollar.
    printf("Taxes     : $%8.4lf\n", totalTax); //Using the printf format specifier to show the total tax of buying shirts.

    //Total-price calculation:
    total = subTotal + totalTax; //calculating the total price of the byuing shirts.
    totalCents = (total * 100);
    // totalCents = (int) round(total * 100); //multiplying with 100 to convert the price in cents, adding (int) before round to make it int type.
    total = (int)round(totalCents * 100) / 100; //rounding the total price in cents.
    total = total / 100; //dividing by 100 to convert the cents to dollar.
    printf("Total     : $%8.4lf\n", total); //Using the printf format specifier to show the total price of buying shirts.

    return 0;
}