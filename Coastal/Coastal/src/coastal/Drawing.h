#pragma once

#include "Vector2.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "Shader.h"
#include "Renderer.h"
#include "OpenGLObjectManager.h"

namespace Coastal {

    void LoadAndDrawQuad(float width, float height, float x, float y, const Coastal::Rgba& color, Coastal::OpenGLObjectManager& manager);
    void LoadQuad(float width, float height, float x, float y, const Coastal::Rgba& color, Coastal::Renderer& renderer, Coastal::OpenGLObjectManager& manager);

}