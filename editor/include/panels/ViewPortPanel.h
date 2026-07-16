#pragma once
#include <string>

#include <Rendering/Buffers/FrameBuffer.h>

#include "Panel.h"
#include "glm/vec2.hpp"
namespace editor {
	class ViewPortPanel: public Panel
	{
	public:
		ViewPortPanel(const std::string& title, otterus_rendering::FrameBuffer* frameBuffer);
		void OnRender() override;

	private:
		otterus_rendering::FrameBuffer* m_frameBuffer;
		glm::vec2 m_size;

	};

}
