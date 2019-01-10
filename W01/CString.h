// Name: Aria Avazkhani
// Seneca Student ID: 134465160
// Seneca email: aavazkhani@myseneca.ca
// Date of completion: 2018-09-13
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef W1_CSTRING_H
#define W1_CSTRING_H

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

namespace w1 {

	class CString {

		const int MAX;
		char str[5];

	public:
		CString(const char*);
		void display(ostream&) const;
	};

	ostream& operator<<(ostream&, CString&);
}

#endif



