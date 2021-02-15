#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>
#include <Entry.h>

using namespace std;

class Expense : public Entry {
    int expenseId;

public:
    void setExpenseId(int newExpenseId);
    int getExpenseId();
};

#endif // EXPENSE_H
