#ifndef ENTRYMANAGER_H
#define ENTRYMANAGER_H

#include <iostream>
#include <ctime>
#include <string>
#include "Markup.h"
#include "AuxiliaryMethods.h"
#include "Dates.h"
#include "Income.h"
#include "Expense.h"

using namespace std;

class EntryManager {
    void getIncomeData(int loggedInUserId);
    int getNewIncomeId();
    void saveNewIncome(Income newIncome);

    void getExpenseData(int loggedInUserId);
    int getNewExpenseId();
    void saveNewExpense(Expense newExpense);

public:
    void addIncome(int loggedInUserId);
    void addExpense(int loggedInUserId);
};

#endif // ENTRYMANAGER_H
