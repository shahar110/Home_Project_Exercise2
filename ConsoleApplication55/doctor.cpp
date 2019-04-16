#define _CRT_SECURE_NO_WARNINGS
#include "doctor.h"

Doctor::Doctor(const char* name, const char* expertise) : StaffMember(name)
{
	setExpertise(expertise);
}

Doctor::~Doctor()
{
	delete[]expertise;
}

bool Doctor::setExpertise(const char* tmpExpertise)
{
	delete[]expertise;
	expertise = new char[strlen(tmpExpertise) + 1];
	strcpy(expertise, tmpExpertise);
	return true;
}

const char* Doctor::getExpertise() const
{
	return expertise;
}

void Doctor::print() const
{
	cout << "Doctor name: " << name << " , field of expertise: " << expertise
		<< " , ID: " << employeeNum;
}