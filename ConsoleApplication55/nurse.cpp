#define _CRT_SECURE_NO_WARNINGS
#include "nurse.h"


Nurse::Nurse(const char * name, int experience) : StaffMember(name)
{
	setExperience(experience);
}

Nurse::~Nurse()
{
}

bool Nurse::setExperience(int experience)
{
	this->experience = experience;
	return true;
}

int Nurse::getExperience() const
{
	return experience;
}

void Nurse::print() const
{
	cout << "Nurse name: " << name << "   , years of experience: " << experience
		<< "   , ID: " << employeeNum;
}
