#include "Matrix.h"
#include <memory>

namespace math
{

	Matrix::Matrix()
	{
		memset(m, 0, sizeof(m));
		MakeIdentity();
	}


	Matrix::~Matrix()
	{
	}

	float* Matrix::operator [] (const size_t index)
	{
		return m[index];
	}

	float & Matrix::Get(const size_t index)
	{
		const size_t row = index / 4;
		const size_t col = index % 4;
		return m[row][col];
	}

	Matrix Matrix::operator * (const Matrix& m2)
	{
		Matrix result;

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

	Matrix Matrix::Transpose()
	{
		Matrix result;

		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				result.m[i][j] = m[j][i];

		return result;
	}

	Matrix Matrix::Inverse()
	{
		// TODO: inverse matrix
		Matrix result;

		result.Get(0) = Get(5) * Get(10) * Get(15) - 
						Get(5) * Get(11) * Get(14) - 
						Get(9) * Get(6) * Get(15) +
						Get(9) * Get(7) * Get(14) +
						Get(13) * Get(6) * Get(11) - 
						Get(13) * Get(7) * Get(10);

		result.Get(4) = -Get(4) * Get(10) * Get(15) +
						Get(4) * Get(11) * Get(14) +
						Get(8) * Get(6) * Get(15) -
						Get(8) * Get(7) * Get(14) -
						Get(12) * Get(6) * Get(11) +
						Get(12) * Get(7) * Get(10);

		result.Get(8) = Get(4) * Get(9) * Get(15) -
						Get(4) * Get(11) * Get(13) -
						Get(8) * Get(5) * Get(15) +
						Get(8) * Get(7) * Get(13) +
						Get(12) * Get(5) * Get(11) -
						Get(12) * Get(7) * Get(9);

		result.Get(12) = -Get(4) * Get(9) * Get(14) +
						Get(4) * Get(10) * Get(13) +
						Get(8) * Get(5) * Get(14) -
						Get(8) * Get(6) * Get(13) -
						Get(12) * Get(5) * Get(10) +
						Get(12) * Get(6) * Get(9);

		float det = Get(0) * result.Get(0) + Get(1) * result.Get(1) + Get(2) * result.Get(2) + Get(3) * result.Get(3);

		if (det == 0.0f)
		{

		}

		det = 1.0f / det;

		for (int i = 0; i < 16; i++)
		{
			result.Get(i) *= det;
		}

		return result;
	}

	Matrix& Matrix::MakeIdentity()
	{
		
		m[0][0] = m[1][1] = m[2][2] = m[3][3] = 1.0f;

		return *this;
	}

	Matrix& Matrix::MakeScale(const Vector3f& scale)
	{
		
		m[0][0] = scale.x;
		m[1][1] = scale.y;
		m[2][2] = scale.z;
		m[3][3] = 1.0f;

		return *this;
	}

	Matrix& Matrix::MakeRotateX(const float& angle)
	{
		const float s = sinf(angle);
		const float c = cosf(angle);

		m[1][1] = c;
		m[1][2] = -s;
		m[2][1] = s;
		m[2][2] = c;

		return *this;
	}

	Matrix& Matrix::MakeRotateY(const float& angle)
	{
		const float s = sinf(angle);
		const float c = cosf(angle);

		m[0][0] = c;
		m[0][2] = s;
		m[2][0] = -s;
		m[2][2] = c;
		return *this;
	}

	Matrix& Matrix::MakeRotateZ(const float& angle)
	{
		const float s = sinf(angle);
		const float c = cosf(angle);
#ifdef ROW_MAJOR

		m[0][0] = c;
		m[0][1] = s;
		m[1][0] = -s;
		m[1][1] = c;
#else
		// TODO: rotate matrix
#endif // ROW_MAJOR
		return *this;
	}

	Matrix& Matrix::MakeTranslation(const Vector3f& transform)
	{
		
#ifdef ROW_MAJOR
		m[3][0] = transform.x;
		m[3][1] = transform.y;
		m[3][2] = transform.z;
		m[3][3] = 1.0f;
#else
		// TODO: translate matrix
#endif // ROW_MAJOR
	
		return *this;
	}

}
