#pragma once

namespace math
{

	struct vec3
	{
		float x, y, z;

		vec3();
		vec3(const float&);
		vec3(const float&, const float&, const float&);

		vec3 operator + (const vec3&);
		vec3 operator - (const vec3&);

		float length() const;

		~vec3();
	};

}

