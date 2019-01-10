// Name: Aria Avazkhani
// Seneca Student ID: 134465160
// Seneca email: aavazkhani@myseneca.ca
// Date of completion: 2018-09-28
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef PAIR_H
#define PAIR_H

template <typename A, typename B>
class Pair {

	A a;
	B b;
public:
	Pair() : a {}, b {} {
	}

	Pair(const A& f, const B& s) : a{ f } , b{ s } {
	}

	const A& getKey() const	{
		return a;
	}
	const B& getValue() const {
		return b;
	}
};

#endif


