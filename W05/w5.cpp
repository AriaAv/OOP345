// Workshop 5 - Lambda Expression
// 345_w5.cpp
// Chris Szalwinski & Dr. Elliott Coleshill
// 2018-08-22

#include <iostream>
#include "Grades.h"
#include "Letter.h"

using namespace sict;

int main(int argc, char* argv[]) {

	std::cout << "Command Line: ";
	for (int i = 0; i < argc; i++)
		std::cout << argv[i] << ' ';
	std::cout << std::endl;

	if (argc == 1) {
		std::cerr << "\n*** Insufficient number of arguments ***\n";
		std::cerr << "Usage: " << argv[0] << " fileName \n";
		return 1;
	}
	else if (argc != 2) {
		std::cerr << "\n*** Too many arguments ***\n";
		std::cerr << "Usage: " << argv[0] << " fileName \n";
		return 2;
	}

	//TODO: Update the main functions as per the specifications here

	else {
		try {
			sict::Grades grades(argv[1]);
			auto letter = [](double _grade) {
				if (_grade >= 90) return let(Letter::Ap);
				else if (_grade >= 80) return let(Letter::A);
				else if (_grade >= 75) return let(Letter::Bp);
				else if (_grade >= 70) return let(Letter::B);
				else if (_grade >= 65) return let(Letter::Cp);
				else if (_grade >= 60) return let(Letter::C);
				else if (_grade >= 55) return let(Letter::Dp);
				else if (_grade >= 50) return let(Letter::D);
				else return  let(Letter::F);
			};
			grades.displayGrades(std::cout, letter);
		}
		catch (const char* msg) {
			std::cerr << argv[0] << msg
				<< argv[1] << "\n";
			return 2;
		}
	}
	return 0;
}