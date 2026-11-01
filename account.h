#pragma once
#include <iostream>
#include <string>

class Account
{
protected:
    std::string name;
    std::string surname;
    int age;
    std::string passportID;
    std::string accountID;
    double balance;
    static int counter;

public:
    Account(std::string name = "None", std::string surname = "None",
            int age = 18, std::string passportID = "PB1236547897RT23", double balance = 0.0);

    void setName(std::string name) { this->name = name; }
    void setAge();
    void setSurname(std::string surname) { this->surname = surname; }
    void setPassportID();
    void setBalance(double balance) { this->balance = balance; }

    std::string getName() const { return name; }
    std::string getSurname() const { return surname; }
    int getAge() const { return age; }
    std::string getPassportID() const { return passportID; }
    std::string getAccountID() const { return accountID; }
    double getBalance() const { return balance; }

    void print(std::ostream &out) const;
    bool operator<(const Account &other) const { return surname < other.surname; }

    ~Account() {}
};
