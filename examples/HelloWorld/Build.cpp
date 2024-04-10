// #include <string>
#include <vector>
import Phi;


auto main (int argc, char** argv) -> int {

	auto lib = build_module {
		.name = "HelloWorld",
		.srcDir = "modules",
		.dstDir = "build/modules"
	};

	// auto app = build_app {
	// 	.name = "HelloWorld",
	// 	.srcDir = "apps",
	// 	.dstDir = "build/apps",
	// 	.modules = {lib}
	// };

	// return app.build ();
	return 0;
}