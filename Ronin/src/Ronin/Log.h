#pragma once

#include <memory.h>
#include "Core.h"
#include "spdlog/spdlog.h"

namespace Ronin {

	class RONIN_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}


// Core log macros
#define RN_CORE_TRACE(...)		::Ronin::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define RN_CORE_INFO(...)		::Ronin::Log::GetCoreLogger()->info(__VA_ARGS__)
#define RN_CORE_WARN(...)		::Ronin::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define RN_CORE_ERROR(...)		::Ronin::Log::GetCoreLogger()->error(__VA_ARGS__)
#define RN_CORE_FATAL(...)		::Ronin::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define RN_TRACE(...)			::Ronin::Log::GetClientLogger()->trace(__VA_ARGS__)
#define RN_INFO(...)			::Ronin::Log::GetClientLogger()->info(__VA_ARGS__)
#define RN_WARN(...)			::Ronin::Log::GetClientLogger()->warn(__VA_ARGS__)
#define RN_ERROR(...)			::Ronin::Log::GetClientLogger()->error(__VA_ARGS__)
#define RN_FATAL(...)			::Ronin::Log::GetClientLogger()->fatal(__VA_ARGS__)
