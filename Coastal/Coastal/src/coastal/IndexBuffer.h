#pragma once

#pragma once

#include "pch.h"
#include "ErrorHandling.h"

namespace Coastal {

    class IndexBuffer
    {
    public:
        IndexBuffer() { m_RendererId = 0; m_Count = 0; }
        IndexBuffer(uint32_t* data, uint32_t count, uint32_t usage);
        ~IndexBuffer();
    public:
        inline size_t GetCount() const { return m_Count; }
    public:
        inline void Bind() const { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererId); }
        inline void UnBind() const { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); }
    private:
        uint32_t m_RendererId;
        size_t m_Count;
    };

}