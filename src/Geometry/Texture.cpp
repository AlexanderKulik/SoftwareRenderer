#include "Texture.h"
#include <algorithm>

Texture::Texture()
	: m_data(nullptr)
	, m_width(0)
	, m_height(0)
{
}

Texture::~Texture()
{
	delete m_data;
}

void Texture::UploadData(void* pixels, const size_t width, const size_t height)
{
	if (m_data)
		delete m_data;

	m_width = width;
	m_height = height;
	m_data = new unsigned char[width * height * 4];

	memcpy(m_data, pixels, width * height * 4);
}

void Texture::GetDataData()
{
}

Color Texture::Sample(const math::Vector2f& uv)
{

	if (m_data == nullptr)
	{
		return Color(0, 0, 0, 0);
	}
	
	const Filtering filterMode = NEAREST;

	if (filterMode == NEAREST)
	{
		const size_t posX = static_cast<size_t>(uv.x * m_width);
		const size_t posY = static_cast<size_t>(uv.y * m_height);

		const size_t idx = (posX * m_width + posY) * 4;
		const auto& r = m_data[idx];
		const auto& g = m_data[idx + 1];
		const auto& b = m_data[idx + 2];
		const auto& a = m_data[idx + 3];

		return Color(r, g, b, a);
	}
	else
	{
		// TODO: linear filtration
		return Color(0, 0, 0, 0);
	}

	
}
