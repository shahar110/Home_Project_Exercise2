#ifndef __VISITATION_FORM_H
#define __VISITATION_FORM_H

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
#include "date.h"

//enum ePurpose { Treatment, Medicine ,Emergency, Visit, Reception };
//namespace { const char* visitPurpose[] = { "Treatment", "Medicine", "Emergency", "Visit", "Reception" }; }

class VisitForm
{
protected:
	Date arrivalDate;
	int purpose;   

	char* therapistName;
	int therapistNum;	

	char* departmentName;
	int departmentPatientIndex = -1;

public:
	VisitForm(const Date& date, int purpose, int therapistNum, const char* therapistName,  const char* departmentName);

	bool setDate(const Date& newDate);
	bool setPurpose(int newPurpose);
	bool setTherapist(int therapistNum, const char* therapistName);
	bool setDepartmentName(const char* newDepartment);
	bool setDepartmentIndex(int index);

	Date getDate() const;
	int getPurpose() const;
	int getTherapist() const;
	const char* getDepartment() const;

	void printVisitForm();
};

#endif