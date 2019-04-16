#include "article.h"

Article::Article(const char* articleName, const char* magazineName, const Date& date) : publishDate(date)
{
	setArticleName(articleName);
	setMagazineName(magazineName);
	//publishDate = date;
}

Article::~Article()
{
	delete[]articleName;
	delete[]magazineName;
}

bool Article::setArticleName(const char* tmpArtName)
{
	delete[]articleName;
	articleName = new char[strlen(tmpArtName) + 1];
	strcpy(articleName, tmpArtName);
	return true;
}

bool Article::setMagazineName(const char* tmpMagName)
{
	delete[]magazineName;
	magazineName = new char[strlen(tmpMagName) + 1];
	strcpy(magazineName, tmpMagName);
	return true;
}

bool Article::setDate(const Date& newDate)
{
	publishDate = newDate;
	return true;
}

const char* Article::getArticleName() const
{
	return articleName;
}

const char* Article::getMagazineName() const
{
	return magazineName;
}

Date Article::getDate() const
{
	return publishDate;
}

void Article::print() const
{
	cout << "Article name: " << articleName << "    , published by magazie: : " << magazineName
		<< "    , at ";
	publishDate.printDate();
}