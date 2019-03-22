
#include <iostream>
#include "date.h"

using namespace std;

Date::Date(int tmpDay, int tmpMonth, int tmpYear)
{
	setDay(tmpDay);
	setMonth(tmpMonth);
	setYear(tmpYear);

}

Date::Date(const Date &other)
{
	setDay(other.day);
	setMonth(other.month);
	setYear(other.year);
}



bool Date::setDay(int tmpDay)
{
	day = tmpDay;
	return true;
}
bool Date::setMonth(int tmpMonth)
{
	month = tmpMonth;
	return true;
}
bool Date::setYear(int tmpYear)
{
	year = tmpYear;
	return true;
}

int Date::getDay() const
{
	return day;
}

int Date::getMonth() const
{
	return month;
}

int Date::getYear() const
{
	return year;
}

void Date::print() const
{
	cout << day << " " << month
		<< " " << year;
}