#pragma once

class RenderNode;

class Renderer
{
	float * m_depthBuffer;
public:

	Renderer();
	~Renderer();

	void Render(RenderNode*);
	void ClearDepthBuffer(float value = 1.0);
};

