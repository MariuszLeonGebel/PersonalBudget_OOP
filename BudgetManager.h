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

using namespace std;

class BudgetManager {
    int loggedInUserId;

    void getBudgetData(string periodBegining, string periodEnd);

public:
    void createMonthBudget(int userId, int no);

};

#endif // BUDGETMANAGER_H
