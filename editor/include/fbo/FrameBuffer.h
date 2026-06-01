#pragma once
#include <core/Core.h>

namespace editor {
	class FrameBuffer {
	public:
		// Takes size
		FrameBuffer(engine::ui32 width, engine::ui32 height);
		~FrameBuffer();

		// Either Render to current attached FrameBuffer OR Screen
		void Bind();
		void Unbind();
		void Resize(engine::ui32 width, engine::ui32 height);

		// Image/Panel ID
		engine::ui32 GetTextureID() const;
		engine::ui32 GetWidth() const;
		engine::ui32 GetHeight() const;

	private:
		engine::ui32 m_fbo = 0;
		engine::ui32 m_colorAttachment = 0;
		engine::ui32 m_depthAttachment = 0;
		engine::ui32 m_width, m_height;

		void create();
		void destroy();
	};
}