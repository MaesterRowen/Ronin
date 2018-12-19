#pragma once

#ifdef RN_PLATFORM_WINDOWS

extern Ronin::Application* Ronin::CreateApplication();

int main(int argc, char** argv)
{
	int a = 5;
	Ronin::Log::Init();
	RN_CORE_WARN("Initialized Log");
	RN_INFO("Hello! Var={0}", a);

	auto app = Ronin::CreateApplication();
	app->Run();
	delete app;
}

#endif