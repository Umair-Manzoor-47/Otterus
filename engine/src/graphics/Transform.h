//
// Created by Umair Manzoor on 5/16/2026.
// Copyright (c) 2026 Otterus, LLC. All rights reserved.
//

#pragma once
#include <glm/glm.hpp>
#include <core/Common.h>

namespace engine {
    class Transform {
    public:
        explicit Transform(const TransformDesc& desc);

        // Setters
        void SetPosition(const glm::vec3& position);
        void SetRotation(const glm::vec3& rotation);
        void SetScale(const glm::vec3& scale);

        // Getters
        glm::vec3 GetPosition() const;
        glm::vec3 GetRotation() const;
        glm::vec3 GetScale() const;

        glm::mat4 GetModelMatrix() const;

    private:
        glm::vec3 m_position;
        glm::vec3 m_scale;
        glm::vec3 m_rotation;

        glm::mat4 m_modelMatrix;

        void generateModelMatrix();
    };
} // engine
