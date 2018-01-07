#pragma once

#include "Vector3.h"

namespace math
{
	#define ROW_MAJOR (1)

	struct Matrix
	{

		float m[4][4];

		Matrix();
		~Matrix();

		Matrix operator * (const Matrix& m2);
		float* operator [] (const size_t index);
		float& Get(const size_t index);

		Matrix Transpose();
		Matrix Inverse();

		Matrix& MakeIdentity();
		Matrix& MakeScale(const Vector3f& scale);
		Matrix& MakeRotateX(const float& angle);
		Matrix& MakeRotateY(const float& angle);
		Matrix& MakeRotateZ(const float& angle);
		Matrix& MakeTranslation(const Vector3f& transform);
	};

}

