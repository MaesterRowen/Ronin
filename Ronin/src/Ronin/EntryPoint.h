#pragma once

#ifdef RN_PLATFORM_WINDOWS

extern Ronin::Application* Ronin::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Ronin::CreateApplication();
	app->Run();
	delete app;
}

#endif