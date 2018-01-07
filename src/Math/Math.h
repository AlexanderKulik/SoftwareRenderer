
#pragma once

#include "Vector3.h"
#include "Vector4.h"
#include "Matrix3.h"
#include "Matrix.h"

namespace math
{

	float Dot(const Vector3f&, const Vector3f&);

	Vector3f Cross(const Vector3f&, const Vector3f&);

	float Cross(const Vector2f&, const Vector2f&);

	Vector3f Transform(const Matrix&, const Vector3f&);
	
	Vector2f Transform(const Matrix3&, const Vector2f&);

	Matrix Perspective(const float& l, const float& r, const float& t, const float& b, const float& n, const float& f);
	
	Matrix Perspective(const float& fov, const float& ar, const float& n, const float& f);

	Matrix Ortho(const float& l, const float& r, const float& t, const float& b, const float& n, const float& f);

}