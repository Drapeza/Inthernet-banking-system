#include <iostream>
#include <iomanip>
#include <string>
#include "account.h"

int Account::counter = 0;

Account::Account(std::string name, std::string surname, int age, std::string passportID, double balance)
    : name(name), surname(surname), age(age), passportID(passportID), balance(balance)
{
    counter++;
    accountID = "ACC" + std::to_string(counter);
}

void Account::setAge()
{
    int age;
    while (true)
    {
        std::cout << "\nВведите ваш возраст: ";
        std::cin >> age;

        if (std::cin.good() && age >= 18 && age <= 100)
        {
            std::cin.ignore(1000, '\n');
            break;
        }

        std::cin.clear();
        std::cout << "\nУказано невозможное значение возраста. Возраст клиента должен быть в диапазоне от 18 до 100.\n";
        std::cin.ignore(1000, '\n');
    }

    Account::age = age;
}

void Account::setPassportID()
{
    std::string number;
    while (true)
    {
        std::cout << "\nВведите идентификационный номер: ";
        std::getline(std::cin, number);
        int size = number.size();

        bool correct = true;
        for (int i = 0; i < size; i++)
        {
            if (!((number[i] >= '0' && number[i] <= '9') || (number[i] >= 'A' && number[i] <= 'Z')))
                correct = false;
        }

        if (std::cin.good() && correct == true && size == 16 && number.rfind("0", 0) != 0)
        {
            break;
        }

        std::cin.clear();
        std::cout << "\nУказан несуществующий идентификационный номер. Повторите ввод.\n";
    }

    Account::passportID = number;
}

void Account::print(std::ostream &out) const
{
    out << std::left << std::setw(9) << accountID << std::setw(15) << surname
        << std::setw(12) << name << std::setw(9) << age << std::setw(20) << passportID
        << std::fixed << std::setprecision(2) << balance << "\n";
}
