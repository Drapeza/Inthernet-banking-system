#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <memory>
#include "paymentSchedule.h"

class BankProduct
{
protected:
    std::string productName;
    double amount;
    double percent;
    std::string accountID = "-";

public:
    BankProduct(const std::string &productName, double amount, double percent) : productName(productName), amount(amount), percent(percent) {}

    void setPercent(double percent) { this->percent = percent; }
    void setAmount(double amount) { this->amount = amount; }
    void setAccountID(const std::string &accountID) { this->accountID = accountID; }

    double getAmount() const { return amount; }
    std::string getName() const { return productName; }
    double getPercent() const { return percent; }
    std::string getAccountID() const { return accountID; }

    virtual void print(std::ostream &out) const = 0;
    virtual double calculate() const = 0;
    virtual std::string getType() const = 0;

    virtual ~BankProduct() {}
};

class Deposit : public BankProduct
{
public:
    Deposit(const std::string &name, double amount, double percent)
        : BankProduct(name, amount, percent) {}

    void print(std::ostream &out) const override
    {
        out << std::left << std::setw(15) << "Депозит" << std::setw(20) << productName
            << std::fixed << std::setprecision(2) << std::setw(12) << amount
            << std::setw(10) << percent << std::setw(8) << "-"
            << std::setw(12) << calculate() << "\n";
    }

    std::string getType() const override { return "Deposit"; }
    double calculate() const override
    {
        return amount * percent / 100.0 / 12.0;
    }

    ~Deposit() {}
};

class Credit : public BankProduct
{
private:
    int months;
    std::unique_ptr<PaymentSchedule> schedule;

public:
    Credit(const std::string &name, double amount, double percent, int months)
        : BankProduct(name, amount, percent), months(months)
    {
        schedule = std::make_unique<PaymentSchedule>(months, calculate());
    }

    void print(std::ostream &out) const override
    {
        out << std::left << std::setw(15) << "Кредит" << std::setw(20) << productName
            << std::fixed << std::setprecision(2) << std::setw(12) << amount
            << std::setw(10) << percent << std::setw(8) << months
            << std::setw(12) << calculate() << "\n";
    }

    std::string getType() const override { return "Credit"; }
    double calculate() const override
    {
        if (months <= 0)
            return 0;
        double monthlyBody = amount / months;
        double monthlyPercent = amount * percent / 100.0 / 12.0;
        return monthlyBody + monthlyPercent;
    }

    ~Credit() {}
};

class TermDeposit : public Deposit
{
protected:
    int months;
public:
    TermDeposit(const std::string &name, double amount, double percent, int months) : Deposit(name, amount, percent), months(months) {}

    void print(std::ostream &out) const override
    {
        out << std::left << std::setw(15) << "Срочный вклад" << std::setw(20) << productName
            << std::fixed << std::setprecision(2) << std::setw(12) << amount
            << std::setw(10) << percent << std::setw(8) << months
            << std::setw(12) << calculate() << "\n";
    }
    double calculate() const override
    {
        if (months <= 0)
            return 0;
        double monthProfit = amount * (percent + 1) / 100 / 12;
        return monthProfit;
    }

    std::string getType() const override { return "TermDeposit"; }
};
