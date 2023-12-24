#include "Shader.h"

static const Coastal::__ShaderProgramSource& Coastal::__ParseShader(const std::string& filepath)
{
    std::ifstream stream(filepath);

    if (!(stream.is_open()))
    {
        std::cout << "Shader source file doesn't exist!\n";
        exit(3); // EXIT CODE 3 = SHADER SOURCE FILE NOT FOUND ERROR
    }

    enum class ShaderType
    {
        NONE = -1,
        VERTEX = 0,
        FRAGMENT = 1
    };

    std::string line;
    std::stringstream stringStream[2];
    ShaderType type = ShaderType::NONE;

    while (getline(stream, line))
    {
        if (line.find("#shader") != std::string::npos)
        {
            if (line.find("vertex") != std::string::npos)
            {
                type = ShaderType::VERTEX;
            }
            else if (line.find("fragment") != std::string::npos)
            {
                type = ShaderType::FRAGMENT;
            }
        }
        else if (line.find("//") != std::string::npos)
        {
            for (size_t i = 0; i < line.length(); i++)
            {
                if (line[i] == '/')
                    line[i] = ' ';
            }

            stringStream[(int)type] << line << '\n';
        }
        else
        {
            stringStream[(int)type] << line << '\n';
        }
    }

    return { stringStream[0].str(), stringStream[1].str() };
}

uint32_t Coastal::__CompileShader(uint32_t type, const std::string& source)
{
    CSTL_GLCALL(uint32_t shader = glCreateShader(type));
    const char* src = source.c_str();
    CSTL_GLCALL(glShaderSource(shader, 1, &src, nullptr));
    CSTL_GLCALL(glCompileShader(shader));

    int result;
    CSTL_GLCALL(glGetShaderiv(shader, GL_COMPILE_STATUS, &result));

    if (result == GL_FALSE)
    {
        int length;
        CSTL_GLCALL(glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length));

        char* message = new char[length];
        CSTL_GLCALL(glGetShaderInfoLog(shader, length, &length, message));

        std::cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "vertex shader.\n" : "fragment shader.\n");
        std::cout << message << '\n';

        CSTL_GLCALL(glDeleteShader(shader));

        delete[] message;
        return 0;
    }

    return shader;
}

uint32_t Coastal::__CreateShader(const std::string& vertexShaderSource, const std::string& fragmentShaderSource)
{
    CSTL_GLCALL(uint32_t shader = glCreateProgram());
    uint32_t vertexShader = __CompileShader(GL_VERTEX_SHADER, vertexShaderSource);
    uint32_t fragmentShader = __CompileShader(GL_FRAGMENT_SHADER, fragmentShaderSource);

    CSTL_GLCALL(glAttachShader(shader, vertexShader));
    CSTL_GLCALL(glAttachShader(shader, fragmentShader));
    CSTL_GLCALL(glLinkProgram(shader));
    CSTL_GLCALL(glValidateProgram(shader));

    CSTL_GLCALL(glDeleteShader(vertexShader));
    CSTL_GLCALL(glDeleteShader(fragmentShader));

    return shader;
}

Coastal::Shader::Shader(const std::string& filepath)
{
    __ShaderProgramSource source = __ParseShader(filepath);

    m_RendererId = __CreateShader(source.VertexShaderSource, source.FragmnetShaderSource);
}
