#pragma once
#include <exception>
#include <string>
// создаем класс банковских исключений
class BankException : public std::exception
{
protected:
    std::string message;

public:
    BankException(const std::string &message) : message(message) {}
    const char *what() const noexcept override { return message.c_str(); }
};
// исключение, если неправильный формат введенной суммы
class InvalidInputException : public BankException
{
public:
    InvalidInputException(const std::string &message) : BankException(message) {}
};
// исключение, если недостаточно денежных средств
class NotEnoughMoneyException : public BankException
{
public:
    NotEnoughMoneyException(const std::string &message) : BankException(message) {}
};

// исключение, если невозможно открыть файл
class FileException : public BankException
{
public:
    FileException(const std::string &message) : BankException(message) {}
};