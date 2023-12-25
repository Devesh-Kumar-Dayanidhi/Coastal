#pragma once

#include "../coastal/Application.h"

class ExampleLayer : public Coastal::Application
{
public:
	void Start() override
	{
		m_CoastalRenderer = Coastal::Renderer(true);
		Coastal::DrawQuad(1.0f, 1.0f, 0.0f, 0.0f, Coastal::Rgba(0.0f, 1.0f, 1.0f, 1.0f), m_CoastalRenderer);
	}

	void OnUpdate() override
	{
		m_CoastalRenderer.Render();
	}
private:

};