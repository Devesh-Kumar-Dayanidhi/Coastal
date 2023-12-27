#pragma once

#include "VertexArray.h"
#include "IndexBuffer.h"
#include "VertexBuffer.h"
#include "Shader.h"
#include "Rgba.h"

namespace Coastal {

	class Renderer
	{
	public:
		Renderer() = default;
	public:
		void AddVertexArray(const Coastal::VertexArray& vao);
		void AddShader(const Coastal::Rgba& color);
		void Render() const;
	private:
		Coastal::Shader m_Shader = Coastal::Shader("C:\\Users\\Devesh\\Programs\\C++\\Coastal\\Coastal\\Coastal\\src\\coastal\\res\\shaders\\Basic.shader");
		std::vector<Coastal::VertexArray> m_Vaos;
		std::vector<Coastal::Rgba> m_Colors;
	};

}