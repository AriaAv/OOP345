// Name: Aria Avazkhani
// Seneca Student ID: 134465160
// Seneca email: aavazkhani@myseneca.ca
// Date of completion: 2018-09-13
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include <iostream>
#include "CString.h"
#include "process.h"

namespace w1 {

	void process(const char* p_str, ostream& os){
		static int cnt = 0;
		CString str(p_str);
		os << cnt++ << ": " << str << endl;
	}
}

