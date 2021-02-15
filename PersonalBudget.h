#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>
#include "UserManager.h"
#include "EntryManager.h"
#include "BudgetManager.h"

using namespace std;

class PersonalBudget {
    UserManager userManager;
    EntryManager entryManager;
    BudgetManager budgetManager;

public:
    bool isUserLoggedIn();
    void userRegistration();
    void userLogIn();
    void userLogOut();
    void passwordChange();
    int getUserId();
    void addIncome(int id);
    void addExpense(int id);
    void createMonthBudget(int id, int no);

};

#endif // PERSONALBUDGET_H
