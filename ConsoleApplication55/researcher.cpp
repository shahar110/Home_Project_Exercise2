#include "researcher.h"

Researcher::Researcher(const char* name) : StaffMember(name)
{
	articleArr = new Article*[physArticleArr];
}

Researcher::~Researcher()
{
	for (int i = 0; i < numOfArticles; i++)
	{
		delete[]articleArr[i];
	}
	delete[]articleArr;
}

bool Researcher::operator<(const Researcher & r) const
{
	if (this->numOfArticles < r.numOfArticles)
		return true;
	else
		return false;
}

bool Researcher::operator>(const Researcher & r) const
{
	if (this->numOfArticles > r.numOfArticles)
		return true;
	else
		return false;
}

bool Researcher::operator==(const Researcher & r) const
{
	if (this->numOfArticles == r.numOfArticles)
		return true;
	else
		return false;
}

bool Researcher::operator!=(const Researcher & r) const
{
	if (this->numOfArticles != r.numOfArticles)
		return true;
	else
		return false;
}

bool Researcher::operator>=(const Researcher & r) const
{
	if (this->numOfArticles > r.numOfArticles || this->numOfArticles == r.numOfArticles)
		return true;
	else
		return false;
}

bool Researcher::operator<=(const Researcher & r) const
{
	if (this->numOfArticles < r.numOfArticles || this->numOfArticles == r.numOfArticles)
		return true;
	else
		return false;
}
//checkKK
bool Researcher::addArticle(const char* articleName, const char* magazineName, const Date& date)
{
	if (physArticleArr == numOfArticles) 
	{
		physArticleArr *= 2;

		Article** temp = new Article*[numOfArticles];
		for (int i = 0; i < numOfArticles; i++)
			temp[i] = articleArr[i];

		delete[]articleArr;

		articleArr = new Article*[physArticleArr];
		for (int i = 0; i < numOfArticles; i++)
			articleArr[i] = temp[i];

		delete[]temp;
	}
	articleArr[numOfArticles] = new Article(articleName, magazineName, date);
	numOfArticles++;
	return true;
}

int Researcher::getNumOfArticles() const
{
	return numOfArticles;
}

void Researcher::printDetails() const
{
	cout << "Researcher Name: " << name << "    , ID: " << employeeNum;
}

void Researcher::printArticleList() const
{
	cout << name << " - Displaying list of articles(" << numOfArticles << "):" << endl;
	for (int i = 0; i < numOfArticles; i++)
	{
		articleArr[i]->print();
		cout << endl;
	}
}