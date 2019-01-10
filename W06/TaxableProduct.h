// Name: Aria Avazkhani
// Seneca Student ID: 134465160
// Seneca email: aavazkhani@myseneca.ca
// Date of completion: 2018-10-30
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef W6_TAXABLEPRODUCT_H
#define W6_TAXABLEPRODUCT_H
#include "Product.h"
#include <array>

namespace w6 {

	class TaxableProduct : public Product {
		char tax;
		std::array<double, 2> rate{{0.13, 0.08}};
	public:
		TaxableProduct(std::string, double, char);
		double getPrice() const;
		void display(std::ostream&) const;
	};

}

#endif

