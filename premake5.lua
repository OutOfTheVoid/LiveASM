-- premake5.lua

workspace "BasicCodeGen"
	configurations { "Debug", "Release" }
	
project "BasicCodeGen"
	
	kind "ConsoleApp"
	
	language "C++"
	
	files { "**.h", "**.cpp" }
	
	includedirs "include"
	
	filter { "not system:windows" }
		toolset "clang"
		buildoptions { "-std=c++11 -Wall -Wextra -pedantic-errors" }
		
	filter { "action:vs*" }
		buildoptions { "/std:c++11" }
		
	filter {}
		
	filter { "configurations:Debug" }
		defines { "DEBUG" }
		symbols "On"
		
	filter { "configurations:Release" }
		defines { "RELEASE" }
		optimize "On"
