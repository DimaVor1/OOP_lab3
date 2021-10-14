#include "IntVector.h"
namespace P3_1 {
	IntVector::IntVector(int el) {
		ar[0] = el;
		cSZ = 1;
	}

	IntVector::IntVector(int size, int *ar1) {
		if (size > SZ) 
			throw std::exception("Vector owerflow");
		for (int i = 0; i < size; i++) {
			ar[i] = ar1[i];
		}
		cSZ = size;
	}

	void IntVector::sum(IntVector a) {
		int x;
		if (a.getCSz() <= cSZ)
			x = cSZ;
		else
			x = a.getCSz();
		for (int i = 0; i < x; i++) {
			if (i < cSZ && i < a.getCSz())
				ar[i] += a.getArEl(i);
			else if (i >= cSZ) {
				ar[i] = a.getArEl(i);
				cSZ++;
			}
		}
	}

	void IntVector::addEl(int el) {
		if (cSZ == SZ)
			throw std::exception("Vector owerflow");
		ar[cSZ] = el;
		cSZ++;
	}

	int IntVector::maxNum() const {
		if (cSZ == 0)
			throw std::exception("Vector is empty");
		int m = ar[0];
		for (int i = 1; i < cSZ; i++) {
			if (ar[i] > m)
				m = ar[i];
		}
		return m;
	}

	void IntVector::sort(int first, int last){
		int i = first, j = last, x = ar[(first + last) / 2];
		do {
			while (ar[i] < x) i++;
			while (ar[j] > x) j--;

			if (i <= j) {
				int tmp = ar[i];
				ar[i] = ar[j];
				ar[j] = tmp;
				i++;
				j--;
			}
		} while (i <= j);

		if (i < last)
			sort(i, last);
		if (first < j)
			sort(first, j);
	}


	std::ostream& IntVector::print(std::ostream& s, int a, int l) const
	{
		if (cSZ == 0)
			s << "Vector is empty";
		else if (a + l > cSZ)
			s << "Too much elements";
		else
			for (int i = a; i < a+l; i++)
				s << ar[i] << ' ';
		s << std::endl;
		return s;
	}
}
