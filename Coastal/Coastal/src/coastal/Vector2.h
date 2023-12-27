#pragma once

namespace Coastal {

	class Vector2 
	{
	public:
		Vector2() = default;
		Vector2(float x, float y) :
			X(x), Y(y) {}
	public:
		float X = 0.0f, Y = 0.0f;
	};

}