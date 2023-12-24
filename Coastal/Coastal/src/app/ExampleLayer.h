#pragma once

#include "../coastal/Application.h"

class ExampleLayer : public Coastal::Application
{
public:
	void Start() override
	{
		rectX = -2.0f;
	}

	void OnUpdate() override
	{
		Coastal::DrawQuad(1.0f, 1.0f, rectX, 0.0f, Coastal::Rgba(0.0f, 1.0f, 1.0f, 1.0f));

		rectX += 0.01f;

		if (rectX >= 2.0f)
			rectX = -2.0f;
	}
private:
	float rectX;
};