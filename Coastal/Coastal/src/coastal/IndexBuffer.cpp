#include "IndexBuffer.h"

Coastal::IndexBuffer::IndexBuffer(uint32_t* data, uint32_t count, uint32_t usage) :
    m_Count(count)
{
    CSTL_ASSERT(sizeof(uint32_t) == sizeof(GLuint));

    CSTL_GLCALL(glGenBuffers(1, &m_RendererId));
    CSTL_GLCALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererId));
    CSTL_GLCALL(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(uint32_t), data, usage));
}

Coastal::IndexBuffer::~IndexBuffer()
{
    glDeleteBuffers(1, &m_RendererId);
}
