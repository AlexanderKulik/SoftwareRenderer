#pragma once

#include "Driver.h"
#include "SDL.h"

class DriverSoftware :
	public Driver
{

	SDL_Renderer* m_renderer;

public:
	DriverSoftware(SDL_Window*);
	~DriverSoftware();

	virtual void DrawPixel(int x, int y, int color) override;
	virtual void ClearColorBuffer(int color = 0) override;
	virtual void Blit() override;
	
	void ConvertFromIntToRGBA(const int& asInt, Uint8 asRGBA[4]);
	void ConvertFromRGBAToInt(const Uint8 asRGBA[4], int& asInt);
};

