#include "Drawing.h"

void Coastal::LoadAndDrawQuad(float width, float height, float x, float y, const Coastal::Rgba& color, Coastal::OpenGLObjectManager& manager)
{
    Vector2 p1, p2, p3, p4;

    p1 = Vector2((x - width / 2), (y + height / 2));
    p2 = Vector2((x + width / 2), (y + height / 2));
    p3 = Vector2((x - width / 2), (y - height / 2));
    p4 = Vector2((x + width / 2), (y - height / 2));

    float verticies[8] = {
        p1.X, p1.Y,
        p2.X, p2.Y,
        p3.X, p3.Y,
        p4.X, p4.Y
    };

    unsigned int indicies[6] = {
        0, 2, 3,
        0, 1, 3
    };

    Coastal::VertexArray vao = manager.CreateVertexArray();
    vao.Bind();

    Coastal::VertexBuffer vbo = manager.CreateVertexBuffer(verticies, sizeof(verticies), GL_STATIC_DRAW);

    Coastal::VertexBufferLayout layout;
    layout.Push<float>(2);
    vao.AddBuffer(vbo, layout);

    Coastal::IndexBuffer ibo = manager.CreateIndexBuffer(indicies, sizeof(indicies) / sizeof(indicies[0]), GL_STATIC_DRAW);

    Coastal::Shader shader = Coastal::Shader("C:\\Users\\Devesh\\Programs\\C++\\Coastal\\Coastal\\Coastal\\src\\coastal\\res\\shaders\\Basic.shader");
    shader.Bind();

    shader.SetUniform4f("u_Color", color);

    CSTL_GLCALL(glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr));
}

void Coastal::LoadQuad(float width, float height, float x, float y, const Coastal::Rgba& color, Coastal::Renderer& renderer, Coastal::OpenGLObjectManager& manager)
{
    Vector2 p1, p2, p3, p4;

    p1 = Vector2((x - width / 2), (y + height / 2));
    p2 = Vector2((x + width / 2), (y + height / 2));
    p3 = Vector2((x - width / 2), (y - height / 2));
    p4 = Vector2((x + width / 2), (y - height / 2));

    float verticies[8] = {
        p1.X, p1.Y,
        p2.X, p2.Y,
        p3.X, p3.Y,
        p4.X, p4.Y
    };

    unsigned int indicies[6] = {
        0, 2, 3,
        0, 1, 3
    };

    Coastal::VertexArray vao = manager.CreateVertexArray();
    vao.Bind();

    Coastal::VertexBuffer vbo = manager.CreateVertexBuffer(verticies, sizeof(verticies), GL_STATIC_DRAW);

    Coastal::VertexBufferLayout layout;
    layout.Push<float>(2);
    vao.AddBuffer(vbo, layout);

    Coastal::IndexBuffer ibo = manager.CreateIndexBuffer(indicies, sizeof(indicies) / sizeof(indicies[0]), GL_STATIC_DRAW);

    renderer.AddVertexArray(vao);
    renderer.AddTransform(Coastal::Vector2(x, y));
    renderer.AddColor(color);
}