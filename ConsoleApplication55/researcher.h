
#include "article.h"
#ifndef __RESEARCHER_H
#define __RESEARCHER_H

const int NAME_LENGTH = 20;

class Researcher
{
private:
	char *name;
	int id;
	int articleCnt;
	Article **allArticles;


public:
	Researcher(const char* name, int id);
	Researcher(const Researcher& other);
	~Researcher();

	bool setName(const char* name);
	bool setId(int age);
	bool addArticle();
	const char* getName() const;
	int getId() const;

	void print() const;


};



#endif // !1
