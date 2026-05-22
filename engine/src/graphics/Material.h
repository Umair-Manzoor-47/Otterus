#pragma once

#include <graphics/Texture.h>
#include <core/common.h>

namespace engine {

class Material
{
public:
    Material() = default;

    // Getters
    std::shared_ptr<Texture> GetDiffuseTexture() const
    {
        return m_diffuseTexture;
    }

    const glm::vec3& GetDiffuseColor() const
    {
        return m_diffuseColor;
    }

    float GetShininess() const
    {
        return m_shininess;
    }

    float GetSpecularStrength() const
    {
        return m_specularStrength;
    }

    bool GetUseTexture() const
    {
        return m_useTexture;
    }

    // Setters
	void SetDiffuseTexture(const std::shared_ptr<Texture>& texture) {
    	m_diffuseTexture = texture;
    	m_useTexture = (texture != nullptr);
	}

    void SetDiffuseColor(const glm::vec3& color)
    {
        m_diffuseColor = color;
    }

    void SetShininess(float value)
    {
        m_shininess = value;
    }

    void SetSpecularStrength(float value)
    {
        m_specularStrength = value;
    }

    void SetUseTexture(bool value)
    {
        m_useTexture = value;
    }

private:
	glm::vec3 m_diffuseColor = glm::vec3(1.0f);
	float m_shininess = 32.f;
	float m_specularStrength = 0.5f;
	bool m_useTexture = false;
    std::shared_ptr<Texture> m_diffuseTexture;
};


}
