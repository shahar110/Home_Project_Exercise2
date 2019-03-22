#ifndef __ARTICLE_H
#define __ARTICLE_H
#include <string>
const int NAME_LENGTH = 20;

class Article
{
private:
	char* articleName;
	char* magazineName;
	int date;

	// we should make new class of date and saving the whole date


public:
	Article(const char* articleName, const char* magazineName, int date);
	Article(const Article& other);
	~Article();

	bool setArticleName(const char* articleName);
	bool setMagazineName(const char* magazineName);
	bool setdate(int date);

	const char* getArticleName() const;
	const char* getMagazineName() const;
	const int getDate() const;

	void print() const;


};


#endif // !1
