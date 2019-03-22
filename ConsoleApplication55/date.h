#ifndef __DATE_H
#define __DATE_H
#include <string>
const int NAME_LENGTH = 20;

class Date
{
private:
	int day;
	int month;
	int year;

	// we should make new class of date and saving the whole date


public:
	Date(int day, int month, int year);
	Date(const Date& other);
	

	bool setDay(int tmpDay);
	bool setMonth(int tmpMonth);
	bool setYear(int tmpYear);

	int getDay() const;
	int getMonth() const;
    int getYear() const;

	void print() const;


};


#endif // !1
