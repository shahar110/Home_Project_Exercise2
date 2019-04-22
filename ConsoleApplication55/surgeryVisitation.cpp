#include "surgeryVisitation.h"


surgeryVisitation::surgeryVisitation(const Date& date, int purpose, int therapistNum, const char* therapistName
	, const char* departmentName) : VisitForm::VisitForm(date, purpose, therapistNum, therapistName, departmentName)
{
	int option,romNum;
	cout << "If the patient fast press 1 if not 0: "<<endl;
	cin >> option;
	setIsFasting(option);
	cout << "Enter room number : " << endl;
	cin >> romNum;
	setRoomNum(romNum);
}

bool surgeryVisitation::setIsFasting(int option)
{
	isFasting = (bool)option;
	return true;
}
bool surgeryVisitation::setRoomNum(int room)
{
	roomNum = room;
	return true;
}

bool surgeryVisitation::getIsFasting()
{
	return isFasting;
}

int surgeryVisitation::getRoomNum()
{
	return roomNum;
}

void surgeryVisitation::printSurgery()
{
	this->printVisitForm();
	cout << " And the room number is: " << roomNum;
	if (isFasting)
		cout << " The patient didn't fast before sergery";
	else
		cout << "THe patient fast before sergery";
}
