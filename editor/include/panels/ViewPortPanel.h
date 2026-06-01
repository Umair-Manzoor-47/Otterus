#pragma once

class ViewPortPanel
{
public:
	ViewPortPanel(const std::string& title, FrameBuffer* frameBuffer);
	void OnRender() override;

private:
	FrameBuffer* m_frameBuffer;
	glm::vec2 m_size;
    
};
