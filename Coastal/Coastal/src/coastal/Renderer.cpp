#include "Renderer.h"

void Coastal::Renderer::AddVertexArray(const Coastal::VertexArray& vao)
{
	m_Vaos.push_back(vao);
}

void Coastal::Renderer::AddColor(const Coastal::Rgba& color)
{
	m_Colors.push_back(color);
}

void Coastal::Renderer::AddTransform(const Coastal::Vector2& position)
{
	m_Transforms.push_back(position);
}

void Coastal::Renderer::EditObjectTransform(const Coastal::Vector2& transform, size_t objectIndex)
{
	CSTL_ASSERT(!(objectIndex >= m_Vaos.size())); // Object index is greater than the length of vertex array objects.

	Coastal::Vector2& coastalTransform = m_Transforms[objectIndex];
	coastalTransform = transform;
}

void Coastal::Renderer::EditObjectColor(const Coastal::Rgba& color, size_t objectIndex)
{
	CSTL_ASSERT(!(objectIndex >= m_Vaos.size())); // Object index is greater than the length of vertex array objects.

	Coastal::Rgba& coastalColor = m_Colors[objectIndex];
	coastalColor = color;
}

void Coastal::Renderer::Render() const
{
	m_Shader.Bind();

	for (size_t i = 0; i < m_Vaos.size(); i++)
	{
		const Coastal::VertexArray& vao = m_Vaos[i];
		const Coastal::Vector2& transform = m_Transforms[i];
		const Coastal::Rgba& color = m_Colors[i];

		vao.Bind();
		m_Shader.SetUniform2f("u_Transform", transform);
		m_Shader.SetUniform4f("u_Color", color);

		CSTL_GLCALL(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));
	}
}
