// Name: Aria Avazkhani
// Seneca Student ID: 134465160
// Seneca email: aavazkhani@myseneca.ca
// Date of completion: 2018-09-21
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.


#ifndef W2_TEXT_H
#define W2_TEXT_H

#include <iostream>
#include <fstream>
#include <string>

namespace w2 {
	class Text {
		std::string* ref;
		std::string name;
		size_t cnt;
	public:
		Text();
		Text(const std::string);
		Text(const Text&);
		Text& operator=(const Text&);
		Text(Text&&);
		Text& operator=(Text&&);
		~Text();
		size_t size() const;
	};
}
#endif


