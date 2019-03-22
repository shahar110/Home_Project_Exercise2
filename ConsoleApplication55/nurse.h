#ifndef __NURSE_H
#define __NURSE_H



class Nurse
{
private:
	char* name;
	int employeeNum;
	int experience;


public:
	Nurse(const char* name, int employeeNum, int experience);
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
