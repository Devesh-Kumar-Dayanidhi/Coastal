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
		inline size_t GetSceneSize() const { return m_Vaos.size(); }
	public:
		void AddVertexArray(const Coastal::VertexArray& vao);
		void AddColor(const Coastal::Rgba& color);
		void AddTransform(const Coastal::Vector2& position);
		void EditObjectTransform(const Coastal::Vector2& transform, size_t objectIndex);
		void EditObjectColor(const Coastal::Rgba& color, size_t objectIndex);
		void Render() const;
	private:
		Coastal::Shader m_Shader = Coastal::Shader("C:\\Users\\Devesh\\Programs\\C++\\Coastal\\Coastal\\Coastal\\src\\coastal\\res\\shaders\\Basic.shader");
		std::vector<Coastal::VertexArray> m_Vaos;
		std::vector<Coastal::Rgba> m_Colors;
		std::vector<Coastal::Vector2> m_Transforms;
	};

}