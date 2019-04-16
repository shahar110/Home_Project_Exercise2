#ifndef __DOCTOR_H
#define __DOCTOR_H
#include "StaffMember.h"

class Doctor : virtual public StaffMember
{
protected:
	char* expertise;

public:
	Doctor(const char* name, const char* expertise);
	~Doctor();

	bool setExpertise(const char* expertise);

	const char* getExpertise() const;

	virtual void print() const;
};

#endif