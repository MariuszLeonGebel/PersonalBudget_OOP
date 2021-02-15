#include "AuxiliaryMethods.h"

char AuxiliaryMethods::selectOptionFromMainMenu() {
    char sel;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    sel = getChar();

    return sel;
}

char AuxiliaryMethods::getChar() {
    string text = "";
    char mark  = {0};

    while (true) {
        cin.clear();
        cin.sync();
        getline(cin, text);

        if (text.length() == 1) {
            mark = text[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie: ";
    }
    return mark;
}

float AuxiliaryMethods::getFloatAmount() {
    string stringNumber = "";
    float amount;
    int position=0;

    while(true) {
Error:
        getline(cin, stringNumber);
        for(int i=0; i<stringNumber.length(); i++) {
            char x = stringNumber.at(i);
            if(int(x)<44 || int(x)>57 || int(x)== 45 || int(x) ==47) {
                cout << "To nie jest liczba. Wpisz ponownie: ";
                goto Error;
            }

            if(stringNumber[i]==',') {
                position=i;
                stringNumber = stringNumber.replace(position, 1, ".");
            }
        }
        amount = stof(stringNumber);

        return amount;
    }
}

char AuxiliaryMethods::selectOptionFromUserMenu() {
    char sel;

    system("cls");
    cout << "    >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "--------------------------------" << endl;
    cout << "1. Dodaj przychod" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Bilans biezacego miesiaca" << endl;
    cout << "4. Bilans poprzedniego miesiaca" << endl;
    cout << "5. Bilans z wybranego okresu" << endl;
    cout << "--------------------------------" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "7. Wyloguj sie" << endl;
    cout << "--------------------------------" << endl;
    cout << "Twoj wybor: ";
    sel = getChar();

    return sel;
}

string AuxiliaryMethods::intToStrConversion(int number) {
    ostringstream ss;
    ss << number;
    string str = ss.str();

    return str;
}

int AuxiliaryMethods::strToIntConversion(string number) {
    int intNumber;
    istringstream iss(number);
    iss >> intNumber;

    return intNumber;
}

string AuxiliaryMethods::floatToStringConversion(float number) {
    stringstream sstream;
    sstream << number;
    string num_str = sstream.str();

    return num_str;
}

string AuxiliaryMethods::getLine() {
    string text = "";
    cin.clear();
    cin.sync();
    getline(cin, text);

    return text;
}

