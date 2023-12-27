#include "OpenGLObjectManager.h"

Coastal::OpenGLObjectManager::~OpenGLObjectManager()
{
	for (size_t i = 0; i < m_Vaos.size(); i++)
	{
		uint32_t& vaoId = m_Vaos[i];
		CSTL_GLCALL(glDeleteVertexArrays(1, &vaoId));
	}

	for (size_t i = 0; i < m_Vbos.size(); i++)
	{
		uint32_t& vboId = m_Vbos[i];
		glDeleteBuffers(1, &vboId);
	}

	for (size_t i = 0; i < m_Ibos.size(); i++)
	{
		uint32_t& iboId = m_Ibos[i];
		glDeleteBuffers(1, &iboId);
	}
}

const Coastal::VertexArray& Coastal::OpenGLObjectManager::CreateVertexArray()
{
	Coastal::VertexArray ret;
	m_Vaos.push_back(ret.GetRendererId());
	return ret;
}

const Coastal::VertexBuffer& Coastal::OpenGLObjectManager::CreateVertexBuffer(const void* data, uint32_t size, uint32_t usage)
{
	Coastal::VertexBuffer ret = Coastal::VertexBuffer(data, size, usage);
	m_Vbos.push_back(ret.GetRendererId());

	return ret;
}

const Coastal::IndexBuffer& Coastal::OpenGLObjectManager::CreateIndexBuffer(uint32_t* data, uint32_t count, uint32_t usage)
{
	Coastal::IndexBuffer ret = Coastal::IndexBuffer(data, count, usage);
	m_Ibos.push_back(ret.GetRendererId());
	return ret;
}
