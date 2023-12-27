#include "Renderer.h"

void Coastal::Renderer::AddVertexArray(const Coastal::VertexArray& vao)
{
	m_Vaos.push_back(vao);
}

void Coastal::Renderer::AddShader(const Coastal::Rgba& color)
{
	m_Colors.push_back(color);
}

void Coastal::Renderer::Render() const
{
	m_Shader.Bind();

	for (size_t i = 0; i < m_Vaos.size(); i++)
	{
		const Coastal::VertexArray& vao = m_Vaos[i];
		const Coastal::Rgba& color = m_Colors[i];

		vao.Bind();
		m_Shader.SetUniform4f("u_Color", color);

		CSTL_GLCALL(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));
	}
}
