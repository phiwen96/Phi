#include <iostream>
#include <stdlib.h>
#include <string>
// #include <cstdlib>

auto main (int argc, char** argv) -> int {
	// std::cout << PHI_MODULE_PATH << std::endl;
	// return 0;
	if (argc < 2) {
		std::cout << "error >> must specify path to target C++ file" << std::endl;
		return 0;
	}
	auto build_target = std::string {argv [1]};
	auto compiler = std::string {"gcc"};
	auto flags = std::string {" -std=gnu++23 -fmodules-ts -fcompare-debug-second -O2 -fno-trapping-math -fno-math-errno -fno-signed-zeros "};
	auto console_command = compiler + flags + std::string {"-o "} + build_target + std::string {" "} + std::string {PHI_MODULE_PATH};
	// std::system (console_command.c_str ());
	// std::cout << "yo" << std::endl;
	return 0;
}