#include <iostream>
#include <string>

using namespace std;

class Person {
private:
    string name;
    int age;
public:
    Person(const string& name = "", int age = 1) : name(name), age(age) {}
    const string& getName() const { return name; }
    int getAge() const { return age; }
};

class Student : virtual public Person {
    int score;
public:
    Student(int score = 0, const string& name = "", int age = 1)
        : score(score), Person(name, age) {}
    int getScore() const { return score; }
};

class Worker : virtual public Person {
    int salary;
public:
    Worker(int salary = 0, const string& name = "", int age = 1)
        : salary(salary), Person(name, age) {}
    int getSalary() const { return salary; }
};

class StudentWorker : public Student, public Worker {
public:
    StudentWorker(const string& name, int age, int score, int salary)
        : Person(name, age), Student(score), Worker(salary) {}
};

int main()
{
    StudentWorker sw("Kim", 20, 100, 3000000);
    cout << "name: " << sw.getName() << ", age: " << sw.getAge()
        << ", score: " << sw.getScore() << ", salary: " << sw.getSalary() << "\n";

    return 0;
}