module;
#include <string>
#include <vector>
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
		return 0;
	}
};