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

        inline float GetAspectRatio() const { return m_aspectRatio; }
        inline float GetHeight() const { return m_height; }
        inline float GetNear() const { return m_near; }
        inline float GetFar() const { return m_far; }
        inline float GetFOV() const { return m_fov; }
		inline ProjectionType GetProjectionType() const { return m_projectionType; }
		inline glm::vec3 GetPosition() const { return m_position; }
		inline glm::vec3 GetForward() const { return m_forward; }
		inline glm::vec3 GetUpVector() const { return m_upVector; }

	
		void SetAspectRatio(float aspectRatio);
		void SetHeight(float height);
		void SetNear(float near);
		void SetFar(float far);
		void SetFOV(float fov);
		void SetProjectionType(ProjectionType type);
		void SetPosition(glm::vec3 position);
		void SetForward(glm::vec3 forward);
		void SetUpVector(glm::vec3 upVector);
		void SetOrtho(float height, float near = 0.f, float far = 100.f);
		
		const glm::mat4 GetProjectionMatrix() const 
							{return m_projectionMatrix;}
		const glm::mat4 GetViewMatrix() const 
			{return m_viewMatrix;}
	private:
		float m_aspectRatio;
		float m_height, m_near, m_far;
		float m_fov;
		
		ProjectionType m_projectionType;
	
		glm::mat4 m_projectionMatrix;
		glm::mat4 m_viewMatrix;
	
		glm::vec3 m_upVector;
	    glm::vec3 m_position;
		glm::vec3 m_forward;

		void calculateProjectionMatrix();
		void calculateViewMatrix();
    	
};


}
