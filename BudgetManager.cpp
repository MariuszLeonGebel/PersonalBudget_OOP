#include "BudgetManager.h"

void BudgetManager::createMonthBudget(int userId, int monthSelection) {
    Dates dates;
    string strMonth="", periodBegin="", periodEnd="";
    int selectedMonth, selectedYear;

    loggedInUserId = userId;
    if (monthSelection != 2) {
        selectedMonth = dates.getCurrentMonth();
        selectedYear = dates.getCurrentYear();
        if(selectedMonth==1 && monthSelection==1) {
            selectedMonth = 12;
            selectedYear -= 1;
        } else {
            selectedMonth -= monthSelection;
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
    getBudgetData(periodBegin, periodEnd);
}

void BudgetManager::getBudgetData(string periodBegining, string periodEnd) {
    CMarkup xml;
    vector <Income> incomes;
    vector <Expense> expenses;
    Income income;
    Expense expense;
    float incomeSum=0, expenseSum=0;

    xml.Load("Incomes.xml");
    xml.FindElem();
    xml.IntoElem();
    while(xml.FindElem("INCOME")) {
        xml.IntoElem();
        xml.FindElem("userId");
        if (xml.GetData()==AuxiliaryMethods::intToStrConversion(loggedInUserId)) {
            xml.FindElem("date");
            if(xml.GetData() >= periodBegining && xml.GetData()<= periodEnd) {
                income.setDate(xml.GetData());
                xml.FindElem("item");
                income.setItem(xml.GetData());
                xml.FindElem("amount");
                income.setAmount(stof(xml.GetData()));
                incomes.push_back(income);
            }
        }
        xml.OutOfElem();
    }

    xml.Load("Expenses.xml");
    xml.FindElem();
    xml.IntoElem();
    while(xml.FindElem("EXPENSE")) {
        xml.IntoElem();
        xml.FindElem("userId");
        if (xml.GetData()==AuxiliaryMethods::intToStrConversion(loggedInUserId)) {
            xml.FindElem("date");
            if(xml.GetData() >= periodBegining && xml.GetData()<= periodEnd) {
                expense.setDate(xml.GetData());
                xml.FindElem("item");
                expense.setItem(xml.GetData());
                xml.FindElem("amount");
                expense.setAmount(stof(xml.GetData()));
                expenses.push_back(expense);
            }
        }
        xml.OutOfElem();
    }

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


