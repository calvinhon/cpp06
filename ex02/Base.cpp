#include "Base.hpp"

Base::~Base() {}

Base* Base::generate(void) {
	srand(time(0));
	int randClass = rand() % 3;
	if (!randClass)
		return new A();
	else if (randClass == 1)
		return new B();
	else
		return new C();
}

void Base::identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl; 
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl; 
	else if (dynamic_cast<C*>(p) == NULL)
		std::cout << "Return is NULL" << std::endl; 
}

void Base::identify(Base& p) {
	try {
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
		return ; 
	} catch (const std::exception& e) {}
	try {
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B" << std::endl; 
		return ;
	} catch (const std::exception& e) {}
	try {
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C" << std::endl;
		return ;
	} catch (const std::exception& e) {
		throw Base::CastFailed();
	}
}

const char* Base::CastFailed::what() const throw() {
	return "Exception caught: cast failed!";
}

