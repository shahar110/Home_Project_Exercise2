#include "VisitationForm.h"

VisitForm::VisitForm(const Date& date, int purpose, int therapistNum, const char* therapistName, const char* departmentName) : arrivalDate(date)
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

bool VisitForm::setPurpose(int newPurpose)
{
	purpose = newPurpose;
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

int VisitForm::getPurpose() const
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
	if (this->purpose == CHECK) cout <<endl<< " And he is in checking";
	else cout <<endl<< " And he is in surgery";
}


// checking changing 