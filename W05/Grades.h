// Name: Aria Avazkhani
// Seneca Student ID: 134465160
// Seneca email: aavazkhani@myseneca.ca
// Date of completion: 2018-10-11
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.


#ifndef W5_GRADES_H
#define W5_GRADES_H

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

namespace sict {
	class Grades {
		std::string* num;
		double* gr;
		int line;
	public:
		Grades();
		Grades(char* file);
		~Grades();

		Grades(const Grades&) = delete;
		void operator = (const Grades&) = delete;

		Grades(Grades&&) = delete;
		void operator = (Grades&&) = delete;

		template <typename F>
		void displayGrades(std::ostream& os, F exp) const {
			for (int i = 0; i < line; ++i) {
				os << std::right << std::setw(10)
					<< num[i] << " ";
				os << std::setw(5) << std::fixed << std::setprecision(2)<< gr[i] << " ";
				os << std::setw(4) << std::left << exp(gr[i]) << std::endl;
			}
		}
	};
}

#endif



