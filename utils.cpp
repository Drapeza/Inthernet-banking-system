#include "utils.h"
#include <ctime>

unsigned long long Utils::hashPassword(const std::string &password)
{
    unsigned long long h = 5381;
    for (size_t i = 0; i < password.length(); i++)
    {
        h = h * 31 + static_cast<unsigned char>(password[i]);
    }
    return h;
}

std::string Utils::currentDate()
{
    std::time_t t = std::time(nullptr);
    char buf[20];
    std::strftime(buf, sizeof(buf), "%d.%m.%Y %H:%M", std::localtime(&t));
    return std::string(buf);
}
