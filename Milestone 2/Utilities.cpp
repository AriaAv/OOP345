// Name: Aria Avazkhani
// Seneca Student ID: 134465160
// Seneca email: aavazkhani@myseneca.ca
// Date of completion: 2018-11-18
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include "Utilities.h"

using namespace std;

	char Utilities::m_delimiter = ' ';

	Utilities::Utilities() {
		m_widthField = 1;
	}

	void Utilities::setFieldWidth(size_t p_width) {
		m_widthField = p_width;
	}

	size_t Utilities::getFieldWidth() const {
		return m_widthField;
	}

	const string Utilities::extractToken(const string& str, size_t& next_pos, bool& more) {
		string token = str.substr(next_pos);
		size_t pos = token.find(m_delimiter);
		if (pos != std::string::npos) {
			token = token.substr(0, pos);
			next_pos += pos + 1;
			if (token == "")
				throw "empty token";
			more = true;
		}

		else {
			more = false;
		}
		if (token.length() > m_widthField)
			setFieldWidth(token.length());

		return token;
	}
	void Utilities::setDelimiter(const char p_del) {
		m_delimiter = p_del;
	}

	const char Utilities::getDelimiter() const {
		return m_delimiter;
	}