#pragma once

#include <Rendering/Essentials/Texture.h>
#include <glm/glm.hpp>

namespace otterus_rendering {

    class Material
    {
    public:
        Material() = default;

        const Texture& GetDiffuseTexture() const
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

        void SetDiffuseTexture(const Texture& texture)
        {
            m_diffuseTexture = texture;
            m_useTexture = texture.GetID() != 0;
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
        Texture m_diffuseTexture;
        glm::vec3 m_diffuseColor{1.0f};
        float m_shininess{32.0f};
        float m_specularStrength{0.5f};
        bool m_useTexture{false};
    };

}
