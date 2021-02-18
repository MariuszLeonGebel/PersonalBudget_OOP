#include "FileOperations.h"

int FileOperations::getNewUserId() {
    int counter=0;
    CMarkup xml;
    bool fileExists = xml.Load("Users.xml");
    if(!fileExists) {
        xml.AddElem("USERS");
    }
    xml.FindElem();
    xml.IntoElem();

    while(xml.FindElem("USER")) {
        counter += 1;
    }
    return counter+1;
}

void FileOperations::saveNewUser(User newUser) {
    CMarkup xml;
    bool fileExists = xml.Load("Users.xml");
    if(!fileExists) {
        xml.AddElem("USERS");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("USER");
    xml.IntoElem();
    xml.AddElem("userId", newUser.getId());
    xml.AddElem("login", newUser.getLogin());
    xml.AddElem("password", newUser.getPassword());
    xml.AddElem("name", newUser.getName());
    xml.AddElem("surname", newUser.getSurname());
    xml.OutOfElem();
    xml.Save("Users.xml");
}

bool FileOperations::isLoginExist(string login) {
    CMarkup xml;
    bool fileExists = xml.Load("Users.xml");
    if(!fileExists) {
        xml.AddElem("USERS");
    }
    xml.FindElem();
    xml.IntoElem();

    while(xml.FindElem("USER")) {
        xml.IntoElem();
        xml.FindElem("login");
        if (xml.GetData()==login) {
            cout<<"Login: "<<login<<" juz istnieje w programie!"<<endl;
            return true;
        }
        xml.OutOfElem();
    }
    return false;
}

bool FileOperations::isLoginNotExist(string login) {
    CMarkup xml;
    bool fileExists = xml.Load("Users.xml");
    if(!fileExists) {
        xml.AddElem("USERS");
    }
    xml.FindElem();
    xml.IntoElem();

    while(xml.FindElem("USER")) {
        xml.IntoElem();
        xml.FindElem("login");
        if (xml.GetData()==login) {
            return true;
        }
        xml.OutOfElem();
    }
    cout<<"Login: "<<login<<" NIE istnieje w programie!"<<endl;
    system("pause");
    return false;
}

int FileOperations::userLogIn() {
    string login = "", password = "", userPassword="";
    CMarkup xml;
    int loggedInUserId;

    do {
        cout << "Podaj login: ";
        login = AuxiliaryMethods::getLine();
    } while (isLoginNotExist(login) != true);

    bool fileExists = xml.Load("Users.xml");
    if(!fileExists) {
        xml.AddElem("USERS");
    }
    xml.FindElem();
    xml.IntoElem();
    while(xml.FindElem("USER")) {
        xml.IntoElem();
        xml.FindElem("login");
        if (xml.GetData()==login) {
            xml.FindElem("password");
            userPassword = xml.GetData();
            xml.ResetMainPos();
            xml.FindElem("userId");
            loggedInUserId = atoi(MCD_2PCSZ(xml.GetData()));
        }
        xml.OutOfElem();
    }

    for(int iloscProb = 3; iloscProb > 0; iloscProb--) {
        cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
        password = AuxiliaryMethods::getLine();
        if(password==userPassword) {
            cout<<endl<<"Zalogowales sie!"<<endl<<endl;
            system("pause");
            return loggedInUserId;
        }
    }
    cout<<endl<<"Wprowadzono 3 razy bledne haslo."<<endl<<endl;
    system("pause");
    return loggedInUserId = 0;
}

void FileOperations::passwordChange(int loggedInUserId) {
    string newPassword = "";
    cout << "Podaj nowe haslo: ";
    newPassword = AuxiliaryMethods::getLine();

    CMarkup xml;
    xml.Load("Users.xml");
    xml.FindElem();
    xml.IntoElem();
    while(xml.FindElem("USER")) {
        xml.IntoElem();
        xml.FindElem("userId");
        if (xml.GetData()==AuxiliaryMethods::intToStrConversion(loggedInUserId)) {
            xml.FindElem("password");
            xml.SetData(newPassword);
        }
        xml.OutOfElem();
    }
    xml.Save("Users.xml");
    cout << "Haslo zostalo zmienione." << endl << endl;
    system("pause");
}

vector <Income> FileOperations::getIncomesData(string periodBegining, string periodEnd, int loggedInUserId) {
    CMarkup xml;
    vector <Income> incomes;
    Income income;

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
    return incomes;
}

vector <Expense> FileOperations::getExpensesData(string periodBegining, string periodEnd, int loggedInUserId) {
    CMarkup xml;
    vector <Expense> expenses;
    Expense expense;

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
    return expenses;
}

void FileOperations::saveNewExpense(Expense newExpense) {
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

    cout<<endl<<"Nowy wydatek zostal zapisany!"<<endl<<endl;
    system("pause");
}

void FileOperations::saveNewIncome(Income newIncome) {
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

    cout<<endl<<"Nowy przychod zostal zapisany!"<<endl<<endl;
    system("pause");
}

int FileOperations::getNewExpenseId() {
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

int FileOperations::getNewIncomeId() {
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
