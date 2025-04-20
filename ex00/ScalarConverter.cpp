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

void isNum(const std::string& literal, Number* n) {
	std::stringstream ss(literal);

	ss >> n->inum;
	if (ss.eof() && !ss.fail()) {
		n->num_type = INT_NUM;
	}
	ss.clear(); ss.str(literal);
	ss >> n->fnum;
	if (ss.eof() && !ss.fail()) {
		n->num_type = FLT_NUM;
	}
	ss.clear(); ss.str(literal);
	ss >> n->dnum;
	if (ss.eof() && !ss.fail()) {
		n->num_type = DBL_NUM;
	}
}

void ScalarConverter::convert(std::string& literal) {
	int	i = isPseudo(literal);
	Number* n = new Number();
	isNum(literal, n);
	if (i != -1) {
		std::cout << "char: impossible\nint: impossible\n";
		if (i < 6)
			std::cout << "float: " << pseudoLiterals[i + 6] << "\ndouble: " << literal;
		else
			std::cout << "float: " << literal << "\ndouble: " << pseudoLiterals[i - 6];
	}
	else if (n->num_type) {
		if (!std::isprint(literal[0]))
			std::cout << "char: Non displayable\n";
		// else if (n == 1 && )

	}
		// else if (literal.length() == 1 && std::isalpha(literal[0]))
	std::cout << std::endl;
	delete n;
}
