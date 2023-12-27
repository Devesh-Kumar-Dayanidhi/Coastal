#pragma once

#include "../coastal/Application.h"

class ExampleLayer : public Coastal::Application
{
public:
	void Start() override
	{
		m_X = -2.0f;
		Coastal::LoadQuad(1.0f, 1.0f, m_X, 0.0f, Coastal::Rgba(1.0f, 0.0f, 1.0f, 1.0f), m_CoastalRenderer, m_CoastalManager);
	}

	void OnUpdate() override
	{
		m_CoastalRenderer.EditObjectTransform(Coastal::Vector2(m_X, 0.0f), 10);

		m_X += 0.001f;

		if (m_X >= 4.0f)
			m_X = -2.0f;
	}
private:
	float m_X;
};