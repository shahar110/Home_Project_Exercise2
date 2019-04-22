#ifndef __DATE_H
#define __DATE_H

#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include <iostream>
#include <string>

class Date
{
private:
	int day;
	int month;
	int year;

public:
	//Date() = default;
	Date(int day, int month, int year);
	Date(const Date& other);
	
	bool setDay(int newDay);
	bool setMonth(int newMonth);
	bool setYear(int newYear);

	void printDate() const;
};

#endif // !1