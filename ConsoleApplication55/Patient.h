#ifndef __PATIENT_H
#define __PATIENT_H

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "string.h"
using namespace std;
#include "VisitationForm.h"

enum eGender {Male, Female};
namespace { const char* genders[] = { "Male", "Female" }; }

class Patient
{
private:
	char* name;
	int id;
	int birthYear;
	eGender gender;

	VisitForm** visitsArr;
	int visitHistoryCounter = 0;
	int physVisitArr = 2;

	int departmentIndex = -1;
	int departmentPatientArrIndex = -1;

public:
	Patient(const char* name, int id, int birthYear, eGender gender);

	bool setName(const char* newName);
	bool setId(long newId);
	bool setBirthYear(int newBirthYear);
	bool setGender(eGender newGender);
	bool addVisit(const Date& arrivalDate, const char* purpose, int therapistNum, const char* therapistName, const char* departmentName);
	bool setDepartmentIndex(int index);
	bool setDepartmentPatientArrIndex(int index);

	const char* getName() const;
	int getId() const;
	int getBirthYear() const;
	eGender getGender() const;
	VisitForm** getVisitsArr() const;
	int getDepartmentPatientArrIndex() const;
	int getDepartmentIndex() const;
	int getVisitCounter() const;

	void printPatient();
	void printCurrentVisit();
};

#endif