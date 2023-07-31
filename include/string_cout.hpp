#ifndef __USTD_STRCOUT_H__
#define __USTD_STRCOUT_H__
#include "string.hpp"
#include "ostream.hpp"

ustd::Ostream& operator<<(ustd::Ostream& f, ustd::String str) {
	f << str.c_str();
	return f;
}

#endif // !#define __USTD_STRCOUT_H__