import Phi;

auto main (int argc, char** argv) -> int {

	auto lib = build_module {
		.name = "MyApp",
		.path = "MyApp.cpp"
	};

	auto app = build_app {
		.name = "MyApp",
		.path = "myapp.cpp"
		// .modules = {lib}
	};

	// return app.build ();
	return 0;
}