#pragma once

#include "pch.h"
#include "ErrorHandling.h"

namespace Coastal {

    class VertexBuffer
    {
    public:
        VertexBuffer() { m_RendererId = 0; }
        VertexBuffer(const void* data, uint32_t size, uint32_t usage);
    public:
        inline void Bind() const { glBindBuffer(GL_ARRAY_BUFFER, m_RendererId); }
        inline void UnBind() const { glBindBuffer(GL_ARRAY_BUFFER, 0); }
        inline uint32_t GetRendererId() const { return m_RendererId; }
    private:
        uint32_t m_RendererId;
    };

}