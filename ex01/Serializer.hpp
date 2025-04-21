#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <sstream>
#include <iomanip>
#include <limits>

struct Number {
	int		inum;
	float	fnum;
	double	dnum;
};

class Serializer {
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
	
	private:
		Serializer();
		Serializer(const Serializer& src);
		Serializer& operator=(const Serializer& src);
		~Serializer();
};

#endif