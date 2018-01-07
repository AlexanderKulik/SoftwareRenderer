#pragma once

#include "Vector2.h"

namespace math
{

	template <class Ty>
	struct Vector3
	{
		float x, y, z;

		Vector3();
		Vector3(const float&);
		Vector3(const float&, const float&, const float&);
		Vector3(const Vector2<Ty>&);

		Vector3 operator + (const Vector3&) const;
		Vector3 operator - (const Vector3&) const;
		Vector3 operator * (const float) const;

		void Set(const Ty&, const Ty&, const Ty&);

		float Length() const;

		Vector3& Normalize();

		~Vector3();
	};

	template <class Ty>
	Vector3<Ty>::Vector3()
		: Vector3( 0, 0, 0 )
	{}

	template <class Ty>
	Vector3<Ty>::Vector3(const float& val)
		: Vector3( val, val, val )
	{}

	template <class Ty>
	Vector3<Ty>::Vector3(const float& x_, const float& y_, const float& z_)
		: x(x_)
		, y(y_)
		, z(z_)
	{}

	template <class Ty>
	Vector3<Ty>::Vector3(const Vector2<Ty>& v2)
		: x(v2.x)
		, y(v2.y)
		, z(0)
	{}

	template <class Ty>
	Vector3<Ty>::~Vector3()
	{}

	template <class Ty>
	Vector3<Ty> Vector3<Ty>::operator + (const Vector3& v2) const
	{
		return Vector3(x + v2.x, y + v2.y, z + v2.z);
	}

	template <class Ty>
	Vector3<Ty> Vector3<Ty>::operator - (const Vector3& v2) const
	{
		return Vector3(x - v2.x, y - v2.y, z - v2.z);
	}

	template<class Ty>
	Vector3<Ty> Vector3<Ty>::operator * (const float m) const
	{
		return Vector3(x * m, y * m, z * m);
	}

	template<class Ty>
	void Vector3<Ty>::Set(const Ty& x_, const Ty& y_, const Ty& z_)
	{
		x = x_;
		y = y_;
		z = z_;
	}

	template <class Ty>
	float Vector3<Ty>::Length() const
	{
		return sqrt(x*x + y*y + z*z);
	}

	template<class Ty>
	Vector3<Ty>& Vector3<Ty>::Normalize()
	{
		const auto len = Length();
		x /= len;
		y /= len;
		z /= len;
		return *this;
	}

	typedef Vector3<float> Vector3f;
	typedef Vector3<int> Vector3i;
	typedef Vector3<unsigned int> Vector3u;

}

