#ifndef __SURGEON_DOC_H
#define __SURGEON_DOC_H

#include "doctor.h"

class SurgeonDoctor : public Doctor
{
protected:
	int numOfSurgeries;
public:
	SurgeonDoctor(const char* name, const char* expetise, int numOfSurgeries);

	bool setNumOfSurgeries(int numOfSurgeries);

	int getNumOfSurgeries() const;

	void print() const;
};

#endif;