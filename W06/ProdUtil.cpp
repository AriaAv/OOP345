// Name: Aria Avazkhani
// Seneca Student ID: 134465160
// Seneca email: aavazkhani@myseneca.ca
// Date of completion: 2018-11-01
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#include "Product.h"
#include "ProdUtil.h"
#include "TaxableProduct.h"
#include <sstream>

using namespace w6;
using namespace std;

namespace w6 {

	std::ostream& operator<<(ostream& os, const iProduct& pr) {
		pr.display(os);
		cout << endl;
		return os;
	}

	iProduct* readProduct(ifstream& file) {

		string tmp;
		getline(file, tmp);

		if (!tmp.empty()) {
			iProduct* temp;
			string no_t;
			double pr_t;
			char tax_t;
			istringstream t(tmp);
			t >> no_t;
			t >> pr_t;
			t >> tax_t;
			if (tax_t == 'C' || tax_t == 'M')
				throw string("Unrecognizable Tax Code!");
			else if (tax_t == 'P' || tax_t == 'H')
				temp = new TaxableProduct(no_t, pr_t, tax_t);
			else
				temp = new Product(no_t, pr_t);
			return temp;
		}
		else {
			throw string("no such record! Reached the end of the file!");
		}
		return nullptr;
	}

}









		/*	
		string tmp;
		getline(file, tmp);

		if (!tmp.empty()) {
			iProduct* temp = nullptr;
			int no_t;
			double pr_t;
			char tax_t = '\n';
			size_t pos = 0u;
			size_t cnt = 0u;

			while ((pos = tmp.find(' ')) != string::npos) {
				if (cnt == 0u) {
					no_t = stoi(tmp.substr(0, pos));
				}
				else if (cnt == 1u)
					if (tmp[0] == ' ')
						tmp.erase(0, 1);
				pr_t = stod(tmp.substr(0, pos));
				tmp.erase(0, pos + 1);
				cnt++;
			}
			if (cnt == 1u)
				pr_t = stod(tmp);
			else if (cnt == 2u)
				tax_t = tmp[0];

			if (tax_t == 'H' || tax_t == 'P') {
				temp = new TaxableProduct(no_t, pr_t, tax_t);
				throw string("done!");
			}
			else if (tax_t == '\n') {
				temp = new Product(no_t, pr_t);
				throw string("done!");
			}
			else
				throw string("Unrecognizable Tax Code!");

			return temp;
		}
		else {
			throw string("no such record! Reached the end of the file!");
			
		}
		return nullptr;
		*/
