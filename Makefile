CXX = clang++
# --verbose
############### C++ compiler flags ###################
CXX_FLAGS = -D DEBUG -std=gnu++23 -fmodules-ts -fcompare-debug-second -O2 -fno-trapping-math -fno-math-errno -fno-signed-zeros # -Wno-attributes -fconcepts-diagnostics-depth=2
CXX_MODULES = -fmodules-ts -fmodules -fbuiltin-module-map -fimplicit-modules -fimplicit-module-maps -fprebuilt-module-path=.

CXX_APP_FLAGS = -lpthread 

USE_GLFW := FALSE
USE_VULKAN := FALSE
USE_BOOST := FALSE
USE_OPENSSL := FALSE
USE_NLOHMANN := FALSE

ifeq ($(OS),Windows_NT) 
    detected_OS := Windows
else
    detected_OS := $(shell sh -c 'uname 2>/dev/null || echo Unknown')
	# CXX_INCLUDES = -I/usr/local/include -I/opt/homebrew/Cellar/glm/0.9.9.8/include -I/opt/homebrew/Cellar/freetype/2.12.1/include/freetype2 #-I/Users/philipwenkel/VulkanSDK/1.3.216.0/macOS/include
endif
ifeq ($(detected_OS),Windows)
	GCC = g++
	CXX_FLAGS += -D WINDOWS
	VULKAN_DIR = C:\VulkanSDK\1.3.224.1
	CXX_LIBS = -L$(VULKAN_DIR)\Lib #-lvulkan
	CXX_INCLUDES += -I$(VULKAN_DIR)\Include
endif
ifeq ($(detected_OS),Darwin)
	
	ifeq ($(USE_GLFW), TRUE) 
		# $(info $$USE_GLFW is [${USE_GLFW}])
		CXX_LIBS += -L$(LIB_GLFW)/lib -lglfw 
		CXX_INCLUDES += -I$(LIB_GLFW)/include 
	endif
	ifeq ($(USE_VULKAN), TRUE)
		CXX_LIBS += -L$(VULKAN_SDK)/macOS/lib -lvulkan.1.3.236 
		CXX_INCLUDES += -I$(VULKAN_SDK)/macOS/include 
	endif
	ifeq ($(USE_BOOST), TRUE)
		CXX_LIBS += -L$(LIB_BOOST)/lib -lboost_system -lboost_url 
		CXX_INCLUDES += -I$(LIB_BOOST)/include 
	endif
	ifeq ($(USE_OPENSSL), TRUE)
		CXX_LIBS += -L$(LIB_OPENSSL)/lib -lssl -lcrypto
		CXX_INCLUDES += -I$(LIB_OPENSSL)/include
	endif
	ifeq ($(USE_NLOHMANN), TRUE)
		CXX_INCLUDES += -I$(LIB_NLOHMANN)/include
	endif
	
	VULKAN_VERSION = 1.3.236.0
	VULKAN_SDK = /Users/philipwenkel/VulkanSDK/$(VULKAN_VERSION)
	LIB_NLOHMANN := /opt/homebrew/Cellar/nlohmann-json/3.11.3
	LIB_OPENSSL := /opt/homebrew/Cellar/openssl@3/3.2.0_1
	LIB_BOOST := /opt/homebrew/Cellar/boost/1.83.0
	LIB_GLFW := /opt/homebrew/Cellar/glfw/3.3.9
	GLSLC_COMPILER = $(VULKAN_SDK)/macOS/bin/glslc
	GCC = /opt/homebrew/Cellar/gcc/13.2.0/bin/g++-13
	CXX_FLAGS += -D MACOS #-D FONTS_DIR=\"/System/Library/Fonts/Supplemental\"
	# CXX_LIBS = -L/opt/homebrew/lib
endif
ifeq ($(detected_OS),Linux)
	# LIB_OPENSSL := /usr/include/openssl
	GLSLC_COMPILER = /usr/bin/glslc
	GCC = /usr/bin/g++-12
	CXX_FLAGS += -D LINUX
	# CXX_LIBS += -lglfw 
    CXX_APP_FLAGS += -lrt
	CXX_LIBS = -lrt -lglfw -lvulkan -luring -lfreetype -lssl -lcrypto
	CXX_INCLUDES += -I/usr/include/freetype2 
endif

Phi: Phi.cpp
	$(GCC) $(CXX_FLAGS) -Werror=unused-result -o $@ $< $(CXX_LIBS) $(CXX_INCLUDES)