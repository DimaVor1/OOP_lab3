#ifndef _INTVECTOR_H_
#define _INTVECTOR_H_

#include <iostream>
#include <cmath>
#include <strstream>

namespace P3_1 {

	template <class T>
	int getNum(T& a) {
		std::cin >> a;
		while (!std::cin.good()) {
			std::cout << "Error, try again" << std::endl;
			if (std::cin.eof())
				return -1;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		return 1;
	}

	class IntVector{
	private: 
		static const int SZ = 10;
		int cSZ;
		int ar[SZ];
	public:
		IntVector(): cSZ(0) {};
		IntVector(int el);
		IntVector(int size, int *ar);

		std::ostream& print(std::ostream&, int a, int l) const;

		int getArEl(int i) { return ar[i]; }
		int getCSz() { return cSZ; }

		void sum(IntVector);
		void addEl(int el);
		void sort(int first, int last);
		int maxNum() const;
	};
}
#endif
