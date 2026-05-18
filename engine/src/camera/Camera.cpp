#include <camera/Camera.h>
#include <glm/gtc/matrix_transform.hpp>

engine::Camera::Camera()
    : m_aspectRatio(16.f / 9.f),
      m_height(1080.f),
      m_near(0.1f),
      m_far(100.f),
      m_fov(45.f),
      m_projectionType(ProjectionType::PERSPECTIVE),
      m_projectionMatrix(1.f),
      m_upVector(glm::vec3(0.f, 1.f, 0.f)),
      m_position(glm::vec3(0.f, 0.f, 2.f)),
      m_forward(glm::vec3(0.f, 0.f, -1.f))
{
   calculateProjectionMatrix();
   calculateViewMatrix();
}

engine::Camera::Camera(const engine::Camera& other)
    : m_aspectRatio(other.m_aspectRatio),
      m_height(other.m_height),
      m_near(other.m_near),
      m_far(other.m_far),
      m_fov(other.m_fov),
      m_projectionType(other.m_projectionType),
      m_upVector(other.m_upVector),
      m_position(other.m_position),
      m_forward(other.m_forward)
{
   calculateProjectionMatrix();
}


void engine::Camera::SetAspectRatio(float aspectRatio)
{
   m_aspectRatio = aspectRatio;
   calculateProjectionMatrix();
}

void engine::Camera::SetHeight(float height)
{
   m_height = height;
   calculateProjectionMatrix();
}
void engine::Camera::SetProjectionType(ProjectionType type)
{
   m_projectionType = type;
   calculateProjectionMatrix();
}

void engine::Camera::SetNear(float near)
{
   m_near = near;
   calculateProjectionMatrix();
}

void engine::Camera::SetFar(float far)
{
   m_far = far;
   calculateProjectionMatrix();
}
void engine::Camera::SetFOV(float fov)
{
   m_fov = fov;
   calculateProjectionMatrix();
}

void engine::Camera::SetOrtho(float height, float near, float far)
{
   m_height = height;
   m_near = near;
   m_far = far;

   calculateProjectionMatrix();
}

void engine::Camera::SetPosition(glm::vec3 position)
{
   m_position = position;
   calculateViewMatrix();
   
}
void engine::Camera::SetUpVector(glm::vec3 upVector)
{
   m_upVector = upVector;
   calculateViewMatrix();
}

void engine::Camera::SetForward(glm::vec3 forward)
{
   m_forward = forward;
   calculateViewMatrix();
}

void engine::Camera::calculateProjectionMatrix()
{
   if (ProjectionType::ORTHOGRAPHIC == m_projectionType)
   {
      float halfWidth = m_height * m_aspectRatio * 0.5f;
      float halfHeight = m_height * 0.5f;

      m_projectionMatrix = glm::ortho(
          -halfWidth,
           halfWidth,
          -halfHeight,
           halfHeight,
           m_near,
           m_far
      );      
   }
   else
   {
      m_projectionMatrix = glm::perspective(glm::radians(m_fov), m_aspectRatio, m_near, m_far);
   }

}

void engine::Camera::calculateViewMatrix()
{
   m_viewMatrix = glm::lookAt(m_position, m_position + m_forward, m_upVector);
}