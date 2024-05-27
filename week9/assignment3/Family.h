#pragma once

#include <string>
#include "Person.h"

class Family {
	string name;
	Person* p;
	int size;
public:
	Family(const string& name, int size);
	~Family();
	void setName(int index, const string& name);
	void show() const;
};