#pragma once

class Framebuffer {
public:
	// Takes size
    Framebuffer(ui32 width, ui32 height);
    ~Framebuffer();      

	// Either Render to current attached FrameBuffer OR Screen
    void Bind();             
    void Unbind();           
    void Resize(ui32 width, ui32 height); 

	// Image/Panel ID
    ui32 GetTextureID() const; 
    ui32 GetWidth() const;
    ui32 GetHeight() const;

private:
    ui32 m_fbo = 0;        
    ui32 m_colorAttachment = 0; 
    ui32 m_depthAttachment = 0;  
    ui32 m_width, m_height;

    void create();           
    void destroy();     
};