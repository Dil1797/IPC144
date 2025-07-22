/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 3
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

#include <stdio.h>
#include <string.h>
#include <time.h>

// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"


//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
    printf("Pat.# Name            Phone#\n"
           "----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient* patient, int fmt)
{
    if (fmt == FMT_FORM)
    {
        printf("Name  : %s\n"
               "Number: %05d\n"
               "Phone : ", patient->name, patient->patientNumber);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
    else
    {
        printf("%05d %-15s ", patient->patientNumber,
               patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's appointment schedule headers (date-specific or all records)
void displayScheduleTableHeader(const struct Date* date, int isAllRecords)
{
    printf("Clinic Appointments for the Date: ");

    if (isAllRecords)
    {
        printf("<ALL>\n\n");
        printf("Date       Time  Pat.# Name            Phone#\n"
               "---------- ----- ----- --------------- --------------------"
            "\n");
    }
    else
    {
        printf("%04d-%02d-%02d\n\n", date->year, date->month, date->day);
        printf("Time  Pat.# Name            Phone#\n"
               "----- ----- --------------- --------------------\n");
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display a single appointment record with patient info. in tabular format
void displayScheduleData(const struct Patient* patient,
                         const struct Appointment* appoint,
                         int includeDateField)
{
    if (includeDateField)
    {
        printf("%04d-%02d-%02d ", appoint->date.year, appoint->date.month,
               appoint->date.day);
    }
    printf("%02d:%02d %05d %-15s ", appoint->time.hour, appoint->time.min,
           patient->patientNumber, patient->name);

    displayFormattedPhone(patient->phone.number);

    printf(" (%s)\n", patient->phone.description);
}


//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData* data)
{
    int selection;

    do {
        printf("Veterinary Clinic System\n"
               "=========================\n"
               "1) PATIENT     Management\n"
               "2) APPOINTMENT Management\n"
               "-------------------------\n"
               "0) Exit System\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
        case 0:
            printf("Are you sure you want to exit? (y|n): ");
            selection = !(inputCharOption("yn") == 'y');
            putchar('\n');
            if (!selection)
            {
                printf("Exiting system... Goodbye.\n\n");
            }
            break;
        case 1:
            menuPatient(data->patients, data->maxPatient);
            break;
        case 2:
            menuAppointment(data);
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
    int selection;

    do {
        printf("Patient Management\n"
               "=========================\n"
               "1) VIEW   Patient Data\n"
               "2) SEARCH Patients\n"
               "3) ADD    Patient\n"
               "4) EDIT   Patient\n"
               "5) REMOVE Patient\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 5);
        putchar('\n');
        switch (selection)
        {
        case 1:
            displayAllPatients(patient, max, FMT_TABLE);
            suspend();
            break;
        case 2:
            searchPatientData(patient, max);
            break;
        case 3:
            addPatient(patient, max);
            suspend();
            break;
        case 4:
            editPatient(patient, max);
            break;
        case 5:
            removePatient(patient, max);
            suspend();
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient* patient)
{
    int selection;

    do {
        printf("Edit Patient (%05d)\n"
               "=========================\n"
               "1) NAME : %s\n"
               "2) PHONE: ", patient->patientNumber, patient->name);
        
        displayFormattedPhone(patient->phone.number);
        
        printf("\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');

        if (selection == 1)
        {
            printf("Name  : ");
            inputCString(patient->name, 1, NAME_LEN);
            putchar('\n');
            printf("Patient record updated!\n\n");
        }
        else if (selection == 2)
        {
            inputPhoneData(&patient->phone);
            printf("Patient record updated!\n\n");
        }

    } while (selection);
}


// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Appointment Management
void menuAppointment(struct ClinicData* data)
{
    int selection;

    do {
        printf("Appointment Management\n"
               "==============================\n"
               "1) VIEW   ALL Appointments\n"
               "2) VIEW   Appointments by DATE\n"
               "3) ADD    Appointment\n"
               "4) REMOVE Appointment\n"
               "------------------------------\n"
               "0) Previous menu\n"
               "------------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 4);
        putchar('\n');
        switch (selection)
        {
        case 1:
            viewAllAppointments(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 2:
            viewAppointmentSchedule(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 3:
            addAppointment(data->appointments, data->maxAppointments,
                           data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 4:
            removeAppointment(data->appointments, data->maxAppointments,
                              data->patients, data->maxPatient);  // ToDo: You will need to create this function!
                              
            suspend();
            break;
        }
    } while (selection);
}


// ---------------------------------------------------------------------------
// !!! INSERT/COPY YOUR MS#2 FUNCTION DEFINITIONS BELOW... !!!
// Note: Maintain the same order/sequence as it is listed in the header file
//       Properly organize/categorize any new functions accordingly
// ---------------------------------------------------------------------------


// Display's all patient data in the FMT_FORM | FMT_TABLE format
void displayAllPatients(const struct Patient patient[], int max, int fmt)
{
    int i, record = 0;

    if (fmt == FMT_TABLE)
    {
        displayPatientTableHeader();
    }

    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber != 0)
        {
            displayPatientData(&patient[i], fmt);
            record = 1;
        }
    }

    if (record == 0)
    {
        printf("*** No records found ***\n\n");
    }

    printf("\n");

}


// Search for a patient record based on patient number or phone number
void searchPatientData(const struct Patient patient[], int max)
{
    int opt;

    do {
        printf("Search Options\n");
        printf("==========================\n");
        printf("1) By patient number\n");
        printf("2) By phone number\n");
        printf("..........................\n");
        printf("0) Previous menu\n");
        printf("..........................\n");
        printf("Selection: ");
        scanf("%d", &opt);
        printf("\n");

        if (opt == 1)
        {
            searchPatientByPatientNumber(patient, max);
            clearInputBuffer();
            suspend();
        }
        else if (opt == 2)
        {
            searchPatientByPhoneNumber(patient, max);
            clearInputBuffer();
            suspend();
        }
    } while (opt != 0);

}


// Add a new patient record to the patient array
void addPatient(struct Patient patient[], int max)
{
    int i;
    int done = 0;

    for (i = 0; i < max && done == 0; i++)
    {
        if (patient[i].patientNumber == 0)
        {
            done = 1;
            patient[i].patientNumber = nextPatientNumber(patient, max);
            inputPatient(&patient[i]);
        }
    }
    if (done ==0)
    {
        printf("ERROR: Patient listing is FULL!\n\n");
    }
}


// Edit a patient record from the patient array
void editPatient(struct Patient patient[], int max)
{

    int patNum, index;

    printf("Enter the patient number: ");
    scanf("%d", &patNum);
    printf("\n");

    index = findPatientIndexByPatientNum(patNum, patient, max);

    if (index != -1)
    {
        // pointer arithmetic 
        menuPatientEdit(patient + index);
    }
    else
    {
        printf("ERROR: Patient record not found!\n");
    }

}


// Remove a patient record from the patient array
void removePatient(struct Patient patient[], int max)
{
    int patNum, index;
    char opt;

    printf("Enter the patient number: ");
    patNum = inputIntPositive();
    putchar('\n');

    index = findPatientIndexByPatientNum(patNum, patient, max);

    if (index != -1)
    {
        displayPatientData(&patient[index], FMT_FORM);

        printf("\n");
        printf("Are you sure you want to remove this patient record? (y/n): ");
        opt = inputCharOption("yn");

        if (opt == 'y')
        {
            patient[index].patientNumber = 0;
            printf("Patient record has been removed!\n");
        }
        else if (opt == 'n')
        {
            printf("Operation aborted.");
        }
    }

    else
    {
        printf("ERROR: Patient record not found!\n");
    }

    putchar('\n');
}


// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Milestone #3 mandatory functions...
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// View ALL scheduled appointments
void viewAllAppointments(struct ClinicData* data) {

    int i, sortedInd;
    struct Date today = { 0,0,0 };

    // Display header
    displayScheduleTableHeader(&today, ALL_DATES);

    // Display data
    for (i = 0; i < data->maxAppointments; i++)
    {
        if (data->appointments[i].date.year != 0)
        {

            // Find patient info based on sorted appointments array
            sortedInd = findPatientIndexByPatientNum
            (data->appointments[i].patientNumber, 
                data->patients, data->maxPatient);

            // Display sorted data
            displayScheduleData(&data->patients[sortedInd],
                &data->appointments[i], ALL_DATES);
        }
    }
    putchar('\n');

    return;

}


// View appointment schedule for the user input date
void viewAppointmentSchedule(struct ClinicData* data) {
    struct Date date = { 0,0,0 };
    int i, max_day, pat_ind;

    // prompt user to enter date
    printf("Year        : ");
    date.year = inputIntPositive();

    printf("Month (1-12): ");
    date.month = inputIntRange(MIN_MONTH, MAX_MONTHS);

    max_day = getMaxDay(date.year, date.month);
    printf("Day (%d-%d)  : ", MIN_DAY, max_day);
    date.day = inputIntRange(MIN_DAY, max_day);

    putchar('\n');

    // Display header
    displayScheduleTableHeader(&date, SINGLE_DATE);

    // Get data
    for (i = 0; i < data->maxAppointments; i++)
    {
        if (matchDate(data->appointments[i].date, date))
        {
            // Find matching patient
            pat_ind = findPatientIndexByPatientNum
            (data->appointments[i].patientNumber, 
                data->patients, data->maxPatient);

            // Display data
            displayScheduleData(&data->patients[pat_ind], 
                &data->appointments[i], SINGLE_DATE);
        }
    }

    putchar('\n');
}

// Add an appointment record to the appointment array
void addAppointment(struct Appointment* appointments, int maxAppointments,
    struct Patient* patients, int maxPatients) 
{
    struct Appointment app;
    int i, patInd, openSlot = 0;
    int addPatient = 0, addDate = 0, addTime = 0, flag = 0, confirm = 0;

    // Handle user input
    do
    {
        // Patient number
        while (!addPatient)
        {
            printf("Patient Number: ");
            app.patientNumber = inputIntPositive();

            // To validate input
            patInd = findPatientIndexByPatientNum(app.patientNumber, 
                patients, maxPatients);

            if (patInd != -1)
            {
                addPatient = 1;
            }
        }

        // Date
        if (!addDate)
        {
            inputDate(&app.date);
        }

        // Time
        if (!addTime)
        {
            inputTime(&app.time);
        }

        // To validate input
        openSlot = availAppoint(appointments, &app, maxAppointments);

        if (!openSlot && !addDate)
        {
            printf("\nERROR: Appointment timeslot is not available!\n\n");
            addDate = 0;
            addTime = 0;
            openSlot = 1;
        }
        else
        {
            addDate = 1;
        }

        if (!openSlot || ((app.time.hour < HOUR_OPEN || 
            app.time.hour > HOUR_CLOSE) ||
            (app.time.hour == HOUR_CLOSE && app.time.min > 0)))
        {
            printf("ERROR: Time must be between %d:00 and %d:00 in %d minute"
                " intervals.\n\n", 
                HOUR_OPEN, HOUR_CLOSE, APPOINT_INTERVAL);
        }
        else
        {
            addTime = addDate;
        }

        flag = (addDate && addTime && openSlot);

    } while (!flag);

    if (flag)
    {
        for (i = 0; i < maxAppointments && confirm != 1; i++)
        {
            if (appointments[i].date.year == 0 ||
                appointments[i].patientNumber == 0)
            {
                // add new appointment to database
                appointments[i] = app;

                // exit loop
                confirm = 1;
            }
        }

        // sort appointments array 
        sortAppointment(appointments, maxAppointments);

        // concluding message if appointment successfully scheduled
        printf("\n*** Appointment scheduled! ***\n");
    }

    putchar('\n');
}

// Remove an appointment record from the appointment array
void removeAppointment(struct Appointment* appointments, int maxAppointments,
    struct Patient* patients, int maxPatients)
{
    int i, appToRemove = 0, patNum, patInd;
    struct Patient patData;
    struct Date appDate;
    char confirm;

    printf("Patient Number: ");
    patNum = inputIntPositive();

    patInd = findPatientIndexByPatientNum(patNum, patients, maxPatients);

    if (patInd == -1)
    {
        printf("ERROR: Patient record not found!\n");
    }
    else
    {
        patData = patients[patInd];
        inputDate(&appDate);

        // search appointment
        for (i = 0; i < maxAppointments && appToRemove == 0; i++)
        {
            if (appointments[i].patientNumber == patData.patientNumber &&
                appointments[i].date.year == appDate.year &&
                appointments[i].date.month == appDate.month &&
                appointments[i].date.day == appDate.day)
            {
                appToRemove = 1;
            }
        }

        if (appToRemove == 1)
        {
            printf("\n");
            printf("Name  : %s\n", patData.name);
            printf("Number: %05d\n", patData.patientNumber);
            printf("Phone : ");
            displayFormattedPhone(patData.phone.number);
            printf(" (%s)\n", patData.phone.description);

            printf("Are you sure you want to remove this appointment (y,n): ");
            confirm = inputCharOption("yn");

            if (confirm == 'y')
            {
                appointments[i - 1].patientNumber = 0;
                appointments[i - 1].date.year = 0;
                printf("\nAppointment record has been removed!\n");
            }

        }
    }

    putchar('\n');
}

//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
void searchPatientByPatientNumber(const struct Patient patient[], int max)
{
    int patNum, isPresent;

    printf("Search by patient number: ");
    scanf("%d", &patNum);
    printf("\n");

    isPresent = findPatientIndexByPatientNum(patNum, patient, max);

    if (isPresent != -1)
    {
        displayPatientData(&patient[isPresent], FMT_FORM);
    }
    else
    {
        printf("*** No records found ***\n");
    }

    printf("\n");
}


// Search and display patient records by phone number (tabular)
void searchPatientByPhoneNumber(const struct Patient patient[], int max)
{
    int i, display = 0;
    char phoneNum[PHONE_LEN + 1];
    clearInputBuffer();
    printf("Search by phone number: ");
    fgets(phoneNum, sizeof(phoneNum), stdin);
    printf("\n");

    displayPatientTableHeader();

    for (i = 0; i < max + 1; i++)
    {
        if (strcmp(patient[i].phone.number, phoneNum) == 0)
        {
            displayPatientData((patient + i), FMT_TABLE);
            display++;
        }
    }
    printf("\n");
    if (display == 0)
    {
        printf("*** No records found ***");
        printf("\n");
    }

}


// Get the next highest patient number
int nextPatientNumber(const struct Patient patient[], int max)
{
    int i, nextNum;
    int largestNum = patient[0].patientNumber;

    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber > largestNum)
        {
            largestNum = patient[i].patientNumber;
        }
    }

    nextNum = largestNum + 1;
    return nextNum;
}


// Find the patient array index by patient number (returns -1 if not found)
int findPatientIndexByPatientNum(int patientNumber,
    const struct Patient patient[], int max)
{
    int i;

    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber == patientNumber)
        {
            return i;
        }
    }

    return -1;
}

//APPOINTMENT UTILITY FUNCTIONS//

// Sorts an appointments array based on datetime (bubble sort)
void sortAppointment(struct Appointment appoint[], int len)
{
    int i, j;
    struct Appointment temp;

    for (i = 0; i < len; i++)
    {
        for (j = 0; j < len - 1 - i; j++)
        {
            // the comparison from greatest to smallest datetime scale:
            // years -> months -> days -> hours -> minutes
            if (
                // compare years
                appoint[j].date.year > appoint[j + 1].date.year ||

                // years are equal, compare months
                (
                    appoint[j].date.year == appoint[j + 1].date.year &&
                    appoint[j].date.month > appoint[j + 1].date.month
                    )

                ||

                // months are equal, compare days
                (
                    appoint[j].date.year == appoint[j + 1].date.year &&
                    appoint[j].date.month == appoint[j + 1].date.month &&
                    appoint[j].date.day > appoint[j + 1].date.day
                    )

                ||

                // days are equal, compare hours 
                (
                    appoint[j].date.year == appoint[j + 1].date.year &&
                    appoint[j].date.month == appoint[j + 1].date.month &&
                    appoint[j].date.day == appoint[j + 1].date.day &&
                    appoint[j].time.hour > appoint[j + 1].time.hour
                    )

                ||

                // hours are equal, compare minutes 
                (
                    appoint[j].date.year == appoint[j + 1].date.year &&
                    appoint[j].date.month == appoint[j + 1].date.month &&
                    appoint[j].date.day == appoint[j + 1].date.day &&
                    appoint[j].time.hour == appoint[j + 1].time.hour &&
                    appoint[j].time.min > appoint[j + 1].time.min
                    )
                )
            {
                // swap the elements
                temp = appoint[j];
                appoint[j] = appoint[j + 1];
                appoint[j + 1] = temp;
            }
        }
    }
}

// Determines the amount of days for the given year and month
int getMaxDay(int year, int month)
{
    int days, isLeap;

    switch (month)
    {
        // Months which have 31 days
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        days = 31;
        break;

        // Months which have 30 days
    case 4:
    case 6:
    case 9:
    case 11:
        days = 30;
        break;

        // February
    default:
        isLeap = isLeapYear(year);
        if (isLeap)
        {
            days = 29;
        }
        else
        {
            days = 28;
        }
    }

    return days;
}

// Checks if the provided appointdate is equal to the one in database
int matchDate(struct Date baseDate, struct Date appointDate)
{
    int dateMatches = 0;
    if (baseDate.day == appointDate.day && 
        baseDate.month == appointDate.month && 
        baseDate.year == appointDate.year)
    {
        dateMatches = 1;
    }

    return dateMatches;
}

// Checks whether or not the selected time slot is open
int freeSlot(struct Time baseTime, struct Time appointTime)
{
    int baseTotalMins, appTotalMins, totalDiff, isOnInterval = 0,
        isOverlap = 0;

    // calculate difference in minutes
    baseTotalMins = (baseTime.hour * 60) + baseTime.min;
    appTotalMins = (appointTime.hour * 60) + appointTime.min;
    totalDiff = appTotalMins > baseTotalMins ? (appTotalMins - baseTotalMins) :
        (baseTotalMins - appTotalMins);

    // Check if the appointment time falls within the specified interval 
    if (appointTime.min % APPOINT_INTERVAL == 0)
    {
        isOnInterval = 1;
    }
    
    // Check for overlapping with existing appointments
    if ((baseTime.hour == appointTime.hour && totalDiff < APPOINT_INTERVAL) ||
        (totalDiff < APPOINT_INTERVAL))
    {
        isOverlap = 1;
    }

    // Determine if the time slot is available based on interval and without any conflicts
    if (isOnInterval && !isOverlap)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// To verify if a specific time slot is available for an appointment
int availAppoint(struct Appointment dbAppoints[], 
    struct Appointment* dateTime, int arrSize)
{
    int ret = 1, i = 0, flag = 1, isSlotFree;

    // we use flag to exit the loop in case the appointment schedules conflict
    // with each other on a given date
    while (i < arrSize && flag == 1)
    {
        isSlotFree = matchDate(dbAppoints[i].date, dateTime->date);
        if (isSlotFree)
        {
           ret = freeSlot(dbAppoints[i].time, dateTime->time);
        }
        i++;
    }

    return ret;
}

// To check if the year is leap or not
int isLeapYear(int year)
{
    int leap = 0;
    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
    {
        leap = 1;
    }

    return leap;
}


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
void inputPatient(struct Patient* patient)
{
   printf("Patient Data Input\n");
    printf("------------------\n");
    printf("Number: %05d\n", patient->patientNumber);
    printf("Name  : ");
    inputCString(patient->name, 1, NAME_LEN);
    
    putchar('\n');

    inputPhoneData(&patient->phone);

    printf("*** New patient record added ***\n\n");
}


// Get user input for phone contact information
void inputPhoneData(struct Phone* phone)
{
    int opt;

    printf("Phone Information\n");
    printf("-----------------\n");
    printf("How will the patient like to be contacted?\n");
    printf("1. Cell\n");
    printf("2. Home\n");
    printf("3. Work\n");
    printf("4. TBD\n");
    printf("Selection: ");
    scanf("%d", &opt);
    getchar();
    printf("\n");

    switch (opt)
    {
    case 1:
        strncpy(phone->description, "CELL", PHONE_DESC_LEN);
        break;
    case 2:
        strncpy(phone->description, "HOME", PHONE_DESC_LEN);
        break;
    case 3:
        strncpy(phone->description, "WORK", PHONE_DESC_LEN);
        break;
    case 4:
        strncpy(phone->description, "TBD", PHONE_DESC_LEN);
        strcpy(phone->number, "\0");
        break;
    }

    if (opt != 4)
    {
        printf("Contact: %s\n", phone->description);
        printf("Number : ");
        inputCString(phone->number, 10, 10);
        printf("\n");
    }

}

// To prompt user for a date info and save it
// to a received struct Date pointer
void inputDate(struct Date* ptDate)
{
    int maxDay;

    printf("Year        : ");
    ptDate->year = inputIntPositive();
    printf("Month (%d-%d): ", MIN_MONTH, MAX_MONTHS);
    ptDate->month = inputIntRange(MIN_MONTH, MAX_MONTHS);

    // set maxDay based on input
    maxDay = getMaxDay(ptDate->year, ptDate->month);
    printf("Day (%d-%d)  : ", MIN_DAY, maxDay);
    ptDate->day = inputIntRange(MIN_DAY, maxDay);

}

// To prompt user for a time slot info and save it
// to a received struct Date pointer
void inputTime(struct Time* ptTime)
{
    printf("Hour (%d-%d)  : ", MIN_HOUR, MAX_HOURS);
    ptTime->hour = inputIntRange(MIN_HOUR, MAX_HOURS);
    printf("Minute (%d-%d): ", MIN_MINUTE, MAX_MINUTES);
    ptTime->min = inputIntRange(MIN_MINUTE, MAX_MINUTES);
}


//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

// Import patient data from file into a Patient array (returns # of records read)
int importPatients(const char* datafile, struct Patient patients[], int max)
{

    FILE* file = fopen(datafile, "r");
    int numRecs = 0;

    if (file != NULL)
    {
        for (numRecs = 0; numRecs < max && (!feof(file)); numRecs++)
        {
            fscanf(file, "%d|%15[^|]%*c%5[^|]%*c%11[^\n]",
                &patients[numRecs].patientNumber,
                patients[numRecs].name,
                patients[numRecs].phone.description,
                patients[numRecs].phone.number
            );
            fgetc(file);
        }
        fclose(file);
    }
    else
    {
        printf("ERROR reading PATIENTS database...\n");
    }
    return numRecs;
}

// Import appointment data from file into an Appointment array (returns # of records read)
int importAppointments(const char* datafile, 
    struct Appointment appoints[], int max)
{

    FILE* file = fopen(datafile, "r");
    int i = 0;
    if (file != NULL)
    {
        for (i = 0; i < max && (!feof(file)); i++)
        {
            fscanf(file, "%d,%d,%d,%d,%d,%d",
                &appoints[i].patientNumber,
                &appoints[i].date.year, 
                &appoints[i].date.month,
                &appoints[i].date.day, 
                &appoints[i].time.hour, 
                &appoints[i].time.min);
            fgetc(file);
        }
        fclose(file);

        // Verify for 0 value
        if (appoints[i].patientNumber == 0)
        {
            i--;
        }

        // Sort the records based on dateTime
        sortAppointment(appoints, i);
    }
    else
    {
        puts("ERROR reading APPOINTMENTS database...\n");
    }
   
    return i;
}