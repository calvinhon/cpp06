#include "ScalarConverter.hpp"

std::string pseudoLiterals[] = {
	"nan", "+nan", "-nan", "inf", "+inf", "-inf",
	"nanf", "+nanf", "-nanf", "inff", "+inff", "-inff"
};

int isPseudo(const std::string& literal) {
	for (int i = 0; i < 12; ++i)
		if (literal == pseudoLiterals[i])
			return i;
	return -1;
}

bool isNum(const std::string& literal, Number* n) {
	std::stringstream	ss(literal);
	std::string			trimmed;

	ss >> n->inum;
	if (ss.eof() && !ss.fail()) {
		n->fnum = static_cast<float>(n->inum);
		n->dnum = static_cast<double>(n->inum);
		return 1;
	}
	if (literal[literal.length() - 1] == 'f') {
		trimmed = literal.substr(0, literal.length() - 1);
		ss.clear(); ss.str(trimmed);
		ss >> n->fnum;
		if (ss.eof() && !ss.fail()) {
			n->inum = static_cast<int>(n->fnum);
			n->dnum = static_cast<double>(n->fnum);
			return 1;
		}
	}
	ss.clear(); ss.str(literal);
	ss >> n->dnum;
	if (ss.eof() && !ss.fail()) {
		n->inum = static_cast<int>(n->dnum);
		n->fnum = static_cast<float>(n->dnum);
		return 1;
	}
	return 0;
}

void ScalarConverter::convert(std::string& literal) {
	int	i = isPseudo(literal);
	Number* n = new Number();
	std::cout << std::fixed << std::setprecision(1);
	if (i != -1) {
		std::cout << "char: impossible\nint: impossible\n";
		if (i < 6)
			std::cout << "float: " << pseudoLiterals[i + 6] << "\ndouble: " << literal << std::endl;
		else
			std::cout << "float: " << literal << "\ndouble: " << pseudoLiterals[i - 6] << std::endl;
	}
	else if (literal.length() == 1 && !isdigit(literal[0])) {
		std::cout << "char: \'" << static_cast<char>(literal[0])
		<< "\'\nint: " << static_cast<int>(literal[0])
		<< "\nfloat: " << static_cast<float>(literal[0])
		<< "f\ndouble: " << static_cast<double>(literal[0]) << std::endl;
	}
	else if (isNum(literal, n)) {
		if (n->dnum < 0 || n->dnum > 127)
			std::cout << "char: impossible\n";
		else if (!std::isprint(atoi(literal.c_str())))
			std::cout << "char: Non displayable\n";
		else
			std::cout << "char: \'" << static_cast<char>(n->inum) << "\'\n";
		std::cout << "int: ";
		if (n->dnum < std::numeric_limits<int>::min() || n->dnum > std::numeric_limits<int>::max())
			std::cout << "impossible";
		else
			std::cout << n->inum;
		std::cout << "\nfloat: ";
		if (n->dnum < std::numeric_limits<float>::lowest() || n->dnum > std::numeric_limits<float>::max())
			std::cout << "impossible";
		else
			std::cout << n->fnum << "f";
		std::cout << "\ndouble: ";
		if (n->dnum < std::numeric_limits<double>::lowest() || n->dnum > std::numeric_limits<double>::max())
			std::cout << "impossible" << std::endl;
		else
			std::cout << n->dnum << std::endl;
	}
	else
		std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible" << std::endl;
	delete n;
}
