#pragma once

//class RenderNode;

class Renderer
{
	
public:

	Renderer();
	virtual ~Renderer();

	virtual void DrawPixel(int x, int y, int color) = 0;
	virtual void ClearColorBuffer(int color = 0) = 0;
	virtual void ClearDepthBuffer(float value = 1.0) = 0;;
	virtual void Blit() = 0;

	//void Render(RenderNode*);
	
};

