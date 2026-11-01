#pragma once
#include <iostream>
#include "account.h"

class Card
{
protected:
    static long int cardNumber;
    static int cardCVC;
    long int number;
    int CVC;
    Account *owner;

public:
    Card() : number(0), CVC(0), owner(nullptr) {}

    void createCardNumber()
    {
        cardNumber += 1000;
        number = cardNumber;
    }

    void createCVC()
    {
        cardCVC++;
        CVC = cardCVC;
    }

    void setOwner(Account *owner) { this->owner = owner; }

    int getCVC() const { return CVC; }

    long int getNumber() const { return number; }

    Account *getOwner() const { return owner; }

    void print(std::ostream &out) const;

    ~Card() {}
};
