module;
#include <stdio.h>
export module HelloWorld;

export struct hello_world {
	auto print () -> void {
		printf ("Hello World\n";)
	}
};