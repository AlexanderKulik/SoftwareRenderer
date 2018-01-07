#pragma once

struct Color
{
	unsigned char R, G, B, A;
		
	Color() : Color(255) 
	{}

	Color(unsigned char rgb, unsigned char a = 255) : Color(rgb, rgb, rgb, a)
	{}

	Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a = 255)
	{
		R = r;
		G = g;
		B = b;
		A = a;
	}
};