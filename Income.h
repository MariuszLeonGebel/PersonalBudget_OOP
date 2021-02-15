#ifndef INCOME_H
#define INCOME_H

#include <iostream>
#include "Entry.h"

using namespace std;

class Income : public Entry {
    int incomeId;

public:
    void setIncomeId(int newIncomeId);
    int getIncomeId();
};

#endif // INCOME_H
