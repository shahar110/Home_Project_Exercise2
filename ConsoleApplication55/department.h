#ifndef __DEPARTMENT_H
#define __DEPARTMENT_H
#include "doctor.h"
#include "nurse.h"


const int NAME_LENGTH = 20;

class Department
{
private:
	char* name;
	Doctor** allDoctors;
	Nurse** allNurses;
	int numOfDoctors;
	int numOfNurses;
	

public:
	Department(const char* departmentName);
	Department(const Department& other);
	~Department();

	const char* getName() const;
	Doctor** getAllDoctors();
	int getNumOfDoctors() const;
	Nurse** getAllNurses();
	int getNumOfNurses() const;

	bool setName(const char* departmentName);
	bool addDoctor(Doctor& newDoctor);
	bool addNurse(Nurse& newNurse);

	void printDepartment() const;


};


















#endif // !1
