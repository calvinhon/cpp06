#include "Serializer.hpp"

int main() {
	Data		obj;
	Data* 		ptr = &obj;
	uintptr_t	raw;

	obj.inum = 42;
	obj.str = "ScalarConverter";
	std::cout << "Pre-serialize ptr: " << ptr << std::endl;
	raw = Serializer::serialize(ptr);
	std::cout << "Serialized / Raw: " << raw << std::endl;
	ptr = Serializer::deserialize(raw);
	std::cout << "De-serialize ptr: " << ptr
		<< "\ninum: " << obj.inum
		<< "\nstr: " << obj.str
		<< std::endl;
	return 0;
}