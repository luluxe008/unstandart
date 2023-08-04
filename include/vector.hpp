#ifndef __USTD_VECTOR_H__
#define __USTD_VECTOR_H__

#include "memory.hpp"
#include "exception.hpp"

namespace ustd {

	typedef unsigned long long int index;

	template<typename T>
	class Vector {
		/*
			DISCLAIMER:
				The ustd::Vector class is meant to store dynamically a list of item. This class allocate and free memory as soon
				as it can, so for every changement the memory taken will change. This is very time consuming.
		*/
		ustd::SP<T> _list;
		size_t _size;
	public:
		Vector() {
			_size = 0;

		}

		void push_back(const T& v) {
			T* tmp = new T[_size + 1];
			copy_raw_list(tmp, _list.get_ptr(), _size);
			tmp[_size] = v;
			_list.reallocate(tmp);
			_size++;
		}

		void pop_back() {
			if (_size == 0) {
				throw out_of_range_exception;
			}
			T* tmp = new T[_size - 1];
			copy_raw_list(tmp, _list.get_ptr(), _size - 1);
			_list.reallocate(tmp);
			_size--;
		}

		void push_front(const T& v) {
			T* tmp = new T[_size + 1];
			copy_raw_list(tmp + 1, _list.get_ptr(), _size);
			tmp[0] = v;
			_list.reallocate(tmp);
			_size++;
		}

		void pop_front() {
			if (_size == 0) {
				throw out_of_range_exception;
			}
			T* tmp = new T[_size - 1];
			copy_raw_list(tmp, _list.get_ptr() + 1, _size);
			_list.reallocate(tmp);
			_size--;
		}

		void clear() {
			_size = 0;
			_list.reallocate(new T[0]); // to avoid check_null_pointer exception
		}
		
		bool is_equal_to(const ustd::Vector<T>& v) {
			if (v._size != _size) {
				return false;
			}
			for (size_t i = 0; i < _size; i++) {
				if (v[i] != at(i)) {
					return false;
				}
			}
			return true;
		}

		bool operator==(const ustd::Vector<T>& v) {
			return is_equal_to(v);
		}

		bool operator!=(const ustd::Vector<T>& v) {
			return !is_equal_to(v);
		}

		T& at(index i) {
			if (i > _size - 1) {
				throw bad_index_exception;
			}
			return *(_list.get_ptr() + i);
		}

		T& operator[](index i) {
			return at(i);
		}

		void set(index i, const T& v) {
			at(i) = v;
		}

		T& last() {
			if (_size == 0) {
				throw out_of_range_exception;
			}
			return at(_size-1);
		}
		T& first() {
			if (_size == 0) {
				throw out_of_range_exception;
			}
			return at(0);
		}
		size_t size() {
			return _size;
		}
	};
}

#endif // !__USTD_VECTOR_H__
