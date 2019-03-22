#include "researcher.h"
using namespace std;
#include <iostream>
#include <string>


Researcher::Researcher(const char* tmpName, int tmpId)
{
	setName(tmpName);
	setId(tmpId);
}

Researcher::Researcher(const Researcher &other) : name(nullptr)
{
	setName(other.name);
	setId(other.id);
}

Researcher::~Researcher()
{
	delete[]name;
}

bool Researcher::setName(const char* tmpName)
{
	delete[]name;
	name = new char[strlen(tmpName) + 1];
	strcpy(name, tmpName);
	return true;
}
bool Researcher::setId(int tmpId)
{
	id = tmpId;
	return true;
}

bool Researcher::addArticle()
{
	char articleName[NAME_LENGTH];
	char magazineName[NAME_LENGTH];
	int date;
	cout << "Insert Name Of Article : ";
	cin.getline(articleName, NAME_LENGTH);
	cin.getline(articleName, NAME_LENGTH);
	cout << "Where it's published?  : ";
	cin.getline(magazineName, NAME_LENGTH);
	cin.getline(magazineName, NAME_LENGTH);
	cout << "What's the date? ";
	cin >> date;
	Article *tmp = new Article(articleName, magazineName, date);
	allArticles[articleCnt] = tmp;
	articleCnt++;
}
const char* Researcher::getName() const
{
	return name;
}

int Researcher::getId() const
{
	return id;
}



void Researcher::print() const
{
	cout << "The name of the researcher is: " << name << "and his id is: " << id;
}