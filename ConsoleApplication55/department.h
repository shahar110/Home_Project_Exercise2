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
	string name;
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
	Department(const string& departmentName);
	~Department();

	bool setName(const string& departmentName);
	bool addDoctor(Doctor* newDoctor);
	bool addNurse(Nurse* newNurse);
	bool addPatient(Patient* newPatient);
	bool setNumOfPatients(int num);

	const string& getName() const { return name; };
	Doctor** getAllDoctors();
	int getNumOfDoctors() const;
	Nurse** getAllNurses();
	int getNumOfNurses() const;
	Patient** getAllPatients();
	int getNumOfPatients() const;

	const string& selectStaffMember(int* staffMemberNum);

	void printDepartment() const;
	void printDepartmentStaff() const;
	void printPatientsList() const;
	bool operator+=(Doctor* newDoctor);
	bool operator+=(Nurse* newNurse);

};

#endif