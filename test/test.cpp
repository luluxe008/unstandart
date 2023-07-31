#include <iostream>
#include "../include/memory.hpp"
#include "../include/string.hpp"
#include "../include/array.hpp"
#include "assertion.hpp"

#include <ostream>

std::ostream& operator<<(std::ostream& f, ustd::String) { return f; } // only to do the assertion with ustd::string, without that code don't compile

void memory_test() {
	class A {
	public:
		void my_func() {

		}
	};

	{
		ustd::SP<long long> a = 5843544;
		assert<long long>("value equality", *a).IsEqualTo(5843544).ShowResult();
	}

	{
		ustd::SP<long long> a = 2465541;
		{
			ustd::SP<long long> b=a;
		}
		assert<long long>("value alteration validation", *a).IsEqualTo(2465541).ShowResult();
	}

	{
		ustd::SP<long long> a;
		assert<bool>("is null before being inited", a.is_null()).IsEqualTo(true).ShowResult();
	}

	{
		ustd::SP<A> a = A();
		ustd::SP<A> b = a;
		assert<A>("address equality", *a.get_ptr()).HasSameAddressAs(b.get_ptr()).ShowResult();
	}

	{
		ustd::SP<int> a = 25;
		ustd::SP<int> b(a);
		a.reallocate(32); // realocate memory to now hold 32
		assert<int>("address change due to reallocation", *a.get_ptr()).HasDifferentAddressAs(b.get_ptr()).ShowResult();
		
	}
}

void string_test() {
	{
		ustd::BasicString a("hello");
		ustd::BasicString b(a);
		assert<ustd::BasicString>("string equality after copy", a).IsEqualTo(b).ShowResult();
	}

	{
		ustd::BasicString a("hello");
		ustd::BasicString b = "hello";
		assert<ustd::BasicString>("string equality", a).IsEqualTo(b).ShowResult();
	}

	{
		ustd::BasicString a("no");
		ustd::BasicString b("yes");
		assert<ustd::BasicString>("string difference", a).IsDifferentFrom(b).ShowResult();
	}
} 

void array_test() {
	// lazy to write all the tests but it looks like it work

}

int main() {
	//memory_test();
	
	string_test();

	array_test();
}