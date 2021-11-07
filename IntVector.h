#ifndef _INTVECTOR_H_
#define _INTVECTOR_H_

#include <iostream>
#include <cmath>
#include <strstream>

namespace P3_1 {

	//////////////////////////////////////////////////////////////////////////////
	//				class and methods			    //			
	//////////////////////////////////////////////////////////////////////////////

	class IntVector{
	private: 
		static const int SZ = 10;							// maximum vector size
		int cSZ;									// current size			
		int ar[SZ];									// array of vector elements
	public:
		IntVector(): cSZ(0) {};								// default constructor
		IntVector(int el);								// 1 element constructor 
		IntVector(int size, const int *ar);						// elements massive constructor
		
		std::ostream& print(std::ostream&, int a, int l) const;				// output to stream and selection part of a vector with given length
		friend std::ostream& operator <<(std::ostream&, const IntVector&);		// << overload	
						
		void sum(const IntVector &);							// sum vectors (v0+=v1)
		IntVector& operator +=(const IntVector&);					// += overload

		void addEl(int el);								// including a new element in a vector
		void sort(int first, int last);							// quicksort vector
		int maxNum() const;								// finding maximum element

		//////////////////////////////////////////////////////////////////////////
		//	auxiliary methods and overloads at the request of the teacher	//			
		//////////////////////////////////////////////////////////////////////////

		IntVector operator -();								// - overload
		friend IntVector operator+(const IntVector& iv1, const IntVector& iv2);		// + overload
		int& operator[] (const int index);						// [] overload				
		IntVector& operator++();							// pre++ overload
		IntVector operator++(int);							// post++ overload

		int getArEl(int i) const { return ar[i]; }					// getters
		int getCSz() const { return cSZ; }						// getters
		~IntVector() = default;								// destructor
	};


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
}
#endif
