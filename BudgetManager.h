#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include "Markup.h"
#include "AuxiliaryMethods.h"
#include "Dates.h"
#include "Income.h"
#include "Expense.h"
#include "FileOperations.h"

using namespace std;

class BudgetManager {
    void showBudgetData(string periodBegining, string periodEnd, int loggedInUserId);

public:
    void createIncomeExpensesStatement(int loggedInUserId, int periodSelection);
};

#endif // BUDGETMANAGER_H
