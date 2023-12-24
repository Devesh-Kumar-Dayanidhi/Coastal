#include "VertexBuffer.h"

Coastal::VertexBuffer::VertexBuffer(const void* data, uint32_t size, uint32_t usage)
{
    CSTL_GLCALL(glGenBuffers(1, &m_RendererId));
    CSTL_GLCALL(glBindBuffer(GL_ARRAY_BUFFER, m_RendererId));
    CSTL_GLCALL(glBufferData(GL_ARRAY_BUFFER, size, data, usage));
}

Coastal::VertexBuffer::~VertexBuffer()
{
    glDeleteBuffers(1, &m_RendererId);
}
