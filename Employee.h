#include <iostream>
#include "Address.h"
#include "Project.h"

using namespace std;

#ifndef EMPLOYEE_H
#define EMPLOYEE_H
class Employee
{
	char* emp_name; 
	//Add Data Members here
	Project const **  Projects;
	int ProjectCount;
	int ProjectCap;
	Address address;
	
public:
	Employee(char* name, const Address&);
	//overloaded constructor
	Employee(const Employee&);
	//copy constructor
	friend ostream& operator<<(ostream& osObject, const Employee&);
	//overloaded insertion operator
	const Employee &   operator=(const Employee& other);
	//overloaded assignment operator

	void addProject(Project const * );
	void removeProject(Project const * ); 

	~Employee();

}; 
#endif