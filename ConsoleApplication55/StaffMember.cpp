#include "StaffMember.h"

int StaffMember::employeeNumCounter = 0;

StaffMember::StaffMember(const char * name)
{
	employeeNumCounter++;
	employeeNum = employeeNumCounter;
	setName(name);
}

StaffMember::~StaffMember()
{
	delete[]name;
}

bool StaffMember::setName(const char* tmpName)
{
	delete[]name;
	name = new char[strlen(tmpName) + 1];
	strcpy(name, tmpName);
	return true;
}

const char * StaffMember::getName() const
{
	return name;
}

int StaffMember::getEmployeeNum() const
{
	return employeeNum;
}
