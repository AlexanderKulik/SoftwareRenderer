#include "Math.h"
#include <cassert>

namespace math
{
	float Dot(const Vector3f& v1, const Vector3f& v2)
	{
		return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	}

	Vector3f Cross(const Vector3f& v1, const Vector3f& v2)
	{
		// determinant of 3x3 matrix
		// |  i     j     k   |
		// | v1.x  v1.y  v1.z |
		// | v2.x  v2.y  v2.z |
		//
		// i j k - basis vectors
		//
		// i x j = k
		// j x k = i
		// k x i = j
		//
		// j x i = -k
		// k x j = -i
		// i x k = -j
		//
		// i x i = j x j = k x k = 0
		// 
		// u = u1 * i + u2 * j + u3 * k
		// v = v1 * i + v2 * j + v3 * k
		// u x v = (u1 * i + u2 * j + u3 * k) x (v1 * i + v2 * j + v3 * k)

		return Vector3f(v1.y * v2.z - v1.z * v2.y, 
			v1.z * v2.x - v1.x*v2.z, 
			v1.x * v2.y - v1.y * v2.x);
	}

	float Cross(const Vector2f& v1, const Vector2f& v2)
	{
		// determinant of 2x2 matrix consists of 2 vectors
		// | v1.x  v1.y |
		// | v2.x  v2.y |
		// D(M) = v1.x * v2.y - v1.y * v2.x;
		return v1.x * v2.y - v2.x * v1.y;
	}

	Vector3f Transform(const Matrix& m, const Vector3f& v)
	{
		Vector4 result;
		const Vector4 vH{ v.x, v.y, v.z };

		result.x = vH.x * m.m[0][0] + vH.y * m.m[1][0] + vH.z * m.m[2][0] + vH.w * m.m[3][0];
		result.y = vH.x * m.m[0][1] + vH.y * m.m[1][1] + vH.z * m.m[2][1] + vH.w * m.m[3][1];
		result.z = vH.x * m.m[0][2] + vH.y * m.m[1][2] + vH.z * m.m[2][2] + vH.w * m.m[3][2];
		result.w = vH.x * m.m[0][3] + vH.y * m.m[1][3] + vH.z * m.m[2][3] + vH.w * m.m[3][3];

		if (result.w != 1.0f)
		{
			result.x /= result.w;
			result.y /= result.w;
			result.z /= result.w;
		}

		return Vector3f(result.x, result.y, result.z);
	}

	Vector2f Transform(const Matrix3& m, const Vector2f& v)
	{
		Vector3f result;
		const Vector3f vH{ v.x, v.y, 1.0f };

		result.x = vH.x * m.m[0][0] + vH.y * m.m[1][0] + vH.z * m.m[2][0];
		result.y = vH.x * m.m[0][1] + vH.y * m.m[1][1] + vH.z * m.m[2][1];
		result.z = vH.x * m.m[0][2] + vH.y * m.m[1][2] + vH.z * m.m[2][2];

		return Vector2f(result.x, result.y);
	}

	Matrix Perspective(const float & l, const float & r, const float & t, const float & b, const float & n, const float & f)
	{
		assert(false);
#if ROW_MAJOR

#endif
		return Matrix();
	}

	Matrix Perspective(const float & fov, const float & ar, const float & n, const float & f)
	{
		assert(false);
		return Matrix();
	}

	Matrix Ortho(const float & l, const float & r, const float & t, const float & b, const float & n, const float & f)
	{
		assert(false);
		return Matrix();
	}
}