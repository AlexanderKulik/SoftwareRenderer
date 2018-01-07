#include "Matrix3.h"
#include <memory>

namespace math
{

	Matrix3::Matrix3()
	{
		memset(m, 0, sizeof(m));
		MakeIdentity();
	}


	Matrix3::~Matrix3()
	{
	}

	float* Matrix3::operator [] (const size_t index)
	{
		return m[index];
	}

	Matrix3 Matrix3::operator * (const Matrix3& m2)
	{
		Matrix3 result;

		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
			{
				float res = 0.0f;
				for (int k = 0; k < 3; k++)
					res += m[i][k] * m2.m[k][j];
				result[i][j] = res;
			}

		return result;
					
	}

	Matrix3 Matrix3::Transpose()
	{
		Matrix3 result;

		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				result.m[i][j] = m[j][i];

		return result;
	}

	Matrix3 Matrix3::Inverse()
	{
		// Gauss-Jordan elimination method
		Matrix3 result;

		const float N = 3;

		for (int column = 0; column < N; column++)
		{
			// swap row to the biggest absolute in case it pivot is zero
			if (m[column][column] == 0)
			{
				int big = column;
				for (int row = 0; row < N; row++)
				{
					if (fabs(m[row][column]) > fabs(m[big][column]))
						big = row;
				}

				if (big == column)
				{
					// singular matrix
					throw;
				}
				else
				{
					// swap rows in original and result matrix
					for (int j = 0; j < N; j++)
					{
						std::swap(m[column][j], m[big][j]);
						std::swap(result.m[column][j], result.m[big][j]);
					}
				}

				for (int row = 0; row < N; row++)
				{
					if (row != column)
					{
						auto coef = m[row][column] / m[column][column];
						if (coef != 0)
						{
							for (int j = 0; j < N; j++)
							{
								m[row][j] -= coef * m[column][j];
								result.m[row][j] -= coef * result.m[column][j];
							}
						}

						m[row][column] = 0;
					}
				}

			}
		}

		// set each element of diagonal to 1
		for (int row = 0; row < N; row++)
			for (int column = 0; column < N; column++)
				result.m[row][column] /= m[row][row];

		*this = result;
		
		return result;
	}

	Matrix3& Matrix3::MakeIdentity()
	{
		m[0][0] = m[1][1] = m[2][2] = 1.0f;
		return *this;
	}

	Matrix3& Matrix3::MakeScale(const Vector2f& scale)
	{
		m[0][0] = scale.x;
		m[1][1] = scale.y;
		m[2][2] = 1.0f;
		return *this;
	}

	Matrix3& Matrix3::MakeRotate(const float& angle)
	{
		const float s = sinf(angle);
		const float c = cosf(angle);
#ifdef ROW_MAJOR

		m[0][0] = c;
		m[0][1] = -s;
		m[1][0] = s;
		m[1][1] = c;
#else
		// TODO: rotate matrix
#endif // ROW_MAJOR
		return *this;
	}

	Matrix3& Matrix3::MakeTranslation(const Vector2f& transform)
	{
		
#ifdef ROW_MAJOR
		m[2][0] = transform.x;
		m[2][1] = transform.y;
#else
		// TODO: translate matrix
#endif // ROW_MAJOR
	
		return *this;
	}

}
