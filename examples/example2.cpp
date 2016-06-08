#include <stdio.h>
#include <stddef.h>

#include <iostream>

#include <fnv/fnv.h>


std::string
read_from_file(const std::string& fname)
{
	char buff[4096]{0};
	FILE* f = fopen(fname.c_str(), "rb");
	size_t length = fread(buff, 1, 4096, f);
	fclose(f);

	return std::string(buff, length);
}


int
main()
{
	auto data1 = read_from_file("header.txt");
	auto data2 = read_from_file("data.txt");
	std::cout << net::QuicUtils::FNV1a_128_Hash_Two(
			data1.c_str(), data1.size(),
			data2.c_str(), data2.size())
		<< '\n';
	return 0;
}
