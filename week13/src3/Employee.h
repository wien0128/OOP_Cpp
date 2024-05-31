#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H

#include <string>

using namespace std;

class Employee {
protected:
    int id;
    string name;
public:
    Employee(int id, const string& name) : id(id), name(name) {}
    virtual ~Employee() {}
    virtual void printInfo(ostream& out) const = 0;
    virtual int calculatePay() const = 0;
};


#endif