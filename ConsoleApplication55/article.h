#ifndef __ARTICLE_H
#define __ARTICLE_H

#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include <iostream>
#include <string>
#include "date.h"

const int NAME_LENGTH = 20;
class Article
{
private:
	char* articleName;
	char* magazineName;
	Date publishDate;

public:
	Article(const char* articleName, const char* magazineName, const Date& date);
	~Article();

	bool setArticleName(const char* articleName);
	bool setMagazineName(const char* magazineName);
	bool setDate(const Date& newDate);

	const char* getArticleName() const;
	const char* getMagazineName() const;
	Date getDate() const;

	void print() const;
};

#endif // !1