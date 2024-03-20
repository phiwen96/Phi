# Phi
 Phi is a build automation tool that builds executable programs and modules for C++

# C++ Example

```cpp
import Phi;

auto main (int argc, char** argv) -> int {

	auto lib = build_module {
		.name = "My app module"
	};

	auto app = build_app {
		.name = "My app",
		.modules = lib
	};

	app.build (argc, argv);

	return 0;
}
```