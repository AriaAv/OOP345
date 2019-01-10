// Name: Aria Avazkhani
// Seneca Student ID: 134465160
// Seneca email: aavazkhani@myseneca.ca
// Date of completion: 2018-10-04
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.


#ifndef W4_MESSAGE_H
#define W4_MESSAGE_H

#include <fstream>
#include <string>
#include <iostream>

using String = std::string;

namespace w4 {
	class Message {
		String us, tw, rp;
	public:
		Message();
		Message(String, String, String);
		Message(std::ifstream& in, char c);
		bool empty() const;
		void display(std::ostream& os) const;
	};
}
#endif



