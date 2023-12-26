#pragma once

#include "../coastal/Application.h"

class ExampleLayer : public Coastal::Application
{
public:
	void Start() override
	{
		Coastal::LoadQuad(1.0f, 1.0f, 0.0f, 0.0f, Coastal::Rgba(1.0f, 1.0f, 0.0f, 1.0f), m_CoastalRenderer, m_CoastalManager);
	}

	void OnUpdate() override
	{
		m_CoastalRenderer.Render();
	}
private:

};