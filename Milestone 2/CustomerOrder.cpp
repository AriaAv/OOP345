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

using namespace std;

size_t CustomerOrder::m_widthField = 0;

CustomerOrder::CustomerOrder() {
	m_name = "";
	m_product = "";
	m_cntItem = 0u;
	m_lstItem = nullptr;
}

CustomerOrder::CustomerOrder(string& input) {
	bool l_more = true;
	size_t l_pos = 0u;
	size_t l_cnt = 0u;
	Utilities l_it;
	size_t i = 0u;
	while (l_more) {
		if (l_cnt == 0) {
			m_name = l_it.extractToken(input, l_pos, l_more);
		}
		else if (l_cnt == 1) {
			m_product = l_it.extractToken(input, l_pos, l_more);;
		}
		else if (l_cnt == 2) {
			size_t p = l_pos;
			while (l_more) {
				l_it.extractToken(input, p, l_more);
				i++;
			}
			m_cntItem = i;
			i = 0u;
			l_more = true;
			m_lstItem = new ItemInfo*[m_cntItem];

		}
		else {
			m_lstItem[i] = new ItemInfo(l_it.extractToken(input, l_pos, l_more));
			i++;
		}
		l_cnt++;
	}
	if (l_it.getFieldWidth() > m_widthField)
		m_widthField = l_it.getFieldWidth();
}


CustomerOrder::CustomerOrder(CustomerOrder&& src) noexcept {
	*this = move(src);
}

CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src) {
	if (this != &src) {
		delete[] m_lstItem;
		m_name = src.m_name;
		m_product = src.m_product;
		m_cntItem = src.m_cntItem;
		m_lstItem = src.m_lstItem;
		src.m_name = "";
		src.m_product = "";
		src.m_cntItem = 0;
		src.m_lstItem = nullptr;

	}
	return *this;
}

CustomerOrder::~CustomerOrder() {
	for (size_t i = 0u; i < m_cntItem; ++i) {
		delete m_lstItem[i];
		m_lstItem[i] = nullptr;
	}
	delete[] m_lstItem;
	m_lstItem = nullptr;
}

bool CustomerOrder::getItemFillState(std::string item) const {
	bool r = true;
	for (size_t i = 0u; i < m_cntItem; ++i) {
		if (m_lstItem[i]->m_itemName == item)
			r = m_lstItem[i]->m_fillState;
		if (r == false)
			return r;
	}
	return r;
}

bool CustomerOrder::getOrderFillState() const {
	for (size_t i = 0u; i < m_cntItem; ++i) {
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
			os << "Filled" <<" " << m_name << ", " << m_product << "[" 
			   << m_lstItem[i]->m_itemName << "]" << std::endl;
			break;
		}
		else if (item.getName() == m_lstItem[i]->m_itemName) {
			os << "Unable to fill " << m_name << m_product << "[" 
			   << m_lstItem[i]->m_itemName << "]" << endl;
			break;
		}

	}
}
void CustomerOrder::display(std::ostream& os) const {
	os << m_name << " - " << m_product << std::endl;
	for (size_t i = 0u; i < m_cntItem; i++) {
		os << "[" << std::setw(6) << std::right << std::setfill('0') << m_lstItem[i]->m_serialNumber << "] " 
			<< std::setfill(' ') << std::left << std::setw(m_widthField) << m_lstItem[i]->m_itemName << " - "
			<< (m_lstItem[i]->m_fillState ? "FILLED" : "MISSING") << std::endl;
	}
}