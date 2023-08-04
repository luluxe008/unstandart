#ifndef __USTD_ISTREAM_H__
#define __USTD_ISTREAM_H__

#define MAX_STRING 255

#include <cstdio>
#include <istream>


namespace ustd {
	class Istream {
		FILE* _file;
	public:
		Istream() : _file(stdin) {

		}
		Istream(FILE* file) : _file(file) {

		}
		Istream(const Istream& o) {
			_file = o._file;
		}
		char read_char() {
			return (char)fgetc(_file);
		}
		Istream& operator>>(char& c) {
			/*
			we skip the \n
			*/
			fscanf(_file, "%c", &c);
			if (c == '\n') fscanf(_file, "%c", &c);

			return *this;
		}
		Istream& operator>>(int& a) {
			fscanf(_file, "%d", &a);

			return *this;
		}
		Istream& operator>>(unsigned int& a) {
			fscanf(_file, "%u", &a);

			return *this;
		}
		Istream& operator>>( short& a) {
			fscanf(_file, "%hi", &a);

			return *this;
		}
		Istream& operator>>(unsigned short& a) {
			fscanf(_file, "%hu", &a);

			return *this;
		}
		Istream& operator>>(float& a) {
			fscanf(_file, "%f", &a);

			return *this;
		}
		Istream& operator>>(double& a) {
			fscanf(_file, "%lf", &a);

			return *this;
		}
		Istream& operator>>(long double& a) {
			fscanf(_file, "%Lf", &a);

			return *this;
		}
		void read_string(char* s, size_t size) {
			fread(s, sizeof(char), size, _file);
		}
	};
}
/*
	I HAVE NO IDEA WHAT I AM DOING
	MAY RE DO EVERYTHING HERE
*/
#endif // !__USTD_ISTREAM_H__
