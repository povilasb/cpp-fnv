#include <iostream>

#include <fnv/fnv.h>

int
main()
{
	char data[] = "\x13\xA5";
	std::cout << net::QuicUtils::FNV1a_128_Hash(data, sizeof(data) - 1) << '\n';
	return 0;
}
