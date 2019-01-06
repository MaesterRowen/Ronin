#include <Ronin.h>

class ExampleLayer : public Ronin::Layer
{
public:
	ExampleLayer(const std::string& name)
		: Layer(name)
	{

	}

	void OnUpdate() override
	{
		RN_INFO("ExampleLayer::Update [{0}]", m_DebugName);
	}

	void OnEvent(Ronin::Event& event) override
	{
		RN_TRACE("{0}", event);
	}
};

class Sandbox : public Ronin::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer("Example"));
		PushLayer(new ExampleLayer("Other"));
	}

	~Sandbox()
	{

	}
};


Ronin::Application* Ronin::CreateApplication()
{
	return new Sandbox();
}