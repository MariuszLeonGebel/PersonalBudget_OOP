#include "EntryManager.h"

void EntryManager::getExpenseData(int loggedInUserId) {
    Expense expense;
    Dates dates;

    expense.setExpenseId(getNewExpenseId());
    expense.setUserId(loggedInUserId);
    expense.setDate(dates.chooseDate("wydatku", "wydatek"));
    cout<<"Czego dotyczy wydatek (art. spozywcze, mieszkanie...): ";
    expense.setItem(AuxiliaryMethods::getLine());

    cout<<"Podaj kwote wydatku: ";
    cin.sync();
    expense.setAmount(AuxiliaryMethods::getFloatAmount());

    saveNewExpense(expense);
}

void EntryManager::saveNewExpense(Expense newExpense) {
    CMarkup xml;
    bool fileExists = xml.Load("Expenses.xml");
    if(!fileExists) {
        xml.AddElem("EXPENSES");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("EXPENSE");
    xml.IntoElem();
    xml.AddElem("expenseId", newExpense.getExpenseId());
    xml.AddElem("userId", newExpense.getUserId());
    xml.AddElem("date", newExpense.getDate());
    xml.AddElem("item", newExpense.getItem());
    xml.AddElem("amount", AuxiliaryMethods::floatToStringConversion(newExpense.getAmount()));
    xml.OutOfElem();
    xml.Save("Expenses.xml");

    cout<<endl<<"Nowy wydatek zostal zapisany!"<<endl;
    system("pause");
}

void EntryManager::addExpense(int loggedInUserId) {
    getExpenseData(loggedInUserId);
}

int EntryManager::getNewExpenseId() {
    int counter=0;
    CMarkup xml;
    bool fileExists = xml.Load("Expenses.xml");
    if(!fileExists) {
        xml.AddElem("EXPENSES");
    }
    xml.FindElem();
    xml.IntoElem();

    while(xml.FindElem("EXPENSE")) {
        counter += 1;
    }
    return counter+1;
}

void EntryManager::getIncomeData(int loggedInUserId) {
    Income income;
    Dates dates;

    income.setIncomeId(getNewIncomeId());
    income.setUserId(loggedInUserId);
    income.setDate(dates.chooseDate("przychodu", "przychod"));
    cout<<"Czego dotyczy przychod (wynagrodzenie, odsetki...): ";
    income.setItem(AuxiliaryMethods::getLine());

    cout<<"Podaj kwote przychodu: ";
    income.setAmount(AuxiliaryMethods::getFloatAmount());
    saveNewIncome(income);
}

void EntryManager::saveNewIncome(Income newIncome) {
    CMarkup xml;
    bool fileExists = xml.Load("Incomes.xml");
    if(!fileExists) {
        xml.AddElem("INCOMES");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("INCOME");
    xml.IntoElem();
    xml.AddElem("incomeId", newIncome.getIncomeId());
    xml.AddElem("userId", newIncome.getUserId());
    xml.AddElem("date", newIncome.getDate());
    xml.AddElem("item", newIncome.getItem());
    xml.AddElem("amount", AuxiliaryMethods::floatToStringConversion(newIncome.getAmount()));
    xml.OutOfElem();
    xml.Save("Incomes.xml");

    cout<<endl<<"Nowy przychod zostal zapisany!"<<endl;
    system("pause");
}

void EntryManager::addIncome(int loggedInUserId) {
    getIncomeData(loggedInUserId);
}

int EntryManager::getNewIncomeId() {
    int counter=0;
    CMarkup xml;
    bool fileExists = xml.Load("Incomes.xml");
    if(!fileExists) {
        xml.AddElem("INCOMES");
    }
    xml.FindElem();
    xml.IntoElem();

    while(xml.FindElem("INCOME")) {
        counter += 1;
    }
    return counter+1;
}
