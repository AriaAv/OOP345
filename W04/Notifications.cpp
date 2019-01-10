// Name: Aria Avazkhani
// Seneca Student ID: 134465160
// Seneca email: aavazkhani@myseneca.ca
// Date of completion: 2018-10-04
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include "Notifications.h"
#include "Message.h"
using namespace std;

namespace w4 {
	Notifications::Notifications() {
		mesg = new Message[10];
		loc = 0;
	}

	Notifications::Notifications(const Notifications& other) {
		*this = other;
	}

	Notifications & Notifications::operator=(const Notifications& other) {
		if (this != &other)
			this->mesg = other.mesg;
		return *this;
	}

	Notifications::Notifications(Notifications&& other) {
		*this = std::move(other);
	}

	Notifications & Notifications::operator=(Notifications&& other) {
		if (this != &other) {
			this->mesg = other.mesg;
			this->loc = other.loc;
		}
		return *this;
	}

	Notifications::~Notifications() {
	}

	void Notifications::operator+=(const Message& msg) {
		mesg[loc] = msg;
		loc++;	
	}

	void Notifications::display(ostream& os) const {
		for (size_t i = 0; i < loc; i++) {
			mesg[i].display(os);
		}
	}
}