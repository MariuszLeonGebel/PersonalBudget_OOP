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
#include "FileOperations.h"

using namespace std;

class EntryManager {
    void getIncomeDataFromUser(int loggedInUserId);
    void getExpenseDataFromUser(int loggedInUserId);

public:
    void addIncome(int loggedInUserId);
    void addExpense(int loggedInUserId);
};

#endif // ENTRYMANAGER_H
