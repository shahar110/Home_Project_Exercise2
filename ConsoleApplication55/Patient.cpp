#include "Patient.h"

Patient::Patient(const char* name, int id, int birthYear, eGender gender)
{
	setName(name);
	setId(id);
	setBirthYear(birthYear);
	setGender(gender);

	visitsArr = new VisitForm*[physVisitArr];
}

bool Patient::setName(const char* newName)
{
	delete[]name;
	name = new char[strlen(newName) + 1];
	strcpy(name, newName);
	return true;
}

bool Patient::setId(long newId)
{
	id = newId;
	return true;
}

bool Patient::setBirthYear(int newBirthYear)
{
	birthYear = newBirthYear;
	return true;
}

bool Patient::setGender(eGender newGender)
{
	gender = newGender;
	return true;
}

bool Patient::addVisit(const Date& arrivalDate, const char* purpose, int therapistNum, const char* therapistName, const char* departmentName)
{
	if (physVisitArr == visitHistoryCounter) {
		physVisitArr *= 2;

		VisitForm** temp = new VisitForm*[visitHistoryCounter];
		for (int i = 0; i < visitHistoryCounter; i++)
			temp[i] = visitsArr[i];

		delete[]visitsArr;

		visitsArr = new VisitForm*[physVisitArr];
		for (int i = 0; i < visitHistoryCounter; i++)
			visitsArr[i] = temp[i];

		delete[]temp;
	}

	//Add the new Visit Form to the Patient visits array
	visitsArr[visitHistoryCounter] = new VisitForm(arrivalDate, purpose, therapistNum, therapistName, departmentName);
	visitHistoryCounter++;
	return true;
}

bool Patient::setDepartmentIndex(int index)
{
	departmentIndex = index;
	return true;
}

bool Patient::setDepartmentPatientArrIndex(int index)
{
	departmentPatientArrIndex = index;
	return true;
}

const char* Patient::getName() const
{
	return name;
}

int Patient::getId() const
{
	return id;
}

int Patient::getBirthYear() const
{
	return birthYear;
}

eGender Patient::getGender() const
{
	return gender;
}

VisitForm** Patient::getVisitsArr() const
{
	return visitsArr;
}

int Patient::getDepartmentIndex() const
{
	return departmentIndex;
}

int Patient::getDepartmentPatientArrIndex() const
{
	return departmentPatientArrIndex;
}

//Department* Patient::getDepartment(int *departmentIndex) const
//{
//	*departmentIndex = departmentPatientIndex;
//	return department;
//}

int Patient::getVisitCounter() const
{
	return visitHistoryCounter;
}

void Patient::printPatient()
{
	cout << "Patient name: " << name << "   , ID: " << id << "   , Birth Year: " << birthYear << "   , Gender: " << genders[gender];
}

void Patient::printCurrentVisit()
{
	if (visitHistoryCounter > 0)
	{
		visitsArr[visitHistoryCounter - 1]->printVisitForm();
	}
	else
	{
		cout << "No visits recorded for the patient!\n";
	}
}