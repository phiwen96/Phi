#include <iostream>
#include <stdlib.h>
#include <string>
// #include <cstdlib>

#include <string>

auto basename (const std::string &filename) -> std::string;
auto remove_extension (const std::string& filename) -> std::string;

auto main (int argc, char** argv) -> int {
	// std::cout << PHI_MODULE_PATH << std::endl;
	// return 0;
	if (argc < 2) {
		std::cout << "error >> must specify path to target C++ file" << std::endl;
		return 0;
	}
	
	auto build_target = std::string {argv [1]};
	auto build_dst = std::string {BUILDS_DIR} + std::string {"/"} + remove_extension (basename (build_target));
	auto compiler = std::string {COMPILER_PATH};
	auto flags = std::string {" -D DEBUG -std=gnu++23 -fmodules-ts -fcompare-debug-second -O2 -fno-trapping-math -fno-math-errno -fno-signed-zeros"};
	auto console_command = compiler + flags + std::string {" -o "} + build_dst + std::string {" "} + build_target + std::string {" "} + std::string {PHI_MODULE_PATH};
	std::cout << "compiling build >> " << console_command << std::endl << std::endl;
	// return 0;
	std::system (console_command.c_str ());
	std::cout << "executing build" << std::endl;
	console_command = build_dst;
	std::system (console_command.c_str ());
	// std::cout << "yo" << std::endl;
	return 0;
}

auto basename (const std::string &filename) -> std::string {
    if (filename.empty()) {
        return {};
    }

    auto len = filename.length();
    auto index = filename.find_last_of("/\\");

    if (index == std::string::npos) {
        return filename;
    }

    if (index + 1 >= len) {

        len--;
        index = filename.substr(0, len).find_last_of("/\\");

        if (len == 0) {
            return filename;
        }

        if (index == 0) {
            return filename.substr(1, len - 1);
        }

        if (index == std::string::npos) {
            return filename.substr(0, len);
        }

        return filename.substr(index + 1, len - index - 1);
    }

    return filename.substr(index + 1, len - index);
}

auto remove_extension (const std::string& filename) -> std::string {
    size_t lastdot = filename.find_last_of(".");
    if (lastdot == std::string::npos) return filename;
    return filename.substr(0, lastdot); 
}