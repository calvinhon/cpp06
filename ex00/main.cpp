#include "ScalarConverter.hpp"

int	main(int ac, char** av) {
	if (ac != 2) {
		std::cout << "Input only 1 argument" << std::endl;
		return 1;
	}
	std::string input(av[1]);
	ScalarConverter::convert(input);
	return 0;
}