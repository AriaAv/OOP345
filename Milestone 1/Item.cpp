// Name: Aria Avazkhani
// Seneca Student ID: 134465160
// Seneca email: aavazkhani@myseneca.ca
// Date of completion: 2018-11-18
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include "Item.h"
#include <iomanip>

	unsigned int Item::m_widthField = 0;

	Item::Item(const std::string& it) {
		bool l_more = true;
		size_t l_pos = 0;
		size_t l_cnt = 0;
		Utilities l_it;
		while (l_more && l_cnt < 4) {
			if (l_cnt == 0) 
				m_name = l_it.extractToken(it, l_pos, l_more);
			else if (l_cnt == 1) 
				m_serialNumber = (unsigned int)std::stoi(l_it.extractToken(it, l_pos, l_more));
			else if (l_cnt == 2) {
				m_quantity = (unsigned int)std::stoi(l_it.extractToken(it, l_pos, l_more));
				if (l_it.getFieldWidth() > m_widthField)
					m_widthField = l_it.getFieldWidth();
			}
			else m_description = l_it.extractToken(it, l_pos, l_more);
			l_cnt++;
		}
		

	}

	const std::string& Item::getName() const {
		return m_name;
	}

	const unsigned int Item::getSerialNumber() {
		unsigned int val = m_serialNumber;
		m_serialNumber++;
		return val;
	}

	const unsigned int Item::getQuantity() {
		return m_quantity;
	}

	void Item::updateQuantity() {
		if (m_quantity - 1 >= 0)
			m_quantity--;
	}

	void Item::display(std::ostream& os, bool full) const {
		if (full) {
			os << std::setw(m_widthField) << std::left  << m_name;
			os << " [" << std::setw(6) << std::right << std::setfill('0') << m_serialNumber << std::setfill(' ') << std::left;
			os << "] Quantity: " << std::setw(m_widthField) << std::left  << m_quantity;
			os << " Description: " << m_description << std::endl;
		}
		else {
			
			os << std::setw(m_widthField) << std::left << m_name;
			os << " [" << std::right << std::setw(6) << std::setfill('0') << m_serialNumber << std::setfill(' ') << std::left << "]" << std::endl;
		}

	}
