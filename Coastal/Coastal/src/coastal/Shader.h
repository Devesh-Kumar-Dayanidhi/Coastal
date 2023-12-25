#pragma once

#include "pch.h"
#include "ErrorHandling.h"

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
		Shader(const std::string& filepath);
		Shader(const std::string& vertexShaderSource, const std::string& fragmentShaderSource);
	public:
		void Bind() const { CSTL_GLCALL(glUseProgram(m_RendererId)); }
		void UnBind() const { CSTL_GLCALL(glUseProgram(0)); }
		void SetUniform4f(const std::string& name, const Rgba& value);
	private:
		uint32_t m_RendererId;
	};

}