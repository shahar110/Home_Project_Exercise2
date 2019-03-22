#include "article.h"
#include <iostream>


using namespace std;

Article::Article(const char* articleName, const char* magazineName, int date) : articleName(nullptr), magazineName(nullptr)
{
	setArticleName(articleName);
	setMagazineName(magazineName);
	//setDate(date);
}

Article::Article(const Article &other) : articleName(nullptr), magazineName(nullptr)
{
	setArticleName(other.articleName);
	setMagazineName(other.magazineName);
	//setDate(other.date);
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
bool Article::setdate(int tmpDate)
{
	date = tmpDate;
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

const int Article::getDate() const
{
	return date;
}

void Article::print() const
{
	cout << "The name of the article is : " << articleName << " and published in : " << magazineName
		<< " at " << date;
}