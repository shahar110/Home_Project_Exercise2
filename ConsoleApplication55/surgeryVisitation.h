#pragma once
#include "VisitationForm.h"
#include "date.h"
class surgeryVisitation : public VisitForm
{
	int roomNum;
	bool isFasting;
public:
	surgeryVisitation();
	surgeryVisitation(const Date& date, int purpose, int therapistNum, const char* therapistName, const char* departmentName);
	~surgeryVisitation();
	bool setRoomNum(int roomNum);
	bool setIsFasting(int answer);

	int getRoomNum();
	bool getIsFasting();
	void printSurgery();
};

