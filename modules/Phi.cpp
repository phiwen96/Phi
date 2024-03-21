module;
#include <stdlib.h>
#include <string>
#include <vector>
#include <iostream>
export module Phi;

export struct build_module {
	std::string name;
	std::string path;
	std::vector <build_module> modules;
};

export struct build_app {
	std::string name;
	std::string path;
	std::vector <build_module> modules;

	auto build () -> int {
		auto command = std::string {COMPILER_PATH} + std::string {" "} + std::string {CXX_FLAGS} + std::string {" -o "} + build_dst + std::string {" "} + build_target + std::string {" "} + std::string {PHI_MODULE_PATH};;
		// std::system ()
		return 0;
	}
};