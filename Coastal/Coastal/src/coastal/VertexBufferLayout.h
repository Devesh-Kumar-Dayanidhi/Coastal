#pragma once

#include <vector>
#include <stdint.h>

#include "pch.h"
#include "ErrorHandling.h"

namespace Coastal {

	struct VertexBufferElementLayout
	{
		uint32_t type, count, normalized;

		static unsigned int GetSizeOfType(unsigned int type)
		{
			switch (type)
			{
			case GL_FLOAT:
				return 4;
			case GL_UNSIGNED_INT:
				return 4;
			case GL_UNSIGNED_BYTE:
				return 1;
			}
			CSTL_ASSERT(false);
			return 0;
		}
	};

	class VertexBufferLayout
	{
	public:
		VertexBufferLayout() :
			m_Stride(0) {}

		template<typename T>
		void Push(uint32_t count)
		{
			std::runtime_error("No template args were provided, example of correct usage: Push<float>(3).");
		}

		template<>
		void Push<float>(uint32_t count)
		{
			m_Elements.push_back(VertexBufferElementLayout{ GL_FLOAT, count, GL_FALSE });
			m_Stride += VertexBufferElementLayout::GetSizeOfType(GL_FLOAT) * count;
		}

		template<>
		void Push<uint32_t>(uint32_t count)
		{
			m_Elements.push_back(VertexBufferElementLayout{ GL_UNSIGNED_INT, count, GL_TRUE });
			m_Stride += VertexBufferElementLayout::GetSizeOfType(GL_UNSIGNED_INT) * count;
		}
	public:
		inline std::vector<VertexBufferElementLayout> GetElements() const { return m_Elements; }
		inline uint32_t GetStride() const { return m_Stride; }
	private:
		std::vector<VertexBufferElementLayout> m_Elements;
		uint32_t m_Stride;
	};

}