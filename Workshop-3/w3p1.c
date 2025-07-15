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

int main(void)
{
	//Variables declaration
	// You must use this variable in #3 data analysis section!
	double          averagePrice;
	const double    testValue = 330.99;
	//declaring 9 constant variables of proucts ID, taxed and price.
	const int       product1ID = 111;
	const double    product1Price = 111.49;
	const char      product1Taxed = 'Y';
	const int       product2ID = 222;
	const double    product2Price = 222.99;
	const char      product2Taxed = 'N';
	const int       product3ID = 111;
	const double    product3Price = 334.49;
	const char      product3Taxed = 'N';

	//Displaying Product Data
	//Product-1
	printf("Product Information\n");
	printf("===================\n");
	printf("Product-1 (ID:%d)\n", product1ID); //using printf formatted specifier to show the product 1 ID which is a const.
	printf("  Taxed: %c\n", product1Taxed); //using printf formatted specifier to show the product 1 Taxed which is a const.
	printf("  Price: $%.4lf\n\n", product1Price);

	//Product-2
	printf("Product-2 (ID:%d)\n", product2ID); //using printf formatted specifier to show the product 2 ID which is a const.
	printf("  Taxed: %c\n", product2Taxed); //using printf formatted specifier to show the product 2 Taxed which is a const.
	printf("  Price: $%.4lf\n\n", product2Price);

	//Product-3
	printf("Product-3 (ID:%d)\n", product3ID); //using printf formatted specifier to show the product 3 ID which is a const.
	printf("  Taxed: %c\n", product3Taxed); //using printf formatted specifier to show the product 3 Taxed which is a const.
	printf("  Price: $%.4lf\n\n", product3Price);

	//calculating average price-
	averagePrice = (product1Price + product2Price + product3Price) / 3;
	printf("The average of all prices is: $%.4lf\n\n\n", averagePrice); //using printf formatted specifier to show the products average price.

	printf("About Relational and Logical Expressions!\n");
	printf("========================================\n");
	printf("1. These expressions evaluate to TRUE or FALSE\n");
	printf("2. FALSE: is always represented by integer value 0\n");
	printf("3. TRUE : is represented by any integer value other than 0\n\n");

	//Display summary of test scenarios:
	printf("Some Data Analysis...\n");
	printf("=====================\n");

	//test 1
	printf("1. Is product 1 taxable ? -> %d\n\n", product1Taxed == 'Y'); //using equal(==) "Relational and Logical Expressions" to analysis the product 1 taxed data which is taxable.

	//test 2
	printf("2. Are products 2 and 3 both NOT taxable (N) ? -> %d\n\n",
		product2Taxed == 'N' && product3Taxed == 'N'); //using equal(==) and and(&&) "Relational and Logical Expressions" to analysis the product 2 and product 3 taxed data where both are taxable.

	//test 3
	printf("3. Is product 3 less than testValue ($330.99)? -> %d\n\n",
		product3Price < testValue); //using less than (<) "Relational and Logical Expressions" to analysis if the product 3 is less than test value, which is not true.

	//test 4
	printf("4. Is the price of product 3 more than both product 1 and 2 combined?"
		"-> %d\n\n",
		product3Price > (product1Price + product2Price)); //using the greater than (>) "Relational and Logical Expressions" to analysis if the product 3 price is greater than the additional price of product 2 and product 3, which is true.

	//test 5
	//an in-line calculation, the difference of the price (not stored to a variable).
	printf("5. Is the price of product 1 equal to or more than the price difference\n"   
		"   of product 3 LESS product 2 ? -> % d(price difference : $ % .2lf)\n\n",
		product1Price >= product3Price - product2Price,
		product3Price - product2Price); //using the greater than equal (>=) "Relational and Logical Expressions" to analysis if the product 1 price is greater than the substract price of product 3 and product 2, which is not true.

	//test 6
	printf("6. Is the price of product 2 equal to or more than the average price"
		"? -> %d\n\n",
		product2Price >= averagePrice); //using the greater than equal (>=) "Relational and Logical Expressions" to analysis if the product 2 price is greater than the average price, which is true.

	//test 7
	printf("7. Based on product ID, product 1 is unique -> %d\n\n",
		product1ID != product2ID && product1ID != product3ID); //using the not equal (!=) "Relational and Logical Expressions" to analysis if the product 1 ID is unique, which is not true.

	//test 8
	printf("8. Based on product ID, product 2 is unique -> %d\n\n",
		product2ID != product1ID && product2ID != product3ID); //using the not equal (!=) "Relational and Logical Expressions" to analysis if the product 2 ID is unique, which is true.

	//test 9
	printf("9. Based on product ID, product 3 is unique -> %d\n",
		product3ID != product1ID && product3ID != product2ID); //using the not equal (!=) "Relational and Logical Expressions" to analysis if the product 3 ID is unique, which is not true.

	return 0;
}
