#include "EntryManager.h"

void EntryManager::getExpenseDataFromUser(int loggedInUserId) {
    Expense expense;
    Dates dates;
    FileOperations file;

    expense.setExpenseId(file.getNewExpenseId());
    expense.setUserId(loggedInUserId);
    expense.setDate(dates.chooseDate("wydatku", "wydatek"));
    cout<<"Czego dotyczy wydatek (art. spozywcze, mieszkanie...): ";
    expense.setItem(AuxiliaryMethods::getLine());

    cout<<"Podaj kwote wydatku: ";
    cin.sync();
    expense.setAmount(AuxiliaryMethods::getFloatAmount());

    file.saveNewExpense(expense);
}

void EntryManager::addExpense(int loggedInUserId) {
    getExpenseDataFromUser(loggedInUserId);
}

void EntryManager::getIncomeDataFromUser(int loggedInUserId) {
    Income income;
    Dates dates;
    FileOperations file;

    income.setIncomeId(file.getNewIncomeId());
    income.setUserId(loggedInUserId);
    income.setDate(dates.chooseDate("przychodu", "przychod"));
    cout<<"Czego dotyczy przychod (wynagrodzenie, odsetki...): ";
    income.setItem(AuxiliaryMethods::getLine());

    cout<<"Podaj kwote przychodu: ";
    income.setAmount(AuxiliaryMethods::getFloatAmount());
    file.saveNewIncome(income);
}

void EntryManager::addIncome(int loggedInUserId) {
    getIncomeDataFromUser(loggedInUserId);
}

