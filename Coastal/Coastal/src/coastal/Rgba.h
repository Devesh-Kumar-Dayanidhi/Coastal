#pragma once

namespace Coastal {

	class Rgba
	{
	public:
		Rgba() = default;
		Rgba(float r, float g, float b, float a) :
			R(r), G(g), B(b), A(a) {}
	public:
		float R = 0.0f, G = 0.0f, B = 0.0f, A = 0.0f;
	};

}