// Name: Aria Avazkhani
// Seneca Student ID: 134465160
// Seneca email: aavazkhani@myseneca.ca
// Date of completion: 2018-09-21
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include "Text.h"

using namespace std;

namespace w2 {


	Text::Text() : cnt(0) {
		ref = nullptr;
		name = "\0";
	}

	Text::Text(string source) : cnt(0) {
		ref = new string[cnt];
		name = source;
		if (!name.empty()) {
			ifstream f(name);
			string l;
			while (getline(f, l))
				cnt++;
			ref = new string[cnt];
			int i = 0;
			while (getline(f, l)) {
				ref[i] = l;
				i++;
			}
		}
	}

	Text::Text(const Text& rhs) {
		*this = rhs;
	}

	Text& Text::operator=(const Text& source) {
		cnt = source.cnt;
		name = source.name;

		if (this != &source) {
			delete[] ref;
			ref = new string[cnt];
			for (size_t i = 0; i < cnt; i++)
				ref[i] = source.ref[i];
		}
		return *this;
	}

	Text::Text(Text&& rhs) {
		*this = move(rhs);
	}

	Text& Text::operator=(Text&& source) {
		if (this != &source) {
			name = source.name;
			cnt = source.cnt;
			delete[] ref;
			ref = source.ref;
			source.ref = nullptr;
		}
		return *this;
	}

	Text::~Text() {
		delete[] ref;
		ref = nullptr;
	}

	size_t Text::size() const {
		return cnt;
	}
}
