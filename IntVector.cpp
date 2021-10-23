#include "IntVector.h"
namespace P3_1 {

	IntVector::IntVector(int el) {						// 1 element constructor 
		ar[0] = el;							// assignment to 0 element of the passed value
		cSZ = 1;
	}
	IntVector::IntVector(int size, const int* ar1) {			// elements massive constructor
		if (size > SZ)
			throw std::exception("Vector owerflow");
		for (int i = 0; i < size; i++) {
			ar[i] = ar1[i];
		}
		cSZ = size;
	}



	std::ostream& IntVector::print(std::ostream& s, int a, int l) const {	// output to stream and selection part of a vector with given length 
		if (cSZ == 0)
			s << "Vector is empty";
		else if (a + l > cSZ)
			s << "Too much elements";
		else
			for (int i = a; i < a + l; i++)				// in default output a = 0, l = cSZ
				s << ar[i] << ' ';
		s << std::endl;
		return s;
	}

	std::ostream& operator <<(std::ostream& s, const IntVector& iv) {	// << overload
		if (iv.cSZ == 0)
			s << "Vector is empty";
		else
			for (int i = 0; i < iv.cSZ; i++)
				s << iv.ar[i] << ' ';
		s << std::endl;
		return s;
	}



	void IntVector::sum(const IntVector& other) {				// sum vectors (v0+=v1)
		int x;
		if (other.cSZ <= cSZ)
			x = cSZ;
		else
			x = other.cSZ;
		for (int i = 0; i < x; i++) {					// componentwise addition of the second vector to the first 
			if (i < cSZ && i < other.cSZ)
				ar[i] += other.ar[i];
			else if (i >= cSZ) {
				ar[i] = other.ar[i];
				cSZ++;
			}
		}
	}

	IntVector& IntVector::operator +=(const IntVector& iv) {		// += overload
		int x;
		if (iv.cSZ <= cSZ)
			x = cSZ;
		else
			x = iv.cSZ;
		for (int i = 0; i < x; i++) {					// componentwise addition of the transferred vector to this
			if (i < cSZ && i < iv.cSZ)
				ar[i] += iv.ar[i];
			else if (i >= cSZ) {
				ar[i] = iv.ar[i];
				cSZ++;
			}
		}
		return *this;
	}



	void IntVector::addEl(int el) {						// including a new element in a vector
		if (cSZ == SZ)
			throw std::exception("Vector owerflow");
		ar[cSZ] = el;
		cSZ++;
	}



	void IntVector::sort(int first, int last) {				// quicksort vector			
		if (cSZ == 0)
			throw std::exception("Vector is empty");
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



	int IntVector::maxNum() const {						// finding maximum element
		if (cSZ == 0)
			throw std::exception("Vector is empty");
		int m = ar[0];
		for (int i = 1; i < cSZ; i++) {
			if (ar[i] > m)
				m = ar[i];
		}
		return m;
	}






	IntVector IntVector::operator -() {					// - overload	
		for (int i = 0; i < cSZ; i++) {
			ar[i] = -ar[i];
		}
		return *this;
	}

	IntVector operator +(const IntVector& iv1, const IntVector& iv2) {	// + overload
		IntVector iv3;
		int x;
		if (iv1.cSZ <= iv2.cSZ)
			x = iv2.cSZ;
		else
			x = iv1.cSZ;
		for (int i = 0; i < x; i++) {					// componentwise addition of two vectors
			if (i < iv1.cSZ && i < iv2.cSZ)
				iv3.addEl(iv1.ar[i] + iv2.ar[i]);
			else if (i >= iv1.cSZ)
				iv3.addEl(iv2.ar[i]);
			else
				iv3.addEl(iv1.ar[i]);
		}
		return iv3;
	}

	int& IntVector::operator[] (const int index) {				// [] overload
		if (index < 0 || index >= SZ)
			throw std::exception("Incorrect index");
		return ar[index];
	}

	IntVector& IntVector::operator++() {					// pre ++ overload
		for (int i = 0; i < cSZ; i++) {
			ar[i]++;
		}
		return *this;
	}

	IntVector IntVector::operator++(int) {					// post ++ overload
		IntVector temp = *this;
		++* this;
		return temp;
	}
}
