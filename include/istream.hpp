#ifndef __USTD_ISTREAM_H__
#define __USTD_ISTREAM_H__

#define MAX_STRING 255

#include <cstdio>
#include <istream>

#error UNFINISHED

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
		
	};
}
/*
	I HAVE NO IDEA WHAT I AM DOING
	MAY RE DO EVERYTHING HERE
*/
#endif // !__USTD_ISTREAM_H__
