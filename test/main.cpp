
#include "throw.hpp"
#include <iostream>

#define CHECK_FLAG(flag) \
	std::cout << #flag " is" << (flag ? "" : "NOT") << " set - test " << (flag ? "PASSED" : "FAILED") << std::endl; \
	if ( !flag ) return 1;

struct usertype {
	usertype()
		:a(55)
		,b(66)
	{}

	friend std::ostream& operator<< (std::ostream &os, const usertype &u) {
		return os << '{' << u.a << ',' << u.b << '}';
	}
	int a, b;
};

int main() {
	std::cout << TEST_FORMAT_MESSAGE("message: %1%, %2%, %3%", "string1", 33, "string2") << std::endl;
	const std::string str = TEST_FORMAT_MESSAGE_AS_STRING("message: %1%, %2%, %3%", "string3", 44, "string4");
	std::cout << str << std::endl;

	usertype u;
	std::cout << TEST_FORMAT_MESSAGE("message: %1%, %2%, %3%, %4%", "string1", 33, "string2", u) << std::endl;

	TEST_TRY(flag1)
		throw "message from exception 1";
	TEST_CATCH(flag1)
	CHECK_FLAG(flag1)

	TEST_TRY(flag2)
		TEST_TYPED_THROW(std::logic_error, "message from exception 2");
	TEST_CATCH(flag2)
	CHECK_FLAG(flag2)

	TEST_TRY(flag3)
		throw std::runtime_error("message from exception 3");
	TEST_CATCH_LOG(flag3, std::cout)
	CHECK_FLAG(flag3)
}
