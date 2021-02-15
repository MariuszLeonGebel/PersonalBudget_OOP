#include "PersonalBudget.h"

bool PersonalBudget::isUserLoggedIn() {
    userManager.isUserLoggedIn();
}

void PersonalBudget::userRegistration() {
    userManager.userRegistration();
}

void PersonalBudget::userLogIn() {
    userManager.userLogIn();
}

void PersonalBudget::userLogOut() {
    userManager.userLogOut();
}

void PersonalBudget::passwordChange() {
    userManager.passwordChange();
}

int PersonalBudget::getUserId() {
    return userManager.getUserId();
}

void PersonalBudget::addIncome(int getUserId) {
    entryManager.addIncome(getUserId);
}

void PersonalBudget::addExpense(int getUserId) {
    entryManager.addExpense(getUserId);
}

void PersonalBudget::createMonthBudget(int getUserId, int no) {
    budgetManager.createMonthBudget(getUserId, no);
}
