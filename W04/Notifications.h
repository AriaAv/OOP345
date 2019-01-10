// Name: Aria Avazkhani
// Seneca Student ID: 134465160
// Seneca email: aavazkhani@myseneca.ca
// Date of completion: 2018-10-04
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

// Manages access to a set of up to 10 instances of the Message type
#ifndef W4_NOTIFICATIONS_H
#define W4_NOTIFICATIONS_H

#include "Message.h"

namespace w4 {
	class Notifications {
		Message* mesg;
		size_t loc;
	public:
		Notifications();
		Notifications(const Notifications&);
		Notifications& operator=(const Notifications&);
		Notifications(Notifications&&);
		Notifications& operator=(Notifications&&);
		~Notifications();
		void operator+=(const Message& msg);
		void display(std::ostream& os) const;
	};
}
#endif



