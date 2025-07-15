/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P1)
Full Name  : Dil Humyra Sultana Borna
Student ID#: 139166227
Email      : dhsborna@myseneca.ca
Section    : NEE

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

// macros defining
#define MAX_PRODUCTS 3  // Maximum number of products to analyze
#define NUMBER_GRAMS 64 // Grams in a suggested serving
// ----------------------------------------------------------------------------
// structures

typedef struct
{
    int    sku;             // Product SKU number
    double proPrice;        // Product price
    int    calPerServing;   // Calories per suggested serving
    double proWeight;        // Product weight in pounds
}CatFoodInfo;

// ----------------------------------------------------------------------------
// function prototypes

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)

int getIntPositive(int* intPointer);

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)

double getDoublePositive(double* doublePointer);

// 3. Opening Message (include the number of products that need entering)

void openingMessage(const int numProducts);

// 4. Get user input for the details of cat food product

CatFoodInfo getCatFoodInfo(const int proSequenceNum);

// 5. Display the formatted table header

void displayCatFoodHeader(void);

// 6. Display a formatted record of cat food data

void displayCatFoodData(const int sku, const double* proPrice, const int calPerServing, const double* proWeight);

// 7. Logic entry point
void start(void);