//
// Created by umair on 5/9/2026.
//
#include <graphics/GraphicsEngine.h>

#include <graphics/Material.h>


void engine::GraphicsEngine::Draw(
    const Mesh& mesh,
    const Shader& shader,
    const Material* material,
    const RenderCamera& camera,
    const RenderLight& light,
    const glm::mat4& model)
{
    shader.Bind();
    shader.SetUniform("projection", camera.projection);
    shader.SetUniform("view", camera.view);
    shader.SetUniform("model", model);
    shader.SetUniform("lightPos", light.position);
    shader.SetUniform("lightColor", light.color);
    shader.SetUniform("viewPos", camera.position);
    if (material) {
        shader.SetUniform("useTexture", material->GetUseTexture());
        shader.SetUniform("diffuseColor", material->GetDiffuseColor());
        shader.SetUniform("shininess", material->GetShininess());
        if (material->GetUseTexture() && material->GetDiffuseTexture())
            material->GetDiffuseTexture()->Bind();
    }
    mesh.Draw();
}
