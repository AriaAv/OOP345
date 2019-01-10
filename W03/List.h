// Name: Aria Avazkhani
// Seneca Student ID: 134465160
// Seneca email: aavazkhani@myseneca.ca
// Date of completion: 2018-09-28
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef LIST_H
#define LIST_H

template<typename T, int N>
class List {
	T arr[N];
	int asize = 0;

public:

	List() {
		for(int i=0;i<N;i++)
		arr[i] = {};
	}

	size_t size() const {
		return asize;
	}

	const T& operator[](int index) const {
		return arr[index];
	}

	void operator+=(const T& nw) {
		if (size() < N) {
			arr[size()] = nw;
			asize++;
		}
	}
};

#endif