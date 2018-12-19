#pragma once
#include "Core.h"

namespace Ronin {
	class RONIN_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};


	Application* CreateApplication();
}