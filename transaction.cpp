#include "transaction.h"

int Transaction::transactionNumber = 0;
void Transaction::print(std::ostream &out) const
{
    out << std::left << std::setw(9) << transactionID << std::setw(20) << type
        << std::setw(12) << toID << std::setw(12) << fromID
        << std::setw(20) << std::fixed << std::setprecision(2) << amount
        << std::setw(20) << date << "\n";
}