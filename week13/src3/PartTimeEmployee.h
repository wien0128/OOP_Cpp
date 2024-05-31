#ifndef _PART_H
#define _PART_H

#include "Employee.h"

class PartTimeEmployee : virtual public Employee {
private:
    int hourlyWage;
    int hoursWorked;
public:
    PartTimeEmployee(int id, const string& name, int hWage, int hWork) : Employee(id, name), hourlyWage(hWage), hoursWorked(hWork) {}
    ~PartTimeEmployee() {}
    void printInfo(ostream& out) const override;
    int calculatePay() const override;
};


#endif