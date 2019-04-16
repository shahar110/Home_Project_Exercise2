#include "VisitationForm.h"

VisitForm::VisitForm(const Date& date, const char* purpose, int therapistNum, const char* therapistName, const char* departmentName) : arrivalDate(date)
{
	setPurpose(purpose);
	setTherapist(therapistNum, therapistName);
	setDepartmentName(departmentName);
}

bool VisitForm::setDate(const Date& newDate)
{
	arrivalDate = newDate;
	return true;
}

bool VisitForm::setPurpose(const char* newPurpose)
{
	delete[]purpose;
	purpose = new char[strlen(newPurpose) + 1];
	strcpy(purpose, newPurpose);
	return true;
}

bool VisitForm::setTherapist(int newNum, const char* newName)
{
	delete[]therapistName;
	therapistName = new char[strlen(newName) + 1];
	strcpy(therapistName, newName);
	therapistNum = newNum;
	return true;
}

bool VisitForm::setDepartmentName(const char* newDepartment)
{
	delete[]departmentName;
	departmentName = new char[strlen(newDepartment) + 1];
	strcpy(departmentName, newDepartment);
	return true;
}

bool VisitForm::setDepartmentIndex(int index)
{
	departmentPatientIndex = index;
	return true;
}
Date VisitForm::getDate() const
{
	return arrivalDate;
}

const char* VisitForm::getPurpose() const
{
	return purpose;
}

int VisitForm::getTherapist() const
{
	return therapistNum;
}

const char* VisitForm::getDepartment() const
{
	return departmentName;
}

void VisitForm::printVisitForm()
{
	cout << "Department: " << departmentName << "    , Arrival Date: ";
	arrivalDate.printDate(); 
	cout << "   , Visit Purpose: " << purpose << "   , Assigned Therapist: " << therapistName;  
}