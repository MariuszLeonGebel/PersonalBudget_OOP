#include "Dates.h"

string Dates::enterDate(string description) {
    bool error;
    string enteredDate="";
    int checkY, checkM, checkD;
    do {
        error=false;
        cout<<endl<<"Podaj date "<<description<<": ";
        cin>>enteredDate;

        if(enteredDate.length()!=10) {
            error = true;
            goto Error;
        }

        checkY = AuxiliaryMethods::strToIntConversion(enteredDate.substr(0, 4));
        if (checkY < 2000 || checkY > getCurrentYear()) {
            error = true;
            goto Error;
        }

        checkM = AuxiliaryMethods::strToIntConversion(enteredDate.substr(5, 2));
        if (checkM < 1 || checkM > 12 || (checkY == getCurrentYear() && checkM > getCurrentMonth())) {
            error = true;
            goto Error;
        }
        checkD = AuxiliaryMethods::strToIntConversion(enteredDate.substr(8, 2));

        if (checkD < 1 || checkD > getNumberOfDaysInMonth(checkM, checkY)) {
            error = true;
            goto Error;
        }

        if(error == false) return enteredDate;
Error:
        cout<<endl<<"Nieprawidlowa data!"<<endl;
        cout<<"Program wymaga podania daty w formacie: \"rrrr-mm-dd\","<<endl;
        cout<<"w zakresie od 2000-01-01 do konca biezacego miesiaca!"<<endl;
    } while(error == true);
}

int  Dates::getNumberOfDaysInMonth(int month, int year) {
    if( month == 2) {
        if((year%400==0) || (year%4==0 && year%100!=0))
            return 29;
        else
            return 28;
    } else if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8
              ||month == 10 || month==12)
        return 31;
    else
        return 30;
}

string Dates::chooseDate(string description, string description1) {
    char sel;
    do {
        cout<<endl<<"Czy "<<description1<<" dotyczy dnia dzisiejszego <t/n>: ";
        cin>>sel;
        switch(sel) {
        case 'n':
        case 'N': {
            return enterDate(description);
        }
        case 't':
        case 'T': {
            return getCurrentDate();
        }
        default: {
            cout<<endl<<"Mozna wpisac tylko \"n\" lub \"t\"!. Wpisz odpowiednia litere jeszcze raz!"<<endl;
        }
        }
    } while(sel !='n' || sel !='N' || sel !='t' || sel !='T');
}

string Dates::getCurrentDate() {
    int cY, cM, cD;
    string currY, currM, currD;

    time_t now = time(0);
    tm *ltm = localtime(&now);
    cY = 1900+ltm->tm_year;
    cM = 1+ltm->tm_mon;
    cD = ltm->tm_mday;
    currY = AuxiliaryMethods::intToStrConversion(cY);
    if(cM < 10) currM = "0" + AuxiliaryMethods::intToStrConversion(cM);
    else currM = AuxiliaryMethods::intToStrConversion(cM);
    if(cD < 10) currD = "0" + AuxiliaryMethods::intToStrConversion(cD);
    else currD = AuxiliaryMethods::intToStrConversion(cD);
    return (currY+"-"+currM+"-"+currD);
}

int Dates::getCurrentYear() {
    int currentYear;
    time_t now = time(0);
    tm *ltm = localtime(&now);
    currentYear = 1900+ltm->tm_year;

    return currentYear;
}

int Dates::getCurrentMonth() {
    int currentMonth;
    time_t now = time(0);
    tm *ltm = localtime(&now);
    currentMonth = 1+ltm->tm_mon;

    return currentMonth;
}
