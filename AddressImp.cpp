#include "Address.h"
#include "Misc.h"

Address::Address(char* house_Number, char* Street_Name, char * City,char* County){
	this->house_Number=CopyString(house_Number);
	this->street_Name=CopyString(Street_Name);
	this->city=CopyString(City);
	this->county=CopyString(County);
}

Address::Address(const Address& Add){
	house_Number=CopyString(Add.house_Number);
	street_Name=CopyString(Add.street_Name);
	city=CopyString(Add.city);
	county=CopyString(Add.county);
}

std::ostream& operator<<(std::ostream& osObject, const Address& add){
	std::cout<<"House Number: "<<add.house_Number<<std::endl;
	std::cout<<"Street Name: "<<add.street_Name<<std::endl;
	std::cout<<"City: "<<add.city<<std::endl;
	std::cout<<"county: "<<add.county<<std::endl;

	return osObject;
}

const Address& Address::operator=(const Address& other){
	OverWriteString(house_Number,other.house_Number);
	OverWriteString(street_Name,other.street_Name);
	OverWriteString(city,other.city);
	OverWriteString(county,other.county);

	return *this;
}

Address::~Address(){
	delete [] house_Number;
	delete[] street_Name;
	delete [] city;
	delete[] county;
}