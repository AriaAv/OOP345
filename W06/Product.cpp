// Name: Aria Avazkhani
// Seneca Student ID: 134465160
// Seneca email: aavazkhani@myseneca.ca
// Date of completion: 2018-11-01
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.


#include "Product.h"
#include "TaxableProduct.h"
#include <iomanip>

using namespace w6;
using namespace std;

namespace w6 {

	Product::Product() {
		no = "";
		pr = 0.0;
	}

	Product::Product(string n, double p) {
		no = n;
		pr = p;
	}
	double Product::getPrice() const {
		return pr;
	}
	void Product::display(ostream& os) const {
		os << setw(16) << no << setw(16) << fixed << pr;

	}

}