#include "Base.hpp"

int main() {
	Base* ptr = Base::generate();
	Base::identify(ptr);
	delete ptr;

	try {
		Base* ref = Base::generate();
		Base::identify(*ref);
		delete ref;
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Base ref;
		Base::identify(ref);
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}