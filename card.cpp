#include <iostream>
#include <iomanip>
#include "card.h"

long int Card::cardNumber = 4000000;
int Card::cardCVC = 100;

void Card::print(std::ostream &out) const
{
    out << std::left << std::setw(16) << number << std::setw(8) << CVC;
    if (owner != nullptr)
    {
        out << owner->getSurname() << " " << owner->getName();
    }
    else
    {
        out << "-";
    }
    out << "\n";
}