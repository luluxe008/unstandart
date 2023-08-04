#include "../include/memory.hpp"
#include "assertion.hpp"
#include "../include/vector.hpp"
#include "../include/array.hpp";
#include "../include/ostream.hpp"
//#include "../include/istream.hpp"

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

	// for some raison the tests won't compile so I will do it later
} 

void array_test() {
	// lazy to write all the tests but it looks like it work

}

int main() {
	//memory_test();


	//string_test();

	//array_test();
	ustd::Ostream cout;
	char a, b, c;
	
}
