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
			copy_raw_list(arr, r, Size);
		}
		Array() : arr{} {

		}

		T& at(index i) {
			if (i > Size-1) {
				throw out_of_range_exception;
			}
			return arr[i];
		}

		void set(index i, const T& v) {
			at(i) = v;
		}

		T& operator[](index i) {
			return at(i);
		}
	};
}

#endif // !__USTD__ARRAY_H__
