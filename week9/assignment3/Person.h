#pragma once

#include <string>

using std::string;

class Person {
	string name;
public:
	Person() { name = ""; }
	Person(const string& name) { this->name = name; }
	const string& getName() const { return name; }
	void setName(const string& name) { this->name = name; }
};