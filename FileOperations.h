#ifndef FILEOPERATIONS_H
#define FILEOPERATIONS_H

#include <iostream>
#include <vector>
#include "Markup.h"
#include "User.h"
#include "Income.h"
#include "Expense.h"

class FileOperations {
public:
    int getNewUserId();
    void saveNewUser(User newUser);
    bool isLoginExist(string login);
    bool isLoginNotExist(string login);
    int userLogIn();
    void passwordChange(int loggedInUserId);
    void saveNewExpense(Expense newExpense);
    void saveNewIncome(Income newIncome);
    int getNewExpenseId();
    int getNewIncomeId();
    vector <Income> getIncomesData(string periodBegining, string periodEnd, int loggedInUserId);
    vector <Expense> getExpensesData(string periodBegining, string periodEnd, int loggedInUserId);
};

#endif // FILEOPERATIONS_H
