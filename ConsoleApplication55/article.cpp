#include "article.h"


Article::Article(string articleName, string magazineName, const Date& date) : publishDate(date)
{
	setArticleName(articleName);
	setMagazineName(magazineName);
	//publishDate = date;
}


bool Article::setArticleName(string tmpArtName)
{
	this->articleName = tmpArtName;
	return true;
}

bool Article::setMagazineName(string tmpMagName)
{
	magazineName = tmpMagName;
	return true;
}

bool Article::setDate(const Date& newDate)
{
	publishDate = newDate;
	return true;
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