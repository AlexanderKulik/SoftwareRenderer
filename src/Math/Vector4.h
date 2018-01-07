#pragma once

namespace math
{

	struct Vector4
	{
		float x, y, z, w;

		Vector4();
		Vector4(const float&);
		Vector4(const float&, const float&, const float&);

		Vector4 operator + (const Vector4&);
		Vector4 operator - (const Vector4&);

		float length() const;

		~Vector4();
	};

}

