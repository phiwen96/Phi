# Phi
 Phi is a build automation tool that builds executable programs and modules for C++

# How to compile this build tool

```console
foo@bar:~$ make
```

# C++ Example

```cpp
// Build.cpp

import Phi;

auto main (int argc, char** argv) -> int {

	auto lib = build_module {
		.name = "MyApp",
		.path = "MyApp.cpp"
	};

	auto app = build_app {
		.name = "MyApp",
		.path = "myapp.cpp"
		.modules = lib
	};

	return app.build ();
}
```

```cpp
// myapp.cpp

import MyApp;

auto main (int argc, char** argv) -> int {
	auto app = myApp {};
	return app.run ();
}
```

```cpp
// MyApp.cpp
module;
#include <stdio.h>
export module MyApp;

export struct myApp {
	auto run () -> int {
		printf ("Hello World\n";)
		return 0;
	}
};
```

# How to compile your app with Phi

```console
foo@bar:~$ phi Build.cpp
```