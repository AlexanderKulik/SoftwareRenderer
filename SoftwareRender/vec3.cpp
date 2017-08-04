#include "vec3.h"

#include <math.h>

namespace math
{

	vec3::vec3()
	{
		x = y = z = 0.0f;
	}

	vec3::~vec3()
	{
	}

	vec3::vec3(const float& val)
	{
		x = y = z = val;
	}

	vec3::vec3(const float& x_ , const float& y_, const float& z_)
	{
		x = x_;
		y = y_;
		z = z_;
	}

	vec3 vec3::operator + (const vec3& v2)
	{
		return vec3(x + v2.x, y + v2.y, z + v2.z);
	}

	vec3 vec3::operator - (const vec3& v2)
	{
		return vec3(x - v2.x, y - v2.y, z - v2.z);
	}

	float vec3::length() const
	{
		return sqrt(x*x + y*y + z*z);
	}

}
