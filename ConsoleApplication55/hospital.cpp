#include "hospital.h"

int Hospital::employeeCounter = 0;

Hospital::Hospital(const string& name) 
{
	setName(name);

	departmentArr = new Department*[physDepartmentsArr];
	doctorsArr = new Doctor*[physDoctorsArr];
	nursesArr = new Nurse*[physNursesArr];
	patientArr = new Patient*[physPatientArr];
	researchersArr = new Researcher*[physResearchersArr];
}

Hospital::~Hospital()
{
	delete[]departmentArr;
	delete[]doctorsArr;
	delete[]nursesArr;
	delete[]patientArr;
	delete[]researchersArr;
}

void Hospital::addDepartment(const string& departmentName)
{
	if (physDepartmentsArr == numOfDepartments) {
		physDepartmentsArr *= 2;

		Department** temp = new Department*[numOfDepartments];
		for (int i = 0; i < numOfDepartments; i++)
			temp[i] = departmentArr[i];

		delete[]departmentArr;

		departmentArr = new Department*[physDepartmentsArr];
		for (int i = 0; i < numOfDepartments; i++)
			departmentArr[i] = temp[i];

		delete[]temp;
	}

	//Add the new Department to the Hospital Departments array
	departmentArr[numOfDepartments] = new Department(departmentName);
	numOfDepartments++;
}

int Hospital::getNumOfDepartments() const
{
	return numOfDepartments;
}

Department** Hospital::getDeparmentsArr()
{
	return departmentArr;
}

void Hospital::addNurse(const string& nurseName, int years, int depratmentIndex)
{
	if (physNursesArr == numOfNurses) {
		physNursesArr *= 2;

		Nurse** temp = new Nurse*[numOfNurses];
		for (int i = 0; i < numOfNurses; i++)
			temp[i] = nursesArr[i];

		delete[]nursesArr;

		nursesArr = new Nurse*[physNursesArr];
		for (int i = 0; i < numOfNurses; i++)
			nursesArr[i] = temp[i];

		delete[]temp;
	}
	employeeCounter++;

	//Add the new Nurse to the Hospital Nurses array
	nursesArr[numOfNurses] = new Nurse(nurseName, years);

	//Add the pointer to the Nurse to the her department Nurses pointers arr
	//departmentArr[depratmentIndex]->addNurse(nursesArr[numOfNurses]);
	*(departmentArr[depratmentIndex]) += nursesArr[numOfNurses];
	numOfNurses++;
}

int Hospital::getNumOfNurses() const
{
	return numOfNurses;
}

Nurse** Hospital::getNursesArr()
{
	return nursesArr;
}

void Hospital::addDoctor(const string& doctorName, const string& expertise, int depratmentIndex)
{
	if (physDoctorsArr == numOfDoctors) {
		physDoctorsArr *= 2;

		Doctor** temp = new Doctor*[numOfDoctors];
		for (int i = 0; i < numOfDoctors; i++)
			temp[i] = doctorsArr[i];

		delete[]doctorsArr;

		doctorsArr = new Doctor*[physDoctorsArr];
		for (int i = 0; i < numOfDoctors; i++)
			doctorsArr[i] = temp[i];

		delete[]temp;
	}
	employeeCounter++;

	//Add the new Doctor to the Hospital Doctors array
	doctorsArr[numOfDoctors] = new Doctor(doctorName, expertise);
	//Add the pointer to the Doctor the his department Doctors pointers arr

	//departmentArr[depratmentIndex]->addDoctor(doctorsArr[numOfDoctors]);

	// Trying to change by overloading operator
	*(departmentArr[depratmentIndex]) += doctorsArr[numOfDoctors];
	numOfDoctors++;
}

void Hospital::addSurgeon(const string& doctorName, const string& expertise, int depratmentIndex, int numOfSurgeries)
{
	if (physDoctorsArr == numOfDoctors) {
		physDoctorsArr *= 2;

		Doctor** temp = new Doctor*[numOfDoctors];
		for (int i = 0; i < numOfDoctors; i++)
			temp[i] = doctorsArr[i];

		delete[]doctorsArr;

		doctorsArr = new Doctor*[physDoctorsArr];
		for (int i = 0; i < numOfDoctors; i++)
			doctorsArr[i] = temp[i];

		delete[]temp;
	}
	employeeCounter++;

	//Add the new Doctor to the Hospital Doctors array
	doctorsArr[numOfDoctors] = new SurgeonDoctor(doctorName, expertise, numOfSurgeries);

	//Add the pointer to the Doctor the his department Doctors pointers arr
	departmentArr[depratmentIndex]->addDoctor(doctorsArr[numOfDoctors]);
	numOfDoctors++;
}

int Hospital::getNumOfDoctors() const
{
	return numOfDoctors;
}

Doctor** Hospital::getDoctorsArr()
{
	return doctorsArr;
}

void Hospital::addPatient(const string& patientName, int patientId, int birthYear, eGender patientGender, int depratmentIndex)
{
	if (physPatientArr == numOfPatients) {
		physPatientArr *= 2;

		Patient** temp = new Patient*[numOfPatients];
		for (int i = 0; i < numOfPatients; i++)
			temp[i] = patientArr[i];

		delete[]patientArr;

		patientArr = new Patient*[physPatientArr];
		for (int i = 0; i < numOfPatients; i++)
			patientArr[i] = temp[i];

		delete[]temp;
	}

	//Add the new Patient to the Hospital Patients array
	patientArr[numOfPatients] = new Patient(patientName, patientId, birthYear, patientGender);

	//Add the pointer to the Patient the his department Patients pointers arr
	departmentArr[depratmentIndex]->addPatient(patientArr[numOfPatients]);
	//Save the department index for the Patient (for later use)
	patientArr[numOfPatients]->setDepartmentIndex(numOfPatients);

	numOfPatients++;
}

void Hospital::changePatientDepartment(int patientId, int newDepartmentIndex)
{
	int patientIndex, oldDepartmentIndex, oldPatientArrIndex;

	patientIndex = findPatientIndex(patientId);
	oldDepartmentIndex = patientArr[patientIndex]->getDepartmentIndex();
	oldPatientArrIndex = patientArr[patientIndex]->getDepartmentPatientArrIndex();
	departmentArr[oldDepartmentIndex]->getAllPatients()[oldPatientArrIndex] = nullptr;

	int sizeToEnd = departmentArr[oldDepartmentIndex]->getNumOfPatients();
	int i;
	for (i = oldPatientArrIndex ; i < sizeToEnd ; i++)
	{
		departmentArr[oldDepartmentIndex]->getAllPatients()[i] = departmentArr[oldDepartmentIndex]->getAllPatients()[i+1];
		int numOfPatients = departmentArr[oldDepartmentIndex]->getNumOfPatients();
		departmentArr[oldDepartmentIndex]->setNumOfPatients(numOfPatients - 1);
	}
	departmentArr[oldDepartmentIndex]->getAllPatients()[i] = nullptr;
	departmentArr[newDepartmentIndex]->addPatient(patientArr[patientIndex]);

	patientArr[patientIndex]->setDepartmentIndex(newDepartmentIndex);
}

int Hospital::getNumOfPatients() const
{
	return numOfPatients;
}

Patient** Hospital::getPatientsArr()
{
	return patientArr;
}

int Hospital::findPatientIndex(int id)
{
	for (int i = 0; i < numOfPatients; i++)
	{
		if (patientArr[i]->getId() == id)
			return i;
	}

	return -1;
}

void Hospital::addResearcher(const string& researcherName)
{
	if (physResearchersArr == numOfResearchers) {
		physResearchersArr *= 2;

		Researcher** temp = new Researcher*[numOfResearchers];
		for (int i = 0; i < numOfResearchers; i++)
			temp[i] = researchersArr[i];

		delete[]researchersArr;

		researchersArr = new Researcher*[physResearchersArr];
		for (int i = 0; i < numOfResearchers; i++)
			researchersArr[i] = temp[i];

		delete[]temp;
	}
	employeeCounter++;

	//Add the new Researcher to the Hospital Researchers array
	researchersArr[numOfResearchers] = new Researcher(researcherName);
	numOfResearchers++;
}

int Hospital::getNumOfResearchers() const
{
	return numOfResearchers;
}

Researcher** Hospital::getResearchersArr()
{
	return researchersArr;
}

void Hospital::addResearchDoctor(const string& doctorName, const string& expertise, int depratmentIndex)
{
	if (physDoctorsArr == numOfDoctors) {
		physDoctorsArr *= 2;

		Doctor** temp = new Doctor*[numOfDoctors];
		for (int i = 0; i < numOfDoctors; i++)
			temp[i] = doctorsArr[i];

		delete[]doctorsArr;

		doctorsArr = new Doctor*[physDoctorsArr];
		for (int i = 0; i < numOfDoctors; i++)
			doctorsArr[i] = temp[i];

		delete[]temp;
	}

	if (physResearchersArr == numOfResearchers) {
		physResearchersArr *= 2;

		Researcher** temp = new Researcher*[numOfResearchers];
		for (int i = 0; i < numOfResearchers; i++)
			temp[i] = researchersArr[i];

		delete[]researchersArr;

		researchersArr = new Researcher*[physResearchersArr];
		for (int i = 0; i < numOfResearchers; i++)
			researchersArr[i] = temp[i];

		delete[]temp;
	}

	employeeCounter++;

	//Add the new Doctor to the Hospital Doctors array
	doctorsArr[numOfDoctors] = new ResearchDoctor(doctorName, expertise);
	researchersArr[numOfResearchers] = (ResearchDoctor*) doctorsArr[numOfDoctors];

	//Add the pointer to the Doctor the his department Doctors pointers arr
	departmentArr[depratmentIndex]->addDoctor(doctorsArr[numOfDoctors]);
	numOfDoctors++;
	numOfResearchers++;
}

bool Hospital::setName(const string& newName)
{
	name = newName;
	return true;
}