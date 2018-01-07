#include "Vector4.h"

#include <math.h>

namespace math
{

	Vector4::Vector4()
	{
		x = y = z = 0.0f;
		w = 1.0f;
	}

	Vector4::~Vector4()
	{
	}

	Vector4::Vector4(const float& val)
	{
		x = y = z = val;
	}

	Vector4::Vector4(const float& x_ , const float& y_, const float& z_)
	{
		x = x_;
		y = y_;
		z = z_;
		w = 1.0f;
	}

	Vector4 Vector4::operator + (const Vector4& v2)
	{
		return Vector4(x + v2.x, y + v2.y, z + v2.z);
	}

	Vector4 Vector4::operator - (const Vector4& v2)
	{
		return Vector4(x - v2.x, y - v2.y, z - v2.z);
	}

	float Vector4::length() const
	{
		return sqrtf(x*x + y*y + z*z);
	}

}
