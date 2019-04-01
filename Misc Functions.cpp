#include "Misc.h"

char * CopyString(char const * const str){
	char * Temp=new char[strlen(str)+1];
	strcpy(Temp,str);
	return Temp;
}

void OverWriteString(char * dest, char const * const source){
	if (dest!=nullptr) delete[] dest;
	dest=CopyString(source);
}
