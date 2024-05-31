#include "FullTimeEmployee.h"
#include "PartTimeEmployee.h"
#include <iostream>
#include <string>
#include <limits>

using namespace std;

Employee *createEmployee() {
    int type;
    int id;
    string name;

    cout << "1. Full Time" << endl;
    cout << "2. Part Time" << endl;
    cout << "고용자의 유형을 선택하세요 >> ";
    cin >> type;

    if (type < 1 || type > 2)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw "잘못된 선택입니다.";
    }

    cout << "고용인 아이디 입력: ";
    cin >> id;
    cin.ignore();
    cout << "고용인 이름 입력: ";
    getline(cin, name);

    switch (type)
    {
        case 1:
            int salary;
            cout << "월급 입력: ";
            cin >> salary;
            return new FullTimeEmployee(id, name, salary);
        default:
            int hourlyWage, hoursWorked;
            cout << "시급 입력: ";
            cin >> hourlyWage;
            cout << "근로 시간 입력: ";
            cin >> hoursWorked;
            return new PartTimeEmployee(id, name, hourlyWage, hoursWorked);
    }
}

int main()
{
    const int NUM_OF_WORKERS = 4;
    Employee *workers[NUM_OF_WORKERS];
    int i = 0;

    while (i < NUM_OF_WORKERS) 
    {
        try {
            workers[i] = createEmployee();
            i++;
        } catch (const char *err) {
            cerr << err << endl;
        }
    }

    for (int i = 0; i < NUM_OF_WORKERS; i++)
    {
        cout << endl;
        workers[i]->printInfo(cout);
        cout << "이번달 급여는 " << workers[i]->calculatePay() << "원입니다." << endl;
    }
    
    for (int i = 0; i < NUM_OF_WORKERS; i++) 
        delete workers[i];


    return 0;
}