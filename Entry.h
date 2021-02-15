#ifndef ENTRY_H
#define ENTRY_H

#include <iostream>
#include "AuxiliaryMethods.h"

using namespace std;

class Entry {
    int userId;
    string date;
    string item;
    float amount;

public:
    bool operator < (Entry& str) const {
        return (date < str.date);
    }
    void setUserId(int newUserId);
    void setDate(string newDate);
    void setItem(string newItem);
    void setAmount(float newAmount);

    int getUserId();
    string getDate();
    string getItem();
    float getAmount();
};

#endif // ENTRY_H
