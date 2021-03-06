#ifndef __HOSTPITAL_H
#define __HOSTPITAL_H

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
#include "Patient.h"
#include "doctor.h"
#include "SurgeonDoc.h"
#include "nurse.h"
#include "researcher.h"
#include "department.h"
#include "ResearchDoc.h"

class Hospital
{
private:
	string name;
	Department** departmentArr;
	Doctor** doctorsArr;
	Nurse** nursesArr;
	Patient** patientArr;
	Researcher** researchersArr;

	int numOfDepartments = 0;
	int physDepartmentsArr = 2;

	int numOfDoctors = 0;
	int physDoctorsArr = 2;

	int numOfNurses = 0;
	int physNursesArr = 2;

	int numOfPatients = 0;
	int physPatientArr = 2;

	int numOfResearchers = 0;
	int physResearchersArr = 2;

	static int employeeCounter;

public:
	Hospital(const string& name);
	~Hospital();

	bool setName(const string& newName);

	void addDepartment(const string& departmentName);
	int getNumOfDepartments() const;
	Department** getDeparmentsArr();

	void addNurse(const string& nurseName, int years, int depratmentIndex);
	int getNumOfNurses() const;
	Nurse** getNursesArr();

	void addDoctor(const string& doctorName, const string& expertise, int depratmentIndex);
	void addSurgeon(const string& doctorName, const string& expertise, int depratmentIndex, int numOfSurgeries);
	int getNumOfDoctors() const;
	Doctor** getDoctorsArr();

	void addPatient(const string& patientName, int patientId, int birthYear, eGender patientGender, int depratmentIndex);
	int getNumOfPatients() const;
	Patient** getPatientsArr();
	int findPatientIndex(int id);
	void changePatientDepartment(int patientId, int newDepartmentIndex);

	void addResearcher(const string& researcherName);
	int getNumOfResearchers() const;
	Researcher** getResearchersArr();

	void addResearchDoctor(const string& doctorName, const string& expertise, int depratmentIndex);
};

#endif;