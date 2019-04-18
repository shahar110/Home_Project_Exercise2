#ifndef __RESEARCHER_H
#define __RESEARCHER_H

#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include <iostream>
#include "string.h"
#include "article.h"
#include "StaffMember.h"

class Researcher : virtual public StaffMember
{
protected:
	Article** articleArr;

	int physArticleArr = 2;
	int numOfArticles = 0;

public:
	Researcher(const char* name);
	~Researcher();

	bool operator<(const Researcher& r) const;
	bool operator>(const Researcher& r) const;
	bool operator==(const Researcher& r) const;
	bool operator!=(const Researcher& r) const;
	bool operator<=(const Researcher& r) const;
	bool operator>=(const Researcher& r) const;

	bool addArticle(const char* articleName, const char* magazineName, const Date& date);

	int getNumOfArticles() const;

	void printDetails() const;
	void printArticleList() const;
};
#endif