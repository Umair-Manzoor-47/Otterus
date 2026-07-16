#pragma once
#include <Rendering/Essentials/Texture.h>

namespace otterus_rendering {
	class FrameBuffer {
	public:
		FrameBuffer();		
		FrameBuffer(unsigned int width, unsigned int height, bool useRBO);
		~FrameBuffer();

		
		// Resizing
		void Resize(unsigned int width, unsigned int height);
		void CheckResize();

		// Bind and Unbind
		void Bind();
		void Unbind();

		// Getters
		const unsigned int GetTextureID() const { return m_texture ? m_texture->GetID() : 0; }
		const unsigned int GetID() const { return m_fboID; }
		const unsigned int GetWidth() const { return m_width; }
		const unsigned int GetHeight() const { return m_height; }

	private:
		unsigned int m_fboID = 0, m_rboID = 0;
		unsigned int m_colorAttachment = 0;
		unsigned int m_depthAttachment = 0;
		unsigned int m_width, m_height;
		std::shared_ptr<Texture> m_texture;
		bool m_shouldResize = false, m_useRBO = false;
		

		void create();
		void destroy();
	};
}
