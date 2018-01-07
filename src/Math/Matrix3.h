#pragma once

#include "Vector2.h"

namespace math
{
	#define ROW_MAJOR (1)

	struct Matrix3
	{

		float m[3][3];

		Matrix3();
		~Matrix3();

		Matrix3 operator * (const Matrix3& m2);
		float* operator [] (const size_t index);

		Matrix3 Transpose();
		Matrix3 Inverse();

		Matrix3& MakeIdentity();
		Matrix3& MakeScale(const Vector2f& scale);
		Matrix3& MakeRotate(const float& angle);
		Matrix3& MakeTranslation(const Vector2f& transform);
	};

}

