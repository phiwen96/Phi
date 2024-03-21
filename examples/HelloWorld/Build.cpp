#include <vector>
import Phi;


auto main (int argc, char** argv) -> int {

	auto lib = build_module {
		.name = "HelloWorld",
		.path = "MyApp.cpp"
	};

	auto app = build_app {
		.name = "MyApp",
		.path = "myapp.cpp",
		.modules = {lib}
	};

	return app.build ();
}