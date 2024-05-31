#include "FullTimeEmployee.h"
#include <iostream>

void FullTimeEmployee::printInfo(ostream& out) const
{
    out << "--- Full-Time Employee ---\n"
        << "ID: " << this->id << "\n"
        << "Name: " << this->name << "\n"
        << "Salary " << this->calculatePay() << "\n";
}

int FullTimeEmployee::calculatePay() const
{
    return salary;
}