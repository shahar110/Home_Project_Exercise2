#include "date.h"

Date::Date(int day, int month, int year)
{
	setDay(day);
	setMonth(month);
	setYear(year);
}

Date::Date(const Date &other)
{
	setDay(other.day);
	setMonth(other.month);
	setYear(other.year);
}

bool Date::setDay(int newDay)
{
	day = newDay;
	return true;
}

bool Date::setMonth(int newMonth)
{
	month = newMonth;
	return true;
}

bool Date::setYear(int newYear)
{
	year = newYear;
	return true;
}

void Date::printDate() const
{
	cout << day << "/" << month << "/" << year;
}

;