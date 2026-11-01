#pragma once
#include <string>

// новое пространство имен
namespace Utils
{
    unsigned long long hashPassword(const std::string &password);

    std::string currentDate();
}
