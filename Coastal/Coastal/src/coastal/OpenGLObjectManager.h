#pragma once

#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"

#include <memory>

namespace Coastal {

	class OpenGLObjectManager
	{
	public:
		OpenGLObjectManager() = default;
		~OpenGLObjectManager();
	public:
		const Coastal::VertexArray& CreateVertexArray();
		const Coastal::VertexBuffer& CreateVertexBuffer(const void* data, uint32_t size, uint32_t usage);
		const Coastal::IndexBuffer& CreateIndexBuffer(uint32_t* data, uint32_t count, uint32_t usage);
	private:
		std::vector<uint32_t> m_Vaos;
		std::vector<uint32_t> m_Vbos;
		std::vector<uint32_t> m_Ibos;
	};

}