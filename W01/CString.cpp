// Name: Aria Avazkhani
// Seneca Student ID: 134465160
// Seneca email: aavazkhani@myseneca.ca
// Date of completion: 2018=09-13
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.


#include <cstring>
#include <iostream>
#include "CString.h"


int STORED = 3;

namespace w1{


	CString::CString(const char* p_str) : MAX{ STORED } {
		if (p_str == nullptr)
			str[0] = '\0';
		else{
			strncpy(str, p_str, MAX);
			str[MAX + 1] = '\0';
			
		}
	}
	void CString::display(ostream & os) const{
		os << str;
	}

	ostream& operator<<(ostream& os, CString& p_str){
		p_str.display(os);
		return os;
	}
}
