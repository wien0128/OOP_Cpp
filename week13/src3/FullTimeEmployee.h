#ifndef _FULL_H
#define _FULL_H

#include "Employee.h"

class FullTimeEmployee : virtual public Employee {
private:
    int salary;
public:
    FullTimeEmployee(int id, const string& name, int salary) : Employee(id, name), salary(salary) {}
    ~FullTimeEmployee() override {}
    void printInfo(ostream& out) const override;
    int calculatePay() const override;
};


#endif