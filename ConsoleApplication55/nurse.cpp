#include "nurse.h"
#include <iostream>
#include <string>
using namespace std;


Nurse::Nurse(const char* name, int num, int profession) : name(nullptr)
{
	setName(name);
	setemployeeNum(num);
	setexperience(profession);
}

Nurse::Nurse(const Nurse& other)
{
	setName(other.name);
	setemployeeNum(other.employeeNum);
	setexperience(other.experience);
}

Nurse::~Nurse()
{
	delete[]name;
}

bool Nurse::setName(const char* tmpName)
{
	delete[]name;
	name = new char[strlen(tmpName) + 1];
	strcpy(name, tmpName);
	return true;
}

bool Nurse::setemployeeNum(int tmpNum)
{
	employeeNum = tmpNum;
	return true;
}

bool Nurse::setexperience(int profession)
{
	experience = profession;
	return true;
}

const char* Nurse::getName() const
{
	return name;
}
int Nurse::getexperience() const
{
	return experience;
}
int Nurse::getemployeeNum() const
{
	return employeeNum;
}

void Nurse::print() const
{
	cout << "Nurse name is: " << name << " and her employee number is: " << employeeNum
		<< " and her experience years is: " << experience;
}
