
#pragma once

#include "vec3.h"
#include "mat.h"

namespace math
{
	float dot(const vec3&, const vec3&);

	vec3 cross(const vec3&, const vec3&);

	vec3 transform(const mat4&, const vec3&);
}