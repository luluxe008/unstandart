#ifndef __USTD_STRING_H__
#define __USTD_STRING_H__

/*
	i used _CRT_SECURE_NO_WARNINGS to disable warning on Windows about the strcat and strcpy
*/

#include "memory.hpp"
#include <cstring>

namespace ustd {

	typedef unsigned long long int index;

	
	class BasicString { // I called it BasicString because why not (in reality there migth be other string with another type than char)
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
			_str.reallocate(new char[1]{0}); // else there can be a null pointer reading
		}

		BasicString(const char* s) {
			ustd::check_null_pointer(s);


			size = strlen(s);

			char* tmp = new char[size + 1] {0}; //size+1 for the \0
			strcpy(tmp, s);
			_str.reallocate((char*)tmp);
		}

		

		BasicString(const BasicString& s){ // copy, no ref
			size = s.size;
			char* tmp = new char[size + 1] {0};
			strcpy(tmp, s.c_str());
			_str.reallocate((char*)tmp);
		}

		

		void append(const char* s) {
			ustd::check_null_pointer(s);

			size += strlen(s);
			char* tmp = new char[size + 1] {0};
			strcat(tmp, _str.get_ptr());
			strcat(tmp, s);
			_str.reallocate(tmp);
		}

		void append(const BasicString& s) {
			append(s.c_str());
		}

		void append(const char& c) {
			
			char* tmp = new char[size+1] {0};
			strcpy(tmp, _str.get_ptr());
			tmp[size] = c;
			_str.reallocate(tmp);
			size++;
		}

		void operator+=(const char* s) {
			append(s);
		}

		void operator+=(const BasicString& s) {
			append(s);
		}

		void operator+=(const BasicString& c) {
			append(c);
		}
		
		BasicString slice(index a, index b) const{
			if (b < a) {
				throw bad_index_exception; // b must  be bigger than a
			}
			if (a > size || b > size) {
				throw out_of_range_exception; // too big
			}
			char* tmp = new char[(b - a) + 1] {0};// the size of the 
			strncpy(tmp,_str.get_ptr() + a, b - a);

			BasicString res(tmp);
			return res;
		}

		void set(const char* s) {
			ustd::check_null_pointer(s);

			size = strlen(s);
			char* tmp = new char[size + 1] {0};
			strcpy(tmp, s);
			_str.reallocate(tmp);

		}

		void operator=(const char* s) {
			set(s);
		}

		void operator=(const ustd::BasicString& s) {
			set(s.c_str());
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

	bool operator==(BasicString a, const char* s) {
		return strcmp(a.c_str(), s) == 0;
	}
	bool operator!=(BasicString a, const char* s) {
		return !(a == s);
	}

	ustd::BasicString operator+(const ustd::BasicString& a, const ustd::BasicString & b) {
		ustd::BasicString c(a);
		c.append(b);
		return c;
	}

	ustd::BasicString operator+(const ustd::BasicString& a, const char* s) {
		ustd::BasicString c(a);
		c.append(s);
		return c;
	}

	long long int str_to_lli(const char* s, bool plus_sign=true) {
		/*
		parse the s string to an long long int
		If plus_sign then if s[0] == '+' no error otherwise error
		*/
		short sign = 1;
		long long int res = 0;
		size_t i = 1;

		if (s[0] == '-') {
			sign = -1;
			i++;
		}
		else if (plus_sign && s[0] == '+') {
			i++; // no need to change sign because it's already positive
		}
		
		while (s[i] != '\0') {
			if (s[i] >= '0' && s[i] <= '9') {
				res = res * 10 + (s[i] - '0');
			}
			else {
				throw convert_exception;
			}
			i++;
		}

		return res * sign;

	}

	long long int str_to_lli(const BasicString& s) {
		return str_to_lli(s.c_str());
	}

};


#endif // !__USTD_STRING_H__
