// Name: Aria Avazkhani
// Seneca Student ID: 134465160
// Seneca email: aavazkhani@myseneca.ca
// Date of completion: 2018-10-04
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include "Message.h"
using namespace std;

namespace w4 {
	Message::Message() : Message("", "", "") {
	}

	Message::Message(String p_us, String p_tw, String p_rp)
		: us{ p_us }, tw{ p_tw }, rp{ p_rp } {
	}

	Message::Message(ifstream& in, char c) {
		String temps, un, rep, cont;
		getline(in, temps, c);
		un = temps.substr(0, temps.find(' '));
		size_t loc = temps.find(un);
		temps.erase(loc, un.length() + 1);
		if (temps.find('@') != static_cast<size_t>(-1)){
			temps.erase(0, 1);
			rep = temps.substr(0, temps.find(' '));
			temps.erase(temps.find(rep), temps.find(' ') + 1);
		}
		else 
			rep = "";
		cont = temps;
		if (!cont.empty())
			*this = Message(un, cont, rep);
	}

	bool Message::empty() const {
		return (us.empty() && tw.empty() && rp.empty());
	}

	void Message::display(ostream& os) const {
		os << "Message\n" << " User  : " << this->us << "\n";
		if (this->rp.length() > 0)
			os << " Reply : " << rp << "\n";
		os << " Tweet : " << tw << "\n\n";
	}
}
