#pragma once

#include "Math/Vector2.h"
#include "Geometry/Color.h"

class Texture
{
	enum Filtering { NEAREST, LINEAR };
	
	size_t m_width;
	size_t m_height;
	unsigned char *m_data;

public:
	Texture();
	~Texture();
	void UploadData(void* pixels, const size_t width, const size_t height);
	void GetDataData();
	Color Sample(const math::Vector2f& uv);
};