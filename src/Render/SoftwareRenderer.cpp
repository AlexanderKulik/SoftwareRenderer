#include "SoftwareRenderer.h"

SoftwareRenderer::SoftwareRenderer(SDL_Window* window)
{
	//Create renderer for window
	m_SDLrenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	//SDL_assert(m_renderer);
	/*if (!m_SDLrenderer)
	{
		const char* errorText = SDL_GetError();
		SDL_assert(false);
	}*/
}


SoftwareRenderer::~SoftwareRenderer()
{
	SDL_DestroyRenderer(m_SDLrenderer);
}

void SoftwareRenderer::DrawPixel(int x, int y, int color)
{
	/*Uint8 RGBA[4];
	ConvertFromIntToRGBA(color, RGBA);

	SDL_SetRenderDrawColor(m_renderer, RGBA[0], RGBA[1], RGBA[2], RGBA[3]);

	SDL_RenderDrawPoint(m_renderer, x, y);*/
}

void SoftwareRenderer::ClearColorBuffer(int color /*= 0*/)
{
	/*Uint8 RGBA[4];
	ConvertFromIntToRGBA(color, RGBA);

	SDL_SetRenderDrawColor(m_renderer, RGBA[0], RGBA[1], RGBA[2], RGBA[3]);
	SDL_RenderClear(m_renderer);*/
}

void SoftwareRenderer::ClearDepthBuffer(float value)
{
}

void SoftwareRenderer::Blit()
{
	//Update screen
	SDL_RenderPresent(m_SDLrenderer);
}

