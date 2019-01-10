// Name: Aria Avazkhani
// Seneca Student ID: 134465160
// Seneca email: aavazkhani@myseneca.ca
// Date of completion: 2018-11-01
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include "TaxableProduct.h"


using namespace w6;
using namespace std;

namespace w6 {

	TaxableProduct::TaxableProduct(string n, double p, char t): Product(n, p){
		tax = t;
	}
	double TaxableProduct::getPrice() const {
		if (tax == 'H') {
			return Product::getPrice() + (Product::getPrice() * rate[0]);
		}
		else if (tax == 'P') {
			return Product::getPrice() + (Product::getPrice() * rate[1]);
		}
		else {
			return Product::getPrice();
		}
	}
	void TaxableProduct::display(ostream& os) const {
		Product::display(os);
		if (tax == 'H') os << " HST";
		else if (tax == 'P') os << " PST";

	}

}