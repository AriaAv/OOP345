// Name: Aria Avazkhani
// Seneca Student ID: 134465160
// Seneca email: aavazkhani@myseneca.ca
// Date of completion: 2018-11-25
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.


#ifndef M1_CUSTOMERORDER_H
#define M1_CUSTOMERORDER_H

#include "Item.h"

struct ItemInfo
{
	std::string m_itemName;
	unsigned int m_serialNumber = 0;
	bool m_fillState = false;

	ItemInfo(std::string src) : m_itemName(src) {};
};

class CustomerOrder {
	std::string m_name;
	std::string m_product;
	unsigned int m_cntItem;
	ItemInfo** m_lstItem = nullptr;
	static size_t m_widthField;

public:
	CustomerOrder();
	CustomerOrder(std::string&);
	CustomerOrder(CustomerOrder&) { throw "ERROR: Cannot make copies."; };
	CustomerOrder& operator=(CustomerOrder&) = delete;
	CustomerOrder(CustomerOrder&&) noexcept;
	CustomerOrder& operator=(CustomerOrder&&);
	~CustomerOrder();
	bool getItemFillState(std::string) const;
	bool getOrderFillState() const;
	void fillItem(Item& item, std::ostream&);
	void display(std::ostream&) const;
};


#endif