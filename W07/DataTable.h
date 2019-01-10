// Name: Aria Avazkhani
// Seneca Student ID: 134465160
// Seneca email: aavazkhani@myseneca.ca
// Date of completion: 2018-11-08
//
// I confirm that the content of this file is created by me,
// with the exception of the parts provided to me by my professor.

#ifndef W7_DATATABLE_H
#define W7_DATATABLE_H

#include <fstream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>

namespace w7 {
	template <typename T>
	class DataTable {
		int width;
		int dec;
		std::vector<T> x;
		std::vector<T> y;
	public:
		DataTable(std::ifstream& file, int w, int d) {
			width = w;
			dec = d;
			T temp;

			while (file >> temp){
				x.push_back(temp);
				file >> temp;
				y.push_back(temp);
			}
		}

		T mean() const {
			return (std::accumulate(y.begin(), y.end(), (T)0))/getSize();
		}

		T sigma() const {
			T m = mean();
			T s = std::accumulate(y.begin(), y.end(), (T)0, [m](T a, T b) { return a + (b - m) * (b - m); });
			return sqrt(static_cast<T>(s / (getSize() - 1)));
		}

		T median() const {
			std::vector<T> z = y;
			std::sort(z.begin(), z.end());
			return z[getSize() / 2];
		}

		void regression(T& slope, T& y_intercept) const {
			T t_xy = std::inner_product(x.begin(), x.end(), y.begin(), (T)0);
			T t_x = std::accumulate(x.begin(), x.end(), (T)0);
			T t_y = std::accumulate(y.begin(), y.end(), (T)0);
			T t_xx = std::inner_product(x.begin(), x.end(), x.begin(), (T)0);
			slope = (getSize() * t_xy - t_x * t_y) / (getSize() * t_xx - t_x * t_x);
			y_intercept = (t_y - slope * t_x) / getSize();
		}

		void display(std::ostream& os) const {
			os << std::setw(width) << std::setprecision(dec) 
			   << std::fixed << 'x';
			os << std::setw(width) << 'y' << std::endl;
			for (size_t i = 0; i < x.size(); ++i) {
				os << std::setw(width) << x[i] << std::setw(width)  << y[i] << std::endl;
			}
		}

		size_t getSize() const {
			return y.size();
		}

		friend std::ostream& operator<<(std::ostream& os, const DataTable& data) {
			data.display(os);
			return os;
		}
	};

}

#endif