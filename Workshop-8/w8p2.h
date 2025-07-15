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

// ----------------------------------------------------------------------------
// defines/macros
#define MAX_PRODUCTS 3  // Maximum number of products to analyze
#define NUMBER_GRAMS 64 // Grams in a suggested serving
#define POUND_TO_KG 2.20462   //the conversion factor of the number of U.S. pounds (lbs) in a KG unit.

// ----------------------------------------------------------------------------
// structures
typedef struct
{
    int    sku;             // Product SKU number
    double proPrice;        // Product price
    int    calPerServing;   // Calories per suggested serving
    double proWeight;        // Product weight in pounds
}CatFoodInfo;

typedef struct
{
    int    sku;                  // Product SKU number
    double price;               // Product price
    int    caloriesPerServing;   // Calories per suggested serving
    double weightPounds;        // Product weight in pounds
    double weightKilograms;     // Product weight in kg
    int    weightGrams;          // Product weight in grams
    double totalServings;        // number for the total servings
    double costPerServing;       // number for the cost per serving
    double costcaloriesPerServing;  // number for the cost of calories per serving
   
}ReportData;

// ----------------------------------------------------------------------------
// function prototypes

// PART-1

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
void displayCatFoodData(const int sku, const double* proPrice,
    const int calPerServing, const double* proWeight);

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg

double convertLbsKg(const double* lbs, double* resultInKg);

// 9. convert lbs: g

int convertLbsG(const double* lbs, int* resultInGrams);

// 10. convert lbs: kg / g

void convertLbs(const double* lbs, double* resultInKg, int* resultInGrams);

// 11. calculate: servings based on gPerServ

double calculateServings(const int servingSizeGrams,
    int totalGrams, double* numOfServings);

// 12. calculate: cost per serving

double calculateCostPerServing(const double* price, 
    double* numOfServings, double* result);

// 13. calculate: cost per calorie

double calculateCostPerCal(const double* price, 
    double* calories, double* result);

// 14. Derive a reporting detail record based on the cat food product data

ReportData detailedReportData(const CatFoodInfo info, ReportData* result);

// 15. Display the formatted table header for the analysis results

void displayReportHeader(void);

// 16. Display the formatted data row in the analysis table

void displayReportData(const ReportData report, const int cheapestProduct);

// 17. Display the findings (cheapest)

void displayFinalAnalysis(const CatFoodInfo info);

// ----------------------------------------------------------------------------

// 7. Logic entry point 

void start(void);