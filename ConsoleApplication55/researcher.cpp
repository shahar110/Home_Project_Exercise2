#include "researcher.h"

Researcher::Researcher(const string& name) : StaffMember(name) {}

Researcher::~Researcher()	{}

bool Researcher::operator<(const Researcher & r) const
{
	if (this->articleArr.getSize() < r.articleArr.getSize())
		return true;
	else
		return false;
}

bool Researcher::operator>(const Researcher & r) const
{
	if (this->articleArr.getSize())
		return true;
	else
		return false;
}

bool Researcher::operator==(const Researcher & r) const
{
	if (this->articleArr.getSize() == r.articleArr.getSize())
		return true;
	else
		return false;
}

bool Researcher::operator!=(const Researcher & r) const
{
	if (this->articleArr.getSize() != r.articleArr.getSize())
		return true;
	else
		return false;
}

bool Researcher::operator>=(const Researcher & r) const
{
	if (this->articleArr.getSize() == r.articleArr.getSize() || this->articleArr.getSize() > r.articleArr.getSize())
		return true;
	else
		return false;
}

bool Researcher::operator<=(const Researcher & r) const
{
	if (this->articleArr.getSize() == r.articleArr.getSize() || this->articleArr.getSize() < r.articleArr.getSize())
		return true;
	else
		return false;
}

bool Researcher::addArticle(const string& articleName, const string& magazineName, const Date& date)
{
	articleArr += Article(articleName, magazineName, date);
	return true;
}

int Researcher::getNumOfArticles() const
{
	return this->articleArr.getSize();
}

void Researcher::printDetails() const
{
	cout << "Researcher Name: " << name << "    , ID: " << employeeNum;
}

void Researcher::printArticleList() const
{
	cout << name << " - Displaying list of articles(" << this->articleArr.getSize() << "):" << endl;
	cout << articleArr;
	//for (int i = 0; i < this->articleArr.getSize(); i++)
	//{
	//	articleArr[i]->print();
	//	cout << endl;
	//}
}