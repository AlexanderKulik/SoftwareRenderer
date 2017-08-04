#include "DriverSoftware.h"

DriverSoftware::DriverSoftware(SDL_Window* window)
{
	//Create renderer for window
	m_renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_assert(m_renderer);

}


DriverSoftware::~DriverSoftware()
{
	SDL_DestroyRenderer(m_renderer);
}

void DriverSoftware::DrawPixel(int x, int y, int color)
{
	Uint8 RGBA[4];
	ConvertFromIntToRGBA(color, RGBA);

	SDL_SetRenderDrawColor(m_renderer, RGBA[0], RGBA[1], RGBA[2], RGBA[3]);

	SDL_RenderDrawPoint(m_renderer, x, y);
}

void DriverSoftware::ClearColorBuffer(int color /*= 0*/)
{
	Uint8 RGBA[4];
	ConvertFromIntToRGBA(color, RGBA);

	SDL_SetRenderDrawColor(m_renderer, RGBA[0], RGBA[1], RGBA[2], RGBA[3]);
	SDL_RenderClear(m_renderer);
}

void DriverSoftware::Blit()
{
	//Update screen
	SDL_RenderPresent(m_renderer);
}

void DriverSoftware::ConvertFromIntToRGBA(const int& asInt, Uint8 asRGBA[4])
{
	union
	{
		int as_int;
		Uint8 as_RGBA[4];
	};

	as_int = asInt;
	SDL_memcpy(asRGBA, as_RGBA, 4);
}

void DriverSoftware::ConvertFromRGBAToInt(const Uint8 asRGBA[4], int& asInt)
{
	union
	{
		int as_int;
		Uint8 as_RGBA[4];
	};

	
	SDL_memcpy(as_RGBA, asRGBA, 4);
	asInt = as_int;

}