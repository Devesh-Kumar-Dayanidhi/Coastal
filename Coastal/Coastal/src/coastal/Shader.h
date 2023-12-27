#pragma once

#include <string>
#include <sstream>
#include <fstream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "ErrorHandling.h"
#include "Rgba.h"
#include "Vector2.h"
#include "Vector3.h"

namespace Coastal {

	struct __ShaderProgramSource
	{
		std::string VertexShaderSource, FragmnetShaderSource;
	};
	
	__ShaderProgramSource __ParseShader(const std::string& filepath);
	std::string __ParseFile(const std::string& filepath);
	uint32_t __CompileShader(uint32_t type, const std::string& source);
    uint32_t __CreateShader(const std::string& vertexShaderSource, const std::string& fragmentShaderSource);

}

namespace Coastal {

	typedef unsigned int uint32_t;

	class Shader
	{
	public:
		Shader() { m_RendererId = -1; }
		~Shader() { CSTL_GLCALL(glDeleteProgram(m_RendererId)); }
		Shader(const std::string& filepath);
		Shader(const std::string& vertexShaderSource, const std::string& fragmentShaderSource);
	public:
		void Bind() const { CSTL_GLCALL(glUseProgram(m_RendererId)); }
		void UnBind() const { CSTL_GLCALL(glUseProgram(0)); }
		void SetUniform1f(const std::string& name, float value) const;
		void SetUniform2f(const std::string& name, const Coastal::Vector2& value) const;
		void SetUniform3f(const std::string& name, const Coastal::Vector3& value) const;
		void SetUniform4f(const std::string& name, const Coastal::Rgba& value) const;
	private:
		uint32_t m_RendererId;
	};

}