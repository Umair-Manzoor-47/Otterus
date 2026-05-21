//
// Created by umair on 5/9/2026.
//
#include <graphics/GraphicsEngine.h>


void engine::GraphicsEngine::Draw(
    const Mesh& mesh,
    const Shader& shader,
    const Texture* texture,
    const RenderCamera& camera,
    const RenderLight& light,
    const glm::mat4& model)
{
    shader.Bind();
    if (texture) texture->Bind();
    shader.SetUniform("projection", camera.projection);
    shader.SetUniform("view", camera.view);
    shader.SetUniform("model", model);
    shader.SetUniform("lightPos", light.position);
    shader.SetUniform("lightColor", light.color);
    shader.SetUniform("viewPos", camera.position);
    mesh.Draw();
}
