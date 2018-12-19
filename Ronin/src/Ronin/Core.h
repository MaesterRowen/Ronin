#pragma once

#ifdef RN_PLATFORM_WINDOWS
	#ifdef RN_BUILD_DLL
		#define RONIN_API __declspec(dllexport)
	#else
		#define RONIN_API __declspec(dllimport)
	#endif
#else
#error Ronin only supports Windows!
#endif