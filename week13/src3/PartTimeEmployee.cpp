#include "PartTimeEmployee.h"
#include <iostream>


void PartTimeEmployee::printInfo(ostream& out) const
{
    out << "--- Part-Time Employee ---\n"
        << "ID: " << this->id << "\n"
        << "Name: " << this->name << "\n"
        << "Hourly Wage: " << this->hourlyWage << "\n"
        << "Hours Worked: " << this->hoursWorked << "\n";
}

int PartTimeEmployee::calculatePay() const
{
    return hourlyWage * hoursWorked;
}