#ifndef __USTD_STRING_H__
#define __USTD_STRING_H__

#include "memory.hpp"
#include <cstring>

namespace ustd {

	typedef unsigned long long int index;

	
	class BasicString {
	public:
		// THE LAST CHARACTER IS ALWAYS \0

	protected:
		ustd::SP<char> _str;
		/*
			grace a ustd::SP.reallocate on peut change la taille du contenu du pointeur tout en gardant de la sécurité et des ref count
		*/
		size_t size;

	public:
		BasicString() {
			size = 0;
			// _str initialize itself automatically
		}

		BasicString(const char* s) {
			ustd::check_null_pointer(s);


			size = strlen(s);

			char* tmp = new char[size + 1] {0}; //size+1 pour le \0
			strcpy_s(tmp, size+1,s);
			_str.reallocate((char*)tmp);
		}

		

		BasicString(const BasicString& s){ // copy, no ref
			size = s.size;
			char* tmp = new char[size + 1] {0};
			strcpy_s(tmp, size+1, s.c_str());
			_str.reallocate((char*)tmp);
		}

		

		void append(const char* s) {
			ustd::check_null_pointer(s);

			size += strlen(s);
			char* tmp = new char[size + 1] {0};
			strcat_s(tmp, size+1,_str.get_ptr());
			strcat_s(tmp, size + 1, s);
			_str.reallocate(tmp);
		}

		
		BasicString slice(index a, index b) const{
			if (b < a) {
				throw bad_index_exception; // b must  be bigger than a
			}
			if (a > size || b > size) {
				throw out_of_range_exception; // too big
			}
			char* tmp = new char[(b - a) + 1] {0};// the size of the 
			strncpy_s(tmp, (b - a) + 1,_str.get_ptr() + a, b - a);

			BasicString res(tmp);
			return res;
		}

		void set(const char* s) {
			ustd::check_null_pointer(s);

			size = strlen(s);
			char* tmp = new char[size + 1] {0};
			strcpy_s(tmp, size + 1, s);
			_str.reallocate(tmp);

		}

		void operator=(const char* s) {
			set(s);
		}

		char get(index i) const {
			if (i > size) {
				throw out_of_range_exception;
			}
			return *(_str.get_ptr() + i);
		}
		
		char& operator[](int i) {
			return *(_str.get_ptr()+i);
		}

		const char* c_str() const {
			return _str.get_ptr();
		}

		//no need for a destructer thanks to SP;

		/*
		en redefini des fonction sur les string de type c (avec un \0 à la fin)
		*/
		
	};
	using String = BasicString;
	
	bool operator==(BasicString a, BasicString b) {
		return strcmp(a.c_str(), b.c_str()) == 0;
	}

	bool operator!=(BasicString a, BasicString b) {
		return !(a == b);
	}
};




#endif // !__USTD_STRING_H__
