// Name: Aria Avazkhani
// Seneca Student ID: 134465160
// Seneca email: aavazkhani@myseneca.ca
// Date of completion: 2018-10-30
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

// ProdUtil.h
#ifndef W6_PRODUTIL_H
#define W6_PRODUTIL_H

#include "iProduct.h"

namespace w6
{
	std::ostream& operator<<(std::ostream&, const iProduct&);
	iProduct* readProduct(std::ifstream&);
}
#endif