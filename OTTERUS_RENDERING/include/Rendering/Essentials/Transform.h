//
// Created by Umair Manzoor on 5/16/2026.
// Copyright (c) 2026 Otterus, LLC. All rights reserved.
//

#pragma once
#include <glm/glm.hpp>

namespace otterus_rendering {
    struct TransformDesc {
        glm::vec3 Position = glm::vec3(0.0f, 0.0f, 0.0f);
        glm::vec3 Rotation = glm::vec3(0.0f, 0.0f, 0.0f);
        glm::vec3 Scale    = glm::vec3(1.0f, 1.0f, 1.0f);
    };
    class Transform {
    public:
        Transform();
        explicit Transform(const TransformDesc& desc);

        // Setters
        void SetPosition(const glm::vec3& position);
        void SetRotation(const glm::vec3& rotation);
        void SetScale(const glm::vec3& scale);

        // Getters
        const glm::vec3& GetPosition() const;
        const glm::vec3& GetRotation() const;
        const glm::vec3& GetScale() const;

        glm::mat4 GetModelMatrix() const;

    private:
        glm::vec3 m_position;
        glm::vec3 m_scale;
        glm::vec3 m_rotation;

        glm::mat4 m_modelMatrix;

        void generateModelMatrix();
    };
} // engine
