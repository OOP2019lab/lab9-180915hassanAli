//Address.h
#include <iostream>



#ifndef ADDRESS_H
#define ADDRESS_H
class Address
{
	char* house_Number;
	char* street_Name ;
	char * city;
	char* county;

public:
	Address(char* house_Number, char* Street_Name, char * City,char* County);
	// an overloaded constructor
	Address(const Address&);
	//copy constructor
	friend std::ostream& operator<<(std::ostream& osObject, const Address&);
	//overloaded insertion operator
	const Address &   operator=(const Address& other);
	//overloaded assignment operator
	~Address();
};
#endif