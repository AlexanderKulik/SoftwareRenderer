#include "mat.h"
#include <memory>

namespace math
{

	mat4::mat4()
	{
		memset(m, 0, sizeof(m));
	}


	mat4::~mat4()
	{
	}

	float* mat4::operator [] (const size_t index)
	{
		return m[index];
	}

	mat4 mat4::operator * (const mat4& m2)
	{
		mat4 result;

		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
			{
				float res = 0.0f;
				for (int k = 0; k < 4; k++)
					res += m[i][k] * m2.m[k][j];
				result[i][j] = res;
			}

		return result;
					
	}

	mat4& mat4::transpose()
	{
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				if (i != j)
					std::swap(m[i][j], m[j][i]);

		return *this;
	}

	mat4& mat4::inverse()
	{
		return *this;
	}

	mat4 mat4::makeIdentity()
	{
		mat4 result;

		result[0][0] = result[1][1] = result[2][2] = result[3][3] = 1.0f;

		return result;
	}

	mat4 mat4::makeScale(const float scale)
	{
		mat4 result;

		result[0][0] = result[1][1] = result[2][2] = scale;
		result[3][3] = 1.0f;

		return result;
	}

	mat4 mat4::makeRotate(const float pitch, const float yaw, const float roll)
	{
		mat4 result;

		

		return result;
	}

	mat4 mat4::makeTransform(const float scale)
	{
		mat4 result;

		result[3][0] = scale;
		result[3][1] = scale;
		result[3][2] = scale;
		result[3][3] = 1.0f;

		return result;
	}

}
