#pragma once
#include <core/Core.h>
#include <graphics/Texture.h>

namespace editor {
	class FrameBuffer {
	public:
		FrameBuffer();		
		FrameBuffer(engine::ui32 width, engine::ui32 height, bool useRBO);
		~FrameBuffer();

		
		// Resizing
		void Resize(engine::ui32 width, engine::ui32 height);
		void CheckResize();

		// Getters
		const engine::ui32 GetTextureID() const { return m_texture ? m_texture.GetID() : 0; }
		const engine::ui32 GetID() const { return m_fboID; }
		const engine::ui32 GetWidth() const { return m_width; }
		const engine::ui32 GetHeight() const { return m_height; }

	private:
		engine::ui32 m_fboID = 0, m_rboID = 0;
		engine::ui32 m_colorAttachment = 0;
		engine::ui32 m_depthAttachment = 0;
		engine::ui32 m_width, m_height;
		std::shared_ptr<engine::Texture> m_texture;
		bool m_shouldResize = false, m_useRBO = false;
		

		void create();
		void destroy();
	};
}
