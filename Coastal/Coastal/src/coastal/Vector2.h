#pragma once

namespace Coastal {

	class Vector2 
	{
	public:
		Vector2() = default;
		Vector2(float x, float y) :
			x(x), y(y) {}
	public:
		float x = 0.0f, y = 0.0f;
	};

}