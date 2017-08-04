#include "math.h"

namespace math
{
	float dot(const vec3& v1, const vec3& v2)
	{
		return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	}

	vec3 cross(const vec3& v1, const vec3& v2)
	{
		return vec3();
	}

	vec3 transform(const mat4& m, const vec3& v)
	{
		return vec3();
	}
}