#include "Entry.h"

void Entry::setUserId(int newUserId) {
    if (newUserId >=0)
        userId = newUserId;
}
void Entry::setDate(string newDate) {
    date = newDate;
}
void Entry::setItem(string newItem) {
    while(newItem=="") {
        cout<<"Nie podano opisu transakcji! Wprowadz opis jeszcze raz: ";
        cin.sync();
        newItem = AuxiliaryMethods::getLine();
    }
    item = newItem;
}
void Entry::setAmount(float newAmount) {
    amount = newAmount;
}

int Entry::getUserId() {
    return userId;
}
string Entry::getDate() {
    return date;
}
string Entry::getItem() {
    return item;
}
float Entry::getAmount() {
    return amount;
}
