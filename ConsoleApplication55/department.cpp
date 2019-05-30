#include "department.h"

using namespace std;

// checking if there is max nurse and doc if not take care on the allocation
Department::Department(const string& departmentName)
{
	setName(departmentName);
	allDoctors = new Doctor*[physDoctorArr];
	allNurses = new Nurse*[physNursesArr];
	allPatients = new Patient*[physPatientsArr];
}
//////     Don't forget to remove
Department::~Department()
{
	delete[]allDoctors;
	delete[]allNurses;
	delete[]allPatients;
}

bool Department::setName(const string& departmentName)
{
	name = departmentName;
}

bool Department::addNurse(Nurse* newNurse)
{
	if (physNursesArr == numOfNurses) {
		physNursesArr *= 2;

		Nurse** temp = new Nurse*[numOfNurses];
		for (int i = 0; i < numOfNurses; i++)
			temp[i] = allNurses[i];

		delete[]allNurses;

		allNurses = new Nurse*[physNursesArr];
		for (int i = 0; i < numOfNurses; i++)
			allNurses[i] = temp[i];

		delete[]temp;
	}
	allNurses[numOfNurses] = newNurse;
	numOfNurses++;
	return true;
}

bool Department::addDoctor(Doctor* newDoctor)
{
	if (physDoctorArr == numOfDoctors) {
		physDoctorArr *= 2;

		Doctor** temp = new Doctor*[numOfDoctors];
		for (int i = 0; i < numOfDoctors; i++)
			temp[i] = allDoctors[i];

		delete[]allDoctors;

		allDoctors = new Doctor*[physDoctorArr];
		for (int i = 0; i < numOfDoctors; i++)
			allDoctors[i] = temp[i];

		delete[]temp;
	}
	allDoctors[numOfDoctors] = newDoctor;
	numOfDoctors++;
	return true;
}

bool Department::addPatient(Patient* newPatient)
{
	if (physPatientsArr == numOfPatients) {
		physPatientsArr *= 2;

		Patient** temp = new Patient*[numOfPatients];
		for (int i = 0; i < numOfPatients; i++)
			temp[i] = allPatients[i];

		delete[]allPatients;

		allPatients = new Patient*[physPatientsArr];
		for (int i = 0; i < numOfPatients; i++)
			allPatients[i] = temp[i];

		delete[]temp;
	}
	//Add the patient to the department patients array
	allPatients[numOfPatients] = newPatient;
	//Save the array index for the patient (for later use)
	allPatients[numOfPatients]->setDepartmentPatientArrIndex(numOfPatients);

	numOfPatients++;
	return true;
}

char* Department::selectStaffMember(int* staffMemberNum)
{
	int i,  selectionIndex = 0, selection;
	char *staffMemberName = nullptr;

	cout << "1: Doctors list" << endl;
	cout << "2: Nurses list" << endl;
	cin >> selection;

	switch (selection)
	{
	case 1:
		for (i = 0; i < numOfDoctors; i++)
			cout << i << ":  Doctor " << allDoctors[i]->getName() << endl;

		cin >> selectionIndex;

		if (selectionIndex < 0 || selectionIndex > i - 1)
		{
			cout << "Ileggal selection entered!\nExiting...\n";
			return nullptr;
		}

		*staffMemberNum = allDoctors[selectionIndex]->getEmployeeNum();

		staffMemberName = new char(strlen(allDoctors[selectionIndex]->getName()) + 1);
		strcpy(staffMemberName, allDoctors[selectionIndex]->getName());

		return staffMemberName;
	break;

	case 2:
		for (i = 0; i < numOfNurses; i++)
			cout << i << ":  Nurse " << allNurses[i]->getName() << endl;

		cin >> selectionIndex;

		if (selectionIndex < 0 || selectionIndex > i - 1)
		{
			cout << "Ileggal selection entered!\nExiting...\n";
			return nullptr;
		}

		*staffMemberNum = allNurses[selectionIndex]->getEmployeeNum();

		staffMemberName = new char(strlen(allNurses[selectionIndex]->getName()) + 1);
		strcpy(staffMemberName, allNurses[selectionIndex]->getName());

		return staffMemberName;
	break;
	default:
		cout << "Illegal sellection entered!\nExisiting...\n";
		*staffMemberNum = -1;
		return nullptr;
	}
}

bool Department::setNumOfPatients(int num)
{
	numOfPatients = num;
	return true;
}



Doctor** Department::getAllDoctors()
{
	return allDoctors;
}

Nurse** Department::getAllNurses()
{
	return allNurses;
}

Patient** Department::getAllPatients()
{
	return allPatients;
}

int Department::getNumOfDoctors() const
{
	return numOfDoctors;
}

int Department::getNumOfNurses() const
{
	return numOfDoctors;
}

int Department::getNumOfPatients() const
{
	return numOfPatients;
}

void Department::printDepartment() const
{
	cout << "Department name: " << name << endl;
	cout << "--------------------------------------------------------" << endl;
	int i = 0;

	cout << "List of Doctors in the department (" << numOfDoctors << "): " << endl;
	for (i = 0; i < numOfDoctors; i++) {
		allDoctors[i]->print();
		cout << endl;
	}

	cout << "List of Nurses in the department (" << numOfNurses << "): " << endl;
	for (i = 0; i < numOfNurses; i++) {
		// change to ostream ----- allNurses[i]->print();
		cout << allNurses[i];
		cout << endl;
	}

	cout << "List of Patients in the department (" << numOfPatients << "): " << endl;
	for (i = 0; i < numOfPatients; i++) {
		allPatients[i]->printPatient();
		cout << endl;
	}

	cout << "--------------------------------------------------------" << endl;
}

void Department::printPatientsList() const
{
	cout << "Printing Patients list for department " << name << ":" << endl;

	for (int i = 0; i < numOfPatients; i++)
	{
		if (allPatients[i]!=nullptr)
		{
			allPatients[i]->printPatient();
			cout << endl;
			allPatients[i]->printCurrentVisit();
			cout << "\n\n";
		}

	}
	cout << "--------------------------------------------------------" << endl;
}

void Department::printDepartmentStaff() const
{
	cout << "Staff members of Department " << name << ":" << endl;
	cout << "-----------------------------------------------------------" << endl;
	int i = 0;

	cout << "List of Doctors (" << numOfDoctors << "): " << endl;
	//cout << "------------------------------------------" << endl;
	for (i = 0; i < numOfDoctors; i++) {
		allDoctors[i]->print();
		cout << endl;
	}

	cout << endl;

	cout << "List of Nurses (" << numOfNurses << "): " << endl;
	//cout << "------------------------------------------" << endl;
	for (i = 0; i < numOfNurses; i++) {
		allNurses[i]->print();
		cout << endl;
	}

	cout << endl;
	cout << "-----------------------------------------------------------" << endl;
}


bool Department::operator+=(Doctor* newDoctor)  
{
	addDoctor(newDoctor);
	return true;
	
}



bool Department::operator+=(Nurse* newNurse)  
{
	addNurse(newNurse);
	return true;
}
