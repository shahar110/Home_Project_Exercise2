#ifndef __RESEARCHER_H
#define __RESEARCHER_H

#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include <iostream>
#include "string.h"
#include "article.h"
#include "StaffMember.h"
#include "Array.h"
class Researcher : virtual public StaffMember
{
protected:
	Array<Article> articleArr;
	
public:
	Researcher(const string& name);
	~Researcher();

	bool operator<(const Researcher& r) const;
	bool operator>(const Researcher& r) const;
	bool operator==(const Researcher& r) const;
	bool operator!=(const Researcher& r) const;
	bool operator<=(const Researcher& r) const;
	bool operator>=(const Researcher& r) const;

	bool addArticle(const string& articleName, const string& magazineName, const Date& date);

	int getNumOfArticles() const;

	void printDetails() const;
	void printArticleList() const;
	friend ostream& operator<<(ostream& os, const Researcher &researcher)
	{
		os << "Researcher Name: " << researcher.name<< "    , ID: " << researcher.employeeNum;
		return os;
	}
	
};
#endif