#include "VertexArray.h"

namespace Coastal {

	VertexArray::VertexArray()
	{
		CSTL_GLCALL(glGenVertexArrays(1, &m_RendererId));
	}

	void VertexArray::AddBuffer(const Coastal::VertexBuffer& vbo, const Coastal::VertexBufferLayout& layout)
	{
		Bind();
		vbo.Bind();
		const auto& elements = layout.GetElements();
		unsigned int offset = 0;
		for (size_t i = 0; i < elements.size(); i++)
		{
			const auto& element = elements[i];
			CSTL_GLCALL(glEnableVertexAttribArray(i));
			CSTL_GLCALL(glVertexAttribPointer(i, element.count, element.type, element.normalized, layout.GetStride(), (const void*)offset));
			offset += element.count * VertexBufferElementLayout::GetSizeOfType(element.type);
		}
	}

}