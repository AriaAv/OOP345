// Name: Aria Avazkhani
// Seneca Student ID: 134465160
// Seneca email: aavazkhani@myseneca.ca
// Date of completion: 2018-10-11
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

// Manages access to a set of up to 10 instances of the Message type

#ifndef W5_LETTER_H
#define W5_LETTER_H

#include <string>

namespace sict {
	
	enum class Letter { Ap, A, Bp, B, Cp, C, Dp, D, F };

	std::string let(const Letter l) {
		switch (l) {
		case Letter::Ap:
			return "A+";
			break;
		case Letter::A:
			return "A";
			break;
		case Letter::Bp:
			return "B+";
			break;
		case Letter::B:
			return "B";
			break;
		case Letter::Cp:
			return "C+";
			break;
		case Letter::C:
			return "C";
			break;
		case Letter::Dp:
			return "D+";
			break;
		case Letter::D:
			return "D";
			break;
		case Letter::F:
			return "F";
			break;
		}
		return "N/A";
	}
}
#endif



