#pragma once

#include <glm/glm.hpp>
#include <core/Common.h>

namespace engine{
	enum class ProjectionType { PERSPECTIVE, ORTHOGRAPHIC };
class Camera
{
	public:
		Camera();
		Camera(const Camera& other);

        float GetAspectRatio() const { return m_aspectRatio; }
		float GetHeight() const { return m_height; }
        float GetNear() const { return m_near; }
        float GetFar() const { return m_far; }
        float GetFOV() const { return m_fov; }
		ProjectionType GetProjectionType() const { return m_projectionType; }

		const glm::vec3& GetPosition() const { return m_position; }
		const glm::vec3& GetForward() const { return m_forward; }
		const glm::vec3& GetUpVector() const { return m_upVector; }
		const glm::vec3& GetRightVector() const { return m_right; }
		const glm::mat4& GetProjectionMatrix() const { return m_projectionMatrix; }
		const glm::mat4& GetViewMatrix() const { return m_viewMatrix; }
	
		void SetAspectRatio(float aspectRatio);
		void SetHeight(float height);
		void SetNear(float near);
		void SetFar(float far);
		void SetFOV(float fov);
		void SetProjectionType(ProjectionType type);
		void SetPosition(const glm::vec3 position);
		void SetForward(const glm::vec3 forward);
		void SetUpVector(const glm::vec3 upVector);
		void SetOrtho(float height, float near = 0.f, float far = 100.f);
		void SetRotation(float yaw, float pitch);

	private:
		float m_aspectRatio;
		float m_height, m_near, m_far;
		float m_fov;
		float m_yaw   = -90.f;
		float m_pitch = 0.f;
	
		ProjectionType m_projectionType;
	
		glm::mat4 m_projectionMatrix;
		glm::mat4 m_viewMatrix;
	
		glm::vec3 m_upVector;
	    glm::vec3 m_position;
		glm::vec3 m_forward;
		glm::vec3 m_right;

		void calculateProjectionMatrix();
		void calculateViewMatrix();
    	
};


}
