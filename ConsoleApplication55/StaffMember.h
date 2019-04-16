#ifndef __STAFF_MEMBER_H
#define __STAFF_MEMBER_H

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "string.h"



class StaffMember
{
protected:
	char* name;
	static int employeeNumCounter;
	int employeeNum;
public:
	StaffMember(const char* name);
	~StaffMember();

	bool setName(const char* name);
	const char* getName() const;

	int getEmployeeNum() const;
};

#endif;

