#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

#ifdef _CSTL_DEBUG
#define CSTL_ASSERT(x) if (!(x)) __debugbreak(); 
#define CSTL_GLCALL(x) Coastal::GLClearError();\
    x;\
    CSTL_ASSERT(Coastal::GLLogCall(#x, __FILE__, __LINE__))
#else
#define CSTL_ASSERT(x) x
#define CSTL_GLCALL(x) x
#endif

namespace Coastal {

    static void GLClearError()
    {
        while (glGetError() != GL_NO_ERROR);
    }

    static bool GLLogCall(const char* function, const char* file, int line)
    {
        while (GLenum error = glGetError()) {
            std::cout << "[OpenGl Error] (" << error << ")\n" << "Function: " << function << '\n' << "File: " << file << '\n' << "Line: " << line << '\n';
            return false;
        }

        return true;
    }

}