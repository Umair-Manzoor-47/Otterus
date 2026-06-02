#include <fbo/FrameBuffer.h>
#include <glad/glad.h>
#include <spdlog/fmt/bundled/base.h>

editor::FrameBuffer::FrameBuffer(): FrameBuffer(640, 480, false) {}

editor::FrameBuffer::FrameBuffer(engine::ui32 width, engine::ui32 height, bool useRBO)
    : m_fboID(0), m_rboID(0), m_width(width)
    , m_height(height), m_texture(nullptr), m_shouldResize(false)
    , m_useRBO(useRBO)
{
    m_texture = std::make_shared<engine::Texture>(engine::Texture(width, height));
    create();
}

void editor::FrameBuffer::create()
{

    glGenFramebuffers(1, &m_fboID);
    glBindFramebuffer(GL_FRAMEBUFFER, m_fboID);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_texture->GetID(), 0);

    if (m_useRBO)
    {
        glGenRenderbuffers(1, &m_rboID);
        glBindRenderbuffer(GL_RENDERBUFFER, m_rboID);
        
        glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT32, m_width, m_height);
        glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, m_rboID);
    }
    
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}