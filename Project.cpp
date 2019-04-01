#include "Project.h"

Project::Project(char * name, int budget, int duration)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->budget = budget;
	this->duration = duration;
}

Project::Project(const Project & Pro)
{
	name = new char[strlen(Pro.name) + 1];
	strcpy(name, Pro.name);
	budget = Pro.budget;
	duration = Pro.duration;
}

const Project & Project::operator=(const Project & other)
{
	delete name;
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
	budget = other.budget;
	duration = other.duration;
	return *this;
}

void Project::setBudget(int n)
{
	budget = n;
}

bool Project::operator==(const Project & other)
{
	if (strcmp(name, other.name) == 0) return false;
	if (budget != other.budget) return false;
	if (duration != other.duration) return false;
	
	return true;
}

Project::~Project()
{
	delete[] name;
}

ostream & operator<<(ostream & osObject, const Project & Pro)
{
	cout << "name: " << Pro.name << endl;
	cout << "budget: " << Pro.budget;
	cout << "duration: " << Pro.duration;

	return osObject;
}

bool operator==(const Project & A, const Project & B)
{
	if (strcmp(A.name, B.name) == 0) return false;
	if (A.budget != B.budget) return false;
	if (A.duration != B.duration) return false;

	return true;
}
