#include <string>
#include <iostream>
#include <vector>
#include <sstream>

template <typename T, bool ExitIfFailed=false>
class assert {
	const T& value;
	std::string name;
	std::vector<std::string> fails;
public:
	assert(std::string name, const T& expr) : name(name), value(expr), fails(){
		
	}
	
	
	assert<T, ExitIfFailed>& HasSameAddressAs(const void* other) {
		if (!(other == &value)) {

			std::ostringstream oss;
			oss << other << " has a different adress than " << &value;
			fails.push_back(oss.str());
		}
		return *this;
	}

	assert<T, ExitIfFailed>& HasDifferentAddressAs(const void* other) {
		if (!(other != &value)) {

			std::ostringstream oss;
			oss << other << " has the same adress as " << &value;
			fails.push_back(oss.str());
		}
		return *this;
	}

	template <typename C>
	assert<T, ExitIfFailed>& IsEqualTo(C other) {
		if (!(other == value)) {
			std::ostringstream oss;
			oss << value << " is not equal to " << other;
			fails.push_back(oss.str());
		}

		return *this;
	}

	template <typename C>
	assert<T, ExitIfFailed>& IsDifferentFrom(C other) {
		if (!(other != value)) {
			std::ostringstream oss;
			oss << value << " is not different from " << other;
			fails.push_back(oss.str());
		}
		return *this;
	}

	template <typename C>
	assert<T, ExitIfFailed>& IsGreaterThan(C other) {
		if (!(value > other)) {
			std::ostringstream oss;
			oss << value << " is not greater than " << other;
			fails.push_back(oss.str());
		}
		return *this;
	}

	template <typename C>
	assert<T, ExitIfFailed>& IsGreaterThanOrEqualTo(C other) {
		if (!(value >= other)) {
			std::ostringstream oss;
			oss << value << " is not greater than or equal to " << other;
			fails.push_back(oss.str());
		}
		return *this;
	}

	template <typename C>
	assert<T, ExitIfFailed>& IsLessThan(C other) {
		if (!(value < other)) {
			std::ostringstream oss;
			oss << value << " is not less than " << other;
			fails.push_back(oss.str());
		}
		return *this;
	}

	template <typename C>
	assert<T, ExitIfFailed>& IsLessThanOrEqualTo(C other) {
		if (!(value <= other)) {
			std::ostringstream oss;
			oss << value << " is not less than or equal to " << other;
			fails.push_back(oss.str());
		}
		return *this;
	}

	bool ShowResult() {
		if (fails.size() == 0) {
			std::cout << "[" << name << "] SUCESS" << std::endl;
			return true;
		}

		std::cout << "[" << name << "] FAILED" << std::endl;

		for (auto fail : fails) {
			std::cout << "\t" << fail << std::endl;
		}
		if (ExitIfFailed) {
			throw "assert failed";
		}
		return false;
	}
};

