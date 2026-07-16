#include <glm/gtc/matrix_transform.hpp>
#include <Rendering/Essentials/Transform.h>

namespace otterus_rendering
{
    Transform::Transform()
    : m_position(0.f)
    , m_scale(1.f)
    , m_rotation(0.f) {

        generateModelMatrix();
    }

    Transform::Transform(const TransformDesc &desc):
        m_position(desc.Position),
        m_scale(desc.Scale),
        m_rotation(desc.Rotation) {

        generateModelMatrix();
    }

    void Transform::SetPosition(const glm::vec3 &position) {
        m_position = position;
        generateModelMatrix();
    }

    void Transform::SetRotation(const glm::vec3 &rotation) {
        m_rotation = rotation;
        generateModelMatrix();
    }

    void Transform::SetScale(const glm::vec3 &scale) {
        m_scale = scale;
        generateModelMatrix();
    }

    const glm::vec3& Transform::GetPosition() const {
        return m_position;
    }

    const glm::vec3& Transform::GetRotation() const {
        return m_rotation;
    }

    const glm::vec3& Transform::GetScale() const {
        return m_scale;
    }

    glm::mat4 Transform::GetModelMatrix() const {
        return m_modelMatrix;
    }

    void Transform::generateModelMatrix() {
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, m_position);

        model = glm::rotate(model, glm::radians(m_rotation.x), glm::vec3(1,0,0)); // X axis
        model = glm::rotate(model, glm::radians(m_rotation.y), glm::vec3(0,1,0)); // Y axis
        model = glm::rotate(model, glm::radians(m_rotation.z), glm::vec3(0,0,1)); // Z axis

        m_modelMatrix = glm::scale(model, m_scale);
    }
}