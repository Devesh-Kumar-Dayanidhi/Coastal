#pragma once

#pragma once

#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

#include "pch.h"

namespace Coastal {

	class VertexArray
	{
	public:
		VertexArray();
		~VertexArray();
	public:
		inline void Bind() const { CSTL_GLCALL(glBindVertexArray(m_RendererId)); }
		inline void UnBind() const { CSTL_GLCALL(glBindVertexArray(0)); }
		void AddBuffer(const VertexBuffer& vbo, const VertexBufferLayout& layout);
	private:
		uint32_t m_RendererId;
	};

}