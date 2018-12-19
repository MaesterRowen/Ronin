#include <Ronin.h>

class Sandbox : public Ronin::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};


Ronin::Application* Ronin::CreateApplication()
{
	return new Sandbox();
}