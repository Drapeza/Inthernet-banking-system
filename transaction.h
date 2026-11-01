#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "utils.h"

class Transaction
{
    static int transactionNumber;
    double amount = 0;
    std::string fromID;
    std::string toID;
    std::string date;
    std::string transactionID;
    std::string type;

public:
    Transaction() {}
    Transaction(const std::string &fromID, const std::string &toID, double amount,
                const std::string &type) : fromID(fromID), toID(toID), amount(amount), type(type)
    {
        transactionNumber++;
        transactionID = "TR" + std::to_string(transactionNumber);
        this->date = Utils::currentDate();
    }

    double getAmount() const { return amount; }
    std::string getFromID() const { return fromID; }
    std::string getToID() const { return toID; }
    std::string getDate() const { return date; }
    std::string getTransactionID() const { return transactionID; }
    std::string getType() const { return type; }

    void print(std::ostream &out) const;
};