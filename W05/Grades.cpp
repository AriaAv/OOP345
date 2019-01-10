// Name: Aria Avazkhani
// Seneca Student ID: 134465160
// Seneca email: aavazkhani@myseneca.ca
// Date of completion: 2018-10-11
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include "Grades.h"
using namespace sict;
using namespace std;

namespace sict {
	
	Grades::Grades() :num(nullptr), gr(nullptr), line(0) {};
	Grades::Grades(char* file) {
		try {
			std::ifstream input(file);
			if (input) {
				std::string tempStr;
				line = 0;

				while (!input.eof()) {
					getline(input, tempStr);
					if (tempStr != "")
						line++;
				}
				input.clear();
				input.seekg(0);
				num = new std::string[line];
				gr = new double[line];
				for (int i = 0; i < line; i++) {
					input >> num[i];
					input >> gr[i];
					input.ignore(2000, '\n');
				}
			}
			input.close();
		}
		catch (std::bad_alloc) {
			throw ("Unable to open the file.");
		}
	}
	Grades::~Grades() { 
		delete[] num;
		delete[] gr; }
}
