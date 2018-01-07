#pragma once

#include "Renderer.h"
#include "SDL.h"

class SoftwareRenderer
	: public Renderer
{

public:

	SoftwareRenderer(SDL_Window*);
	~SoftwareRenderer();

	void DrawPixel(int x, int y, int color) override;
	void ClearColorBuffer(int color = 0) override;
	void ClearDepthBuffer(float value = 1.0) override;
	void Blit() override;

private:

	SDL_Renderer*	m_SDLrenderer;
	float *			m_depthBuffer;
};

