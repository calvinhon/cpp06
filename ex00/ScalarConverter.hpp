#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

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

class ScalarConverter {
	public:
		static void convert(std::string& literal);
	
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& src);
		ScalarConverter& operator=(const ScalarConverter& src);
		~ScalarConverter();
};

#endif