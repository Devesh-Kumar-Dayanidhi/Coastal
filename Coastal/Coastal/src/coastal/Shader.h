#pragma once

#include "pch.h"
#include "ErrorHandling.h"

namespace Coastal {

	struct __ShaderProgramSource
	{
		std::string VertexShaderSource, FragmnetShaderSource;
	};
	
	static const __ShaderProgramSource& __ParseShader(const std::string& filepath);
	static uint32_t __CompileShader(uint32_t type, const std::string& source);
    static uint32_t __CreateShader(const std::string& vertexShaderSource, const std::string& fragmentShaderSource);

}

namespace Coastal {

	typedef unsigned int uint32_t;

	class Shader
	{
	public:
		Shader(const std::string& filepath);
	public:

	private:
		uint32_t m_RendererId;
	};

}