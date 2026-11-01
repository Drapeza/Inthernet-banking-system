#include "user.h"
#include <iomanip>
#include "role.h"
#include <iostream>

std::string User::getRoleName() const
{
    if (role == Role::Admin)
        return "Администратор";
    return "Клиент";
}

void User::print(std::ostream &out) const
{
    out << std::left << std::setw(9) << accountID << std::setw(12) << login
        << std::setw(12) << getRoleName() << "\n";
}