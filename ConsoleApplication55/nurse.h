#ifndef __NURSE_H
#define __NURSE_H

const int NAME_LENGTH = 20;

class Nurse
{
private:
	char* name;
	int employeeNum;
	char* experience;


public:
	Nurse(const char* name, int employeeNum, const char* field);
	Nurse(const Nurse& other);
	~Nurse();

	bool setName(const char* name);
	bool setemployeeNum(int age);
	bool setexperience(int experience);

	const char* getName() const;
	int getemployeeNum() const;
	int getexperience() const;

	void print() const;


};


















#endif // !1
