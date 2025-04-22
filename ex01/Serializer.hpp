#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <string>
#include <iostream>
#include <stdint.h>

struct Data {
	int			inum;
	std::string str;
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