#include "Employee.h"
#include "Misc.h"

Employee::Employee(char* name, const Address& add):address(add){
	emp_name=CopyString(name);
	ProjectCount=0;
	Projects=nullptr;
	ProjectCap = 0;
}

Employee::Employee(const Employee& source):address(source.address){
	emp_name = new char[strlen(source.emp_name)+1];
	strcpy(emp_name, source.emp_name);

	ProjectCount = source.ProjectCount;
	ProjectCap = source.ProjectCap;
	Project const ** Temp = new Project*[source.ProjectCount];
	Projects = Temp;
	for (int c = 0; c < ProjectCount; ++c) {
		Projects[c] = source.Projects[c];
	}
}

ostream& operator<<(ostream& osObject, const Employee& emp){
	cout << "Employee name: " << emp.emp_name << endl;
	cout << "Addresses: " << emp.address << endl;
	cout<<"Projects: ";
	if (emp.Projects!=nullptr){
		for (int c=0;c<emp.ProjectCount;++c){
			cout<<*emp.Projects[c];
		}
	}

	return osObject;
}

const Employee & Employee::operator=(const Employee& other) {
	delete[] emp_name;
	emp_name = new char[strlen(other.emp_name) + 1];
	strcpy(emp_name, other.emp_name);

	for (int c = 0; c < ProjectCount; ++c) {
		delete Projects[c];
	}
	ProjectCount = other.ProjectCount;
	Projects = new Project*[ProjectCount];
	for (int c = 0; c < ProjectCount; ++c) {
		Projects[c] = other.Projects[c];
	}

	address = other.address;

	return *this;
}

void Employee::addProject(Project const * Pro) {
	if (ProjectCap == 0) {
		Projects = new Project*[1];
		ProjectCap = 1;
		ProjectCount = 1;

		Projects[0] = Pro;
		return;
	}

	if (ProjectCap > ProjectCount) {
		Projects[ProjectCount] = Pro;
		++ProjectCount;
		return;
	}
	else {
		Project ** Temp = new Project*[2 * ProjectCap];
		for (int c = 0; c < ProjectCount; ++c) {
			Temp[c] = Projects[c];
		}

		delete[] Projects;
		Projects = Temp;
		ProjectCap = ProjectCap * 2;

		Projects[ProjectCount] = Pro;
		++ProjectCount;
		return;
	}

}

void Employee::removeProject(Project const * Pro) {

	for (int c=0; c < ProjectCount; ++c) {
		if (*Pro == *Projects[c]) {

			for (int x = c; x < ProjectCount-1; ++x) {
				Projects[x] = Projects[x + 1];
			}
		}
	}

	--ProjectCount;
}

Employee::~Employee() {
	delete[] emp_name;
	delete[] Projects;
}