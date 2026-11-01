#pragma once
#include <iostream>
#include <string>
#include "role.h"
#include "utils.h"

class User
{
protected:
    Role role;
    std::string login;
    unsigned long long passwordHash;
    std::string accountID;

public:
    User(const Role &role, const std::string &login, const std::string &password, const std::string &accountID) : role(role), login(login), passwordHash(Utils::hashPassword(password)), accountID(accountID) {}

    void setLogin(const std::string &login) { this->login = login; }
    void setPassword(const std::string &password) { this->passwordHash = Utils::hashPassword(password); }
    void setRole(const Role &role) { this->role = role; }

    std::string getLogin() const { return login; }
    Role getRole() const { return role; }
    std::string getRoleName() const;
    std::string getAccountID() const { return accountID; }

    bool checkPassword(const std::string &password) const
    {
        if (Utils::hashPassword(password) == passwordHash)
            return true;
        return false;
    }

    void print(std::ostream &out) const;
};