#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

namespace Coastal {

	class VertexArray
	{
	public:
		VertexArray();
	public:
		inline void Bind() const { CSTL_GLCALL(glBindVertexArray(m_RendererId)); }
		inline void UnBind() const { CSTL_GLCALL(glBindVertexArray(0)); }
		inline uint32_t GetRendererId() const { return m_RendererId; }
		void AddBuffer(const Coastal::VertexBuffer& vbo, const Coastal::VertexBufferLayout& layout);
	private:
		uint32_t m_RendererId = 0;
	};

}