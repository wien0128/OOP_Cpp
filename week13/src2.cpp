#include <iostream>

using namespace std;

class Calculator {
protected:
    int value1, value2;
public:
    friend istream &operator>>(istream &, Calculator &);
    virtual int calculate() const = 0;
};
istream &operator>>(istream &in, Calculator &calc) {
    return in >> calc.value1 >> calc.value2;
}

class Adder : public Calculator {
public:
    int calculate() const override {
        return value1 + value2;
    }
};

class Substractor : public Calculator {
public:
    int calculate() const override {
        return value1 - value2;
    }
};

void calculate(Calculator &calc) {
    cout << "두 개의 수를 입력하세요 >> ";
    cin >> calc;
    cout << "결과: " << calc.calculate() << endl;
}

int main()
{
    Adder adder;
    Substractor substractor;
    
    calculate(adder);
    calculate(substractor);

    return 0;
}