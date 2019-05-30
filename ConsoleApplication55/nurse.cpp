#define _CRT_SECURE_NO_WARNINGS
#include "nurse.h"


Nurse::Nurse(string name, int experience) : StaffMember(name)
{
	setExperience(experience);
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
