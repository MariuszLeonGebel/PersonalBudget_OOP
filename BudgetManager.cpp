#include "BudgetManager.h"

void BudgetManager::createIncomeExpensesStatement(int loggedInUserId, int periodSelection) {
    Dates dates;
    string strMonth="", periodBegin="", periodEnd="";
    int selectedMonth, selectedYear;

    if (periodSelection != 2) {
        selectedMonth = dates.getCurrentMonth();
        selectedYear = dates.getCurrentYear();
        if(selectedMonth==1 && periodSelection==1) {
            selectedMonth = 12;
            selectedYear -= 1;
        } else {
            selectedMonth -= periodSelection;
        }

        if (selectedMonth<10) strMonth = "0"+AuxiliaryMethods::intToStrConversion(selectedMonth);
        else strMonth = AuxiliaryMethods::intToStrConversion(selectedMonth);

        periodBegin = AuxiliaryMethods::intToStrConversion(selectedYear)+"-" + strMonth +"-01";
        periodEnd = AuxiliaryMethods::intToStrConversion(selectedYear)+"-" + strMonth +"-" +
                    AuxiliaryMethods::intToStrConversion(dates.getNumberOfDaysInMonth(selectedMonth, selectedYear));

    } else {
Again:
        periodBegin = dates.enterDate("poczatkowa zestawienia");
        periodEnd = dates.enterDate("koncowa zestawienia");

        if(periodEnd<periodBegin) {
            cout<<"Okres koncowy jest wczesniejszy niz poczatkowy!"<<endl;
            goto Again;
        }
    }
    showBudgetData(periodBegin, periodEnd, loggedInUserId);
}

void BudgetManager::showBudgetData(string periodBegining, string periodEnd, int loggedInUserId) {
    CMarkup xml;
    vector <Income> incomes;
    vector <Expense> expenses;
    FileOperations file;
    float incomeSum=0, expenseSum=0;

    incomes = file.getIncomesData(periodBegining, periodEnd, loggedInUserId);
    expenses = file.getExpensesData(periodBegining, periodEnd, loggedInUserId);

    cout<<endl<<"PRZYCHODY"<<endl;
    cout<<"------------------------------------------------------"<<endl;
    sort(incomes.begin(), incomes.end());
    for(auto x : incomes) {
        cout<<x.getDate()<<"  ";
        cout.width(30);
        cout<<x.getItem()<<"  ";
        cout.width(7);
        incomeSum += x.getAmount();
        printf("%.2f\n", x.getAmount());
    }

    cout<<endl<<"WYDATKI"<<endl;
    cout<<"------------------------------------------------------"<<endl;
    sort(expenses.begin(), expenses.end());
    for(auto x : expenses) {
        cout<<x.getDate()<<"  ";
        cout.width(30);
        cout<<x.getItem()<<"  ";
        cout.width(7);
        expenseSum += x.getAmount();
        printf("%.2f\n", x.getAmount());
    }
    cout<<"------------------------------------------------------"<<endl;
    cout<<"Suma przychodow:\t\t\t    ";
    printf("%.2f\n", incomeSum);
    cout<<"Suma wydatkow  :\t\t\t    ";
    printf("%.2f\n", expenseSum);
    cout<<"------------------------------------------------------"<<endl;
    cout<<"Bilans         :\t\t\t    ";
    printf("%.2f\n", (incomeSum-expenseSum));
    cout<<endl;

    system("pause");
}


