#include <iostream>
using namespace std;



	// FUNCTIONS DECLARATIONS : 
	void menuFunc();
	void addDepartment();
	void addNurse();
	void addDoctor();
	void addVisit();
	void addResearcher();
	void addArticle();
	void printPatients();
	void printStaff();
	void printResearchers();
	void searchPatient();


void main()
{
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
		addDepartment();
		break;
	case 2: 
		addNurse();
		break;
	case 3:
		addDoctor();
		break;
	case 4: 
		addVisit();
		break;
	case 5:
		addResearcher();
		break;
	case 6:
		addArticle();
		break;
	case 7:
		printPatients();
		break;
	case 8:
		printStaff();
		break;
	case 9: 
		printResearchers();
		break;
	case 10:
		searchPatient();
		break;
	}

}

void menuFunc()
{

}
void addDepartment()
{

}
void addNurse()
{

}
void addDoctor()
{

}
void addVisit()
{

}
void addResearcher()
{

}
void addArticle()
{

}
void printPatients()
{

}
void printStaff()
{

}
void printResearchers()
{

}
void searchPatient()
{

}