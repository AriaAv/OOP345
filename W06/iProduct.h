// Name: Aria Avazkhani
// Seneca Student ID: 134465160
// Seneca email: aavazkhani@myseneca.ca
// Date of completion: 2018-10-30
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

// iProduct.h
#ifndef W6_IPRODUCT_H
#define W6_IPRODUCT_H
#include <fstream>
#include <string>
#include <iostream>

namespace w6
{
	class iProduct
	{
	public:
		virtual double getPrice() const = 0;
		virtual void display(std::ostream&) const = 0;
	};
}
#endif