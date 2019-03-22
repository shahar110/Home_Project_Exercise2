#include <iostream>
#include <string>
using namespace std;
const int NAME_LENGTH = 20;
#include "nurse.h"
#include "department.h"
#include "doctor.h"
#include "researcher.h"
#include "article.h"


	// FUNCTIONS DECLARATIONS : 
	void menuFunc();
	void addNurse(int logicalDepartmentSize, Department** department);
	void addDoctor(int logicalDepartmentSize, Department** department);
	void addVisit(int logicalDepartmentSize, Department** department);
	void addDepartment(Department **department, int &physicalDepartmentSize, int &logicalDepartmentSize);
	void addArticle(Researcher **institution, int logicalSize);
	void printPatients();
	void printStaff(int logicalDepartmentSize, Department** department);
	void printResearchers(Researcher **institution, int logicalResearchIns);
	void searchPatient();
	int departmentSelect(int logicalDepartmentSize, Department** department);
	Department **duplicateDepartment(Department **deparment, int physicalDepartmentSize, int logicalDepartmentSize);

void main()
{
	int physicalDepartmentSize=2, logicalDepartmentSize=0;
	Department** deparment = new Department*[physicalDepartmentSize];
	int physicalResearchIns = 2, logicalResearchIns = 0;
	Researcher** institution = new Researcher*[physicalResearchIns];
	int option = 0;
	cout << "Hi and welcome to Academic Hospital " << endl;
	cout << "For menu press 0 for other actions write the function you would like to do" << endl;
	cin >> option;

	switch (option)
	{
	case 0 : 
			menuFunc();
			break;
	case 1: 
		addDepartment(deparment, physicalDepartmentSize, logicalDepartmentSize);
		break;
	case 2: 
		addNurse(logicalDepartmentSize, deparment);
		break;
	case 3:
		addDoctor(logicalDepartmentSize, deparment);
		break;
	case 4: 
		addVisit();
		break;
	case 5:
		addResearcher(institution, logicalResearchIns);
		break;
	case 6:
		addArticle(institution, logicalResearchIns);
		break;
	case 7:
		printPatients();
		break;
	case 8:
		printStaff(logicalDepartmentSize, deparment);
		break;
	case 9: 
		printResearchers(institution, logicalResearchIns);
		break;
	case 10:
		searchPatient();
		break;
	}

}

void menuFunc()
{

}
void addDepartment(Department **deparment, int &physicalDepartmentSize, int &logicalDepartmentSize)
{
	if (physicalDepartmentSize == logicalDepartmentSize)
	{
		physicalDepartmentSize *= 2;
		deparment = duplicateDepartment(deparment, physicalDepartmentSize, logicalDepartmentSize);
	}
		char depName[NAME_LENGTH];
		cout << "What's department's name";
		cin.getline(depName, NAME_LENGTH);
		cin.getline(depName, NAME_LENGTH);
		deparment[logicalDepartmentSize]->setName(depName);
		logicalDepartmentSize++;
}


void addNurse(int logicalDepartmentSize, Department** department)
{
	char name[NAME_LENGTH];
	int employeeNum;
	int experience;
	int selectDepartment;
	cout << "Please insert nurse name: " << endl;
	cin.getline(name, NAME_LENGTH);
	cin.getline(name, NAME_LENGTH);
	cout << "Please insert nurse number: " << endl;
	cin >> employeeNum;
	cout << "Please insert nurse experience: " << endl;
	cin >> experience;
	selectDepartment = departmentSelect(logicalDepartmentSize, department);
	Nurse *tmp = new Nurse(name, employeeNum, experience);
	department[selectDepartment]->addNurse(*tmp);

}
void addDoctor(int logicalDepartmentSize,Department **department)
{
	char name[NAME_LENGTH];
	int employeeNum;
	char field[NAME_LENGTH];
	int selectDepartment;
	cout << "Please insert doctor name: " << endl;
	cin.getline(name, NAME_LENGTH);
	cin.getline(name, NAME_LENGTH);
	cout << "Please insert doctor number: " << endl;
	cin >> employeeNum;
	selectDepartment = departmentSelect(logicalDepartmentSize, department);
	Doctor *tmp = new Doctor(name, employeeNum,department[selectDepartment]->getName());
	department[selectDepartment]->addDoctor(*tmp);

	
}
void addVisit(int logicalDepartmentSize, Department** department)
{
	int isVisited, id, birthYear, gender, selcet;
	char *name = new char[NAME_LENGTH];
	cout << "Press 0 if patient visited or 1 for first visit";
	cin >> isVisited;
	if (isVisited == 0)
	{

	}
	else
	{
		cout << "Please insert patient name: ";
		cin.getline(name, NAME_LENGTH);
		cin.getline(name, NAME_LENGTH);
		cout << "Please insert id";
		cin >> id;
		cout << "Please insert year of birth";
		cin >> birthYear;
		cout << "0 if patient male 1 if female";
		cin >> gender;
		cout << "Please selece which department you would like to be cured";
		selcet = departmentSelect(logicalDepartmentSize, department);
		cout << "Please which doctor you would like to: ";
		//department[selcet]->getAllDoctors[i]
	}
}
void addResearcher(Researcher **institution, int logicalResearchIns)
{
	char name[NAME_LENGTH];
	int employeeId;
	cout << "Please insert researcher name: " << endl;
	cin.getline(name, NAME_LENGTH);
	cin.getline(name, NAME_LENGTH);
	cout << "Please insert researcher id: " << endl;
	cin >> employeeId;
	Researcher *tmp = new Researcher(name, employeeId);
	institution[logicalResearchIns] = tmp;


}
void addArticle(Researcher **institution, int logicalSize)
{
	int select;
	cout << "Which one you would like to add article from the list write the number";
	printResearchers(institution,logicalSize);
	cin >> select;
	institution[select]->addArticle();
	
}
void printPatients()
{

}
void printStaff(int logicalDepartmentSize, Department** department)
{
	int select = 0;
	cout << "Selece a department you would like to show staff";
	select = departmentSelect(logicalDepartmentSize, department);
	department[select]->printDepartment();


}
void printResearchers(Researcher **institution, int logicalSize)
{
	for (int i = 0; i < logicalSize; i++)
	{
		cout << "The " << i << "researcher is :";
		institution[i]->print();
	}
}
void searchPatient()
{

}
int departmentSelect(int logicalDepartmentSize, Department** department)
{
	int select = 0;
	cout << "What department you would like to add";
	for (int i = 0; i < logicalDepartmentSize; i++)
	{
		cout << "The " << i << "is" << department[i]->getName << endl;
	}
	cout << endl;
	cout << "Which one you would like to choose";
		cin >> select;
	return select;
}

Department **duplicateDepartment(Department **deparment, int physicalDepartmentSize, int logicalDepartmentSize)
{
	Department** newDepartment = new Department*[physicalDepartmentSize];
	for (int i = 0; i < logicalDepartmentSize; i++)
	{
		newDepartment[i] = deparment[i];
	}
	return newDepartment;
}