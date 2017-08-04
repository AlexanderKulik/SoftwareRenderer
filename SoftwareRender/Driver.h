#pragma once

class Driver
{
public:
	Driver();
	virtual ~Driver();

	virtual void DrawPixel(int x , int y, int color) = 0;
	virtual void ClearColorBuffer(int color = 0) = 0;
	virtual void Blit() = 0;

};

