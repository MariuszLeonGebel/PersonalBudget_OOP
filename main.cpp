#include <iostream>
#include "Markup.h"
#include "PersonalBudget.h"
#include "AuxiliaryMethods.h"

using namespace std;

int main() {
    PersonalBudget personalBudget;
    char sel;
    while (true) {
        if (personalBudget.isUserLoggedIn() != true) {
            sel = AuxiliaryMethods::selectOptionFromMainMenu();
            switch (sel) {
            case '1':
                personalBudget.userRegistration();
                break;
            case '2':
                personalBudget.userLogIn();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        } else {
            sel = AuxiliaryMethods::selectOptionFromUserMenu();
            switch (sel) {
            case '1':
                personalBudget.addIncome(personalBudget.getUserId());
                break;
            case '2':
                personalBudget.addExpense(personalBudget.getUserId());
                break;
            case '3':
                personalBudget.createIncomeExpensesStatement(personalBudget.getUserId(), 0);
                break;
            case '4':
                personalBudget.createIncomeExpensesStatement(personalBudget.getUserId(), 1);
                break;
            case '5':
                personalBudget.createIncomeExpensesStatement(personalBudget.getUserId(), 2);
                break;
            case '6':
                personalBudget.passwordChange(personalBudget.getUserId());
                break;
            case '7':
                personalBudget.userLogOut();
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
    }
    return 0;
}
