#include "doctor.h"
#include <iostream>
using namespace std;

Doctor::Doctor(const char* name, int employeeNum, const char* field) : name(nullptr), field(nullptr)
{
	setName(name);
	setEmployeeNum(employeeNum);
	setField(field);
}

Doctor::Doctor(const Doctor &other) : name(nullptr), field(nullptr)
{
	setName(other.name);
	setEmployeeNum(other.employeeNum);
	setField(other.field);
}

Doctor::~Doctor()
{
	delete[]name;
	delete[]field;
}

bool Doctor::setName(const char* tmpName)
{
	delete[]name;
	name = new char[strlen(tmpName) + 1];
	strcpy(name, tmpName);
	return true;
}
bool Doctor::setEmployeeNum(int tmpNum)
{
	employeeNum = tmpNum;
	return true;
}
bool Doctor::setField(const char* tmpField)
{
	delete[]field;
	field = new char[strlen(tmpField) + 1];
	strcpy(field, tmpField);
	return true;
}

const char* Doctor::getName() const
{
	return name;
}

int Doctor::getEmployeeNum() const
{
	return employeeNum;
}

const char* Doctor::getField()const
{
	return field;
}

void Doctor::print() const
{
	cout << "The name of the doctor is: " << name << "and his field is: " << field
		<< " and his num is: " << employeeNum;
}