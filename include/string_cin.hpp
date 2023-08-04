#pragma once
#include "string.hpp"
#include "istream.hpp"

ustd::Istream& operator>>(ustd::Istream& f, ustd::BasicString& s) {
	char a = 0;
	while ((a = f.read_char()) != ' ' || a != '\n') {
		s.append(a);
	}
	return f;
}