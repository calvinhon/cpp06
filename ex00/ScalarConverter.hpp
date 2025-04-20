#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <sstream>

enum NumType {
	INT_NUM = 1,
	FLT_NUM,
	DBL_NUM
};

struct Number {
	int		inum;
	float	fnum;
	double	dnum;
	NumType	num_type;
};

class ScalarConverter {
	public:
		static void convert(std::string& literal);
};

#endif