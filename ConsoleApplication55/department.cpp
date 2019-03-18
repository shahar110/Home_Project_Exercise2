#include "department.h"

#include <string>
#include<iostream>
using namespace std;

const char* Department::getName() const
{
	return name;
}

Doctor** Department::getAllDoctors()
{
	return allDoctors;
}

Nurse** Department::getAllNurses()
{
	return allNurses;
}

bool Department::setName(const char* departmentName)
{
	delete[] name;
	name = new char[strlen(departmentName) + 1];
	strcpy(name, departmentName);
	return true;

}
// missing checking of max doctors and allocating new arr
bool Department::addDoctor(Doctor& newDoctor)
{
	allDoctors[numOfDoctors] = &newDoctor;
	numOfDoctors++;
	return true;
}

bool Department::addNurse(Nurse& newNurse)
{
	allNurses[numOfNurses] = &newNurse;
	numOfNurses++;
	return true;
}
// checking if there is max nurse and doc if not take care on the allocation
Department::Department(const char* departmentName) : name(nullptr)
{
	setName(departmentName);
	numOfDoctors = 0;
	numOfNurses = 0;
	allDoctors = new Doctor*[2];
	allNurses = new Nurse*[2];
}

Department::Department(const Department& other) : name(nullptr)
{
	setName(other.name);
	numOfDoctors = other.numOfDoctors;
	numOfNurses = other.numOfNurses;

	allDoctors = new Doctor*[numOfDoctors];
	for (int i = 0; i < numOfDoctors; i++)
		allDoctors[i] = new Doctor(*other.allDoctors[i]);

	allNurses = new Nurse*[numOfNurses];
	for (int i = 0; i < numOfNurses; i++)
		allNurses[i] = new Nurse(*other.allNurses[i]);
}
