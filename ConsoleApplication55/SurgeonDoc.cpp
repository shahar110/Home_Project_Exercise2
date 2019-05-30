#include "SurgeonDoc.h"

SurgeonDoctor::SurgeonDoctor(const string& name, const string& expetise, int numOfSurgeries) : Doctor(name, expetise), StaffMember(name)
{
	setNumOfSurgeries(numOfSurgeries);
}

bool SurgeonDoctor::setNumOfSurgeries(int numOfSurgeries)
{
	this->numOfSurgeries = numOfSurgeries;
	return true;
}

int SurgeonDoctor::getNumOfSurgeries() const
{
	return numOfSurgeries;
}

void SurgeonDoctor::print() const
{
	Doctor::print();
	cout << "     , number of performed surgeries: " << numOfSurgeries;
}
