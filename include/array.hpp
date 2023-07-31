#ifndef __USTD__ARRAY_H__
#define __USTD__ARRAY_H__
#include "exception.hpp"


namespace ustd {

	typedef unsigned long long int index;


	template <typename T, int Size>
	class Array {
		T arr[Size];

	public:
		Array(T r[Size]){
			for (int i = 0; i < Size; i++) {
				arr[i] = r[i];
			}
		}

		T& get(index i) {
			if (i > Size-1) {
				throw out_of_range_exception;
			}
			return arr[i];
		}

		void set(index i, T v) {
			if (i > Size-1) {
				throw out_of_range_exception;
			}
			arr[i] = v;
		}

		T& operator[](index i) {
			if (i > Size-1) {
				throw out_of_range_exception;
			}
			return arr[i];
		}
	};
}

#endif // !__USTD__ARRAY_H__
