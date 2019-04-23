#ifndef __NURSE_H
#define __NURSE_H
#include "StaffMember.h"

using namespace std;

class Nurse : public StaffMember
{
private:
	int experience;

public:
	Nurse(const char * name, int experience);
	~Nurse();

	bool setExperience(int experience);

	int getExperience() const;

	void print() const;
	friend ostream& operator<<(ostream& os, const Nurse &nurse)
	{
		os << "Nurse name: " << nurse.name << "   , years of experience: " << nurse.experience
			<< "   , ID: " << nurse.employeeNum;
		return os;
	}
};

#endif // !1