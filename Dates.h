#ifndef DATES_H
#define DATES_H

#include <iostream>
#include <ctime>
#include <string>
#include "AuxiliaryMethods.h"

using namespace std;

class Dates {
public:
    string chooseDate(string description, string description1);
    string getCurrentDate();
    string enterDate(string description);
    int getCurrentYear();
    int getCurrentMonth();
    int getNumberOfDaysInMonth(int month, int year);
};

#endif // DATES_H
