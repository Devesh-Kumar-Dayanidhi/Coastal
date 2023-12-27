#pragma once

namespace Coastal {

	class Vector3
	{
	public:
		Vector3() = default;
		Vector3(float x, float y, float z) :
			X(x), Y(y), Z(z) {}
	public:
		float X = 0.0f, Y = 0.0f, Z = 0.0f;
	};

}