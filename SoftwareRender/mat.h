#pragma once

namespace math
{
	struct mat4
	{

		float m[4][4];

		mat4();
		~mat4();

		mat4 operator * (const mat4& m2);
		float* operator [] (const size_t index);

		mat4& transpose();
		mat4& inverse();

		mat4 makeIdentity();
		mat4 makeScale (const float scale);
		mat4 makeRotate(const float pitch, const float yaw, const float roll);
		mat4 makeTransform(const float scale);
	};

}

