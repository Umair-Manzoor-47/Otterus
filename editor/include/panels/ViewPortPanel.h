#pragma once
#include <string>

#include <graphics/FrameBuffer.h>

#include "Panel.h"
#include "glm/vec2.hpp"
namespace editor {
	class ViewPortPanel: public Panel
	{
	public:
		ViewPortPanel(const std::string& title, FrameBuffer* frameBuffer);
		void OnRender() override;

	private:
		FrameBuffer* m_frameBuffer;
		glm::vec2 m_size;

	};

}
