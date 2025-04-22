#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>

class Base {
	public:
		virtual ~Base();

		static Base* generate(void);
		static void identify(Base* p);
		static void identify(Base& p);

		class CastFailed: public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

class A: public Base {};
class B: public Base {};
class C: public Base {};

#endif