#ifndef __DOCTOR_H
#define __DOCTOR_H

const int NAME_LENGTH = 20;

class Doctor
{
private:
	char* name;
	int employeeNum;
	char* field;


public:
	Doctor(const char* name, int employeeNum, const char* field);
	Doctor(const Doctor& other);
	~Doctor();

	bool setName(const char* name);
	bool setAge(int age);
	bool setField(const char* field);

	const char* getName() const;
	int getAge() const;
	const char* getField() const;

	void print() const;


};


















#endif // !1
