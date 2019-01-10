// Name: Aria Avazkhani
// Seneca Student ID: 134465160
// Seneca email: aavazkhani@myseneca.ca
// Date of completion: 2018-11-25
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include "CustomerOrder.h"
#include <iomanip>
#include "Utilities.h"

size_t CustomerOrder::m_widthField = 0;

CustomerOrder::CustomerOrder() {
	m_name = "";
	m_product = "";
	m_cntItem = 0u;
	m_lstItem = nullptr;
}

CustomerOrder::CustomerOrder(std::string& input) {

	size_t m_count = 0u;
	size_t m_pos = 0u;
	bool m_more = true;
	size_t i_cnt = 0u;
	size_t i_pos = 0u;
	Utilities utilities;

	while (m_more) {
		if (m_count == 0)
			m_name = utilities.extractToken(input, m_pos, m_more);
		else if (m_count == 1)
			m_product = utilities.extractToken(input, m_pos, m_more);
		else if (m_count == 2) {
			i_pos = m_pos;
			while (m_more) {
				utilities.extractToken(input, i_pos, m_more);
				i_cnt++;
			}
			m_cntItem = i_cnt;
			i_cnt = 0u;
			m_more = true;
			m_lstItem = new ItemInfo*[m_cntItem];
		}
		else {
			m_lstItem[i_cnt] = new ItemInfo(utilities.extractToken(input, m_pos, m_more));
			i_cnt++;
		}
		m_count++;
	}

	if (utilities.getFieldWidth() > m_widthField) {
		m_widthField = utilities.getFieldWidth();
	}

}

CustomerOrder::CustomerOrder(CustomerOrder&) {
	throw "ERROR:  Cannot make copies.";
}

CustomerOrder::CustomerOrder(CustomerOrder&& other) noexcept {
	*this = std::move(other);
}

CustomerOrder& CustomerOrder::operator=(CustomerOrder&& other) {
	if (this != &other) {
		if (m_lstItem != nullptr) {
			for (size_t i = 0u; i < m_cntItem; i++)
				delete m_lstItem[i];
			delete[] m_lstItem;
		}
		m_name = other.m_name;
		m_product = other.m_product;
		m_cntItem = other.m_cntItem;
		m_lstItem = other.m_lstItem;
		m_widthField = other.m_widthField;
		other.m_name = "";
		other.m_product = "";
		other.m_cntItem = 0;
		other.m_lstItem = nullptr;
	}
	return *this;
}

CustomerOrder::~CustomerOrder() {
	if (m_lstItem) {
		for (size_t i = 0u; i < m_cntItem; i++) {
			delete m_lstItem[i];
			m_lstItem[i] = nullptr;
		}
	}

	delete[] m_lstItem;
	m_lstItem = nullptr;
}

bool CustomerOrder::getItemFillState(std::string item) const {
	bool itemFillState = true;
	for (size_t i = 0u; i < m_cntItem; i++) {
		if (m_lstItem[i]->m_itemName == item)
			itemFillState = m_lstItem[i]->m_fillState;

		if (itemFillState == false)
			return itemFillState;
	}
	return itemFillState;
}

bool CustomerOrder::getOrderFillState() const {
	for (size_t i = 0u; i < m_cntItem; i++) {
		if (m_lstItem[i]->m_fillState == false)
			return false;
	}
	return true;
}

void CustomerOrder::fillItem(Item& item, std::ostream& os) {
	for (size_t i = 0u; i < m_cntItem; i++) {
		if (m_lstItem[i]->m_itemName == item.getName() && item.getQuantity() > 0) {

			m_lstItem[i]->m_fillState = true;
			item.updateQuantity();

			m_lstItem[i]->m_serialNumber = item.getSerialNumber();

			os << "Filled" << " " << m_name << ", " << m_product << "["
				<< m_lstItem[i]->m_itemName << "]" << std::endl;

		}
		else if (item.getName() == m_lstItem[i]->m_itemName) {

			os << "Unable to fill " << m_name
				<< m_product << "[" << m_lstItem[i]->m_itemName << "]" << std::endl;

			break;
		}

	}
}

void CustomerOrder::display(std::ostream& os) const {
	os << m_name << " - " << m_product << std::endl;

	for (size_t i = 0u; i < m_cntItem; i++) {
		os << "[" << std::setw(6) << std::right << std::setfill('0')
			<< m_lstItem[i]->m_serialNumber << "] "

			<< std::setfill(' ') << std::left << std::setw(m_widthField)
			<< m_lstItem[i]->m_itemName

			<< " - " << (m_lstItem[i]->m_fillState ? "FILLED" : "MISSING") << std::endl;
	}

}

