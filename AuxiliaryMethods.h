#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class AuxiliaryMethods {

public:
    static char selectOptionFromMainMenu();
    static char getChar();
    static char selectOptionFromUserMenu();
    static string intToStrConversion(int number);
    static int strToIntConversion(string number);
    static string floatToStringConversion(float number);
    static string getLine();
    static float getFloatAmount();
};

#endif // AUXILIARYMETHODS_H
