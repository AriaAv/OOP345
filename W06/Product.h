// Name: Aria Avazkhani
// Seneca Student ID: 134465160
// Seneca email: aavazkhani@myseneca.ca
// Date of completion: 2018-10-30
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef W6_PRODUCT_H
#define W6_PRODUCT_H
#include "iProduct.h"
#include <string>

namespace w6 {

	class Product : public iProduct {
		std::string no;
		double pr;
	public:
		Product();
		Product(std::string, double);
		double getPrice() const;
		void display(std::ostream&) const;
	};

}

#endif