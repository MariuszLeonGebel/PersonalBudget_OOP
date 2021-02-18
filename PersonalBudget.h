#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>
#include "UserManager.h"
#include "EntryManager.h"
#include "BudgetManager.h"

using namespace std;

class PersonalBudget {
    UserManager userManager;
    EntryManager * entryManager;
    BudgetManager * budgetManager;

public:
    PersonalBudget() {
        entryManager = NULL;
        budgetManager = NULL;
    }
    ~PersonalBudget() {
        delete entryManager;
        delete budgetManager;
        entryManager = NULL;
        budgetManager = NULL;
    }
    bool isUserLoggedIn();
    void userRegistration();
    void userLogIn();
    void userLogOut();
    void passwordChange(int id);
    int getUserId();
    void addIncome(int id);
    void addExpense(int id);
    void createIncomeExpensesStatement(int id, int no);
};

#endif // PERSONALBUDGET_H
