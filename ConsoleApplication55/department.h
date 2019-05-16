#ifndef __DEPARTMENT_H
#define __DEPARTMENT_H
#define _CRT_SECURE_NO_WARNINGS
#include "doctor.h"
#include "nurse.h"
#include "patient.h"
#include <iostream>
#include <string>

class Department
{
private:
	char* name;
	Doctor** allDoctors;
	Nurse** allNurses;
	Patient** allPatients;

	int numOfDoctors = 0;
	int physDoctorArr = 2;

	int numOfNurses = 0;
	int physNursesArr = 2;

	int numOfPatients = 0;
	int physPatientsArr = 2;

public:
	Department(const char* departmentName);
	~Department();

	bool setName(const char* departmentName);
	bool addDoctor(Doctor* newDoctor);
	bool addNurse(Nurse* newNurse);
	bool addPatient(Patient* newPatient);
	bool setNumOfPatients(int num);

	const char* getName() const;
	Doctor** getAllDoctors();
	int getNumOfDoctors() const;
	Nurse** getAllNurses();
	int getNumOfNurses() const;
	Patient** getAllPatients();
	int getNumOfPatients() const;

	char* selectStaffMember(int* staffMemberNum);

	void printDepartment() const;
	void printDepartmentStaff() const;
	void printPatientsList() const;
	bool operator+=(Doctor* newDoctor);
	bool operator+=(Nurse* newNurse);

};

#endif