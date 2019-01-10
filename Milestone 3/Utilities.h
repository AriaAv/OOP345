// Name: Aria Avazkhani
// Seneca Student ID: 134465160
// Seneca email: aavazkhani@myseneca.ca
// Date of completion: 2018-11-18
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef M1_UTILITIES_H
#define M1_UTILITIES_H

#include <string>

	class Utilities {
		size_t m_widthField = 1;
		static char m_delimiter;

	public:

		Utilities();
		void setFieldWidth(size_t);
		size_t getFieldWidth() const;
		const std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
		static void setDelimiter(const char);
		const char getDelimiter() const;
	};

#endif
