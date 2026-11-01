#pragma once
#include <iostream>
#include <memory>
#include <iomanip>
#include "exceptions.h"

// class for sheduale of monthly payments

class PaymentSchedule
{
    int count;
    double *payments;

public:
    PaymentSchedule(int count, double monthlyPayment)
    {
        if (count <= 0)
            throw InvalidInputException("Срок должен быть больше нуля");
        this->count = count;
        this->payments = new double[count];
        for (int i = 0; i < count; i++)
        {
            payments[i] = monthlyPayment;
        }
    }

    // copy constructor
    PaymentSchedule(const PaymentSchedule &other) : count(other.count)
    {
        payments = new double[count];
        for (int i = 0; i < count; i++)
        {
            payments[i] = other.payments[i];
        }
    }

    double getTotal() const
    {
        double total = 0;
        for (int i = 0; i < count; i++)
        {
            total += payments[i];
        }
        return total;
    }

    void print(std::ostream &out) const
    {
        for (int i = 0; i < count; i++)
        {
            out << std::setw(5) << i + 1 << std::setw(10) << std::fixed << std::setprecision(2) << payments[i] << "\n";
        }
    }

    PaymentSchedule &operator=(const PaymentSchedule &other)
    {
        if (this->payments != other.payments)
        {
            delete[] this->payments;
            this->count = other.count;
            payments = new double[count];
            for (int i = 0; i < count; i++)
            {
                payments[i] = other.payments[i];
            }
        }
        return *this;
    }
    ~PaymentSchedule() { delete[] payments; }
};