//
// Created by umair on 5/9/2026.
//
#include <graphics/GraphicsEngine.h>


void engine::GraphicsEngine::Draw(
    const Mesh& mesh,
    const Shader& shader,
    const Texture* texture,
    const glm::mat4& projection,
    const glm::mat4& view,
    const glm::mat4& model)
{
    shader.Bind();
    if (texture) texture->Bind();
    shader.SetUniform("projection", projection);
    shader.SetUniform("view", view);
    shader.SetUniform("model", model);
    mesh.Draw();
}
