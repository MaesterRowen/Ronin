
workspace "Ronin"
	architecture "x64"
	startproject "Sandbox"
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Ronin/vendor/GLFW/include"

include "Ronin/vendor/GLFW"

project "Ronin"
	location "Ronin"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "rnpch.h"
	pchsource "Ronin/src/rnpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"RN_PLATFORM_WINDOWS",
			"RN_BUILD_DLL",
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "RN_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "RN_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "RN_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Ronin/vendor/spdlog/include",
		"Ronin/src"
	}

	links
	{
		"Ronin"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"RN_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "RN_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "RN_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "RN_DIST"
		optimize "On"