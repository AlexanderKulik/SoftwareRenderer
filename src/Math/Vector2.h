#pragma once

namespace math
{
	template <class Ty>
	struct Vector2
	{
		Ty x, y;

		Vector2();
		Vector2(const Ty&);
		Vector2(const Ty&, const Ty&);

		~Vector2();

		Vector2 operator + (const Vector2&) const;
		Vector2 operator - (const Vector2&) const;
		Vector2 operator * (const float) const;

		void Set(const Ty&, const Ty&);

		float Length() const;
		float LengthSq() const;

		Vector2& Normalize();

		
	};

	template <class Ty>
	Vector2<Ty>::Vector2()
		: x(0)
		, y(0)
	{}

	template <class Ty>
	Vector2<Ty>::Vector2(const Ty& val)
		: x(val)
		, y(val)
	{}

	template <class Ty>
	Vector2<Ty>::Vector2(const Ty& x_, const Ty& y_)
		: x(x_)
		, y(y_)
	{}

	template <class Ty>
	Vector2<Ty>::~Vector2()
	{
	}

	template <class Ty>
	Vector2<Ty> Vector2<Ty>::operator + (const Vector2<Ty>& v2) const
	{
		return Vector2(x + v2.x, y + v2.y);
	}

	template <class Ty>
	Vector2<Ty> Vector2<Ty>::operator - (const Vector2<Ty>& v2) const
	{
		return Vector2(x - v2.x, y - v2.y);
	}

	template<class Ty>
	Vector2<Ty> Vector2<Ty>::operator * (const float m) const
	{
		return Vector2(x * m, y * m);
	}

	template<class Ty>
	void Vector2<Ty>::Set(const Ty& x_, const Ty& y_)
	{
		x = x_;
		y = y_;
	}

	template <class Ty>
	float Vector2<Ty>::Length() const
	{
		return sqrt(x*x + y*y);
	}

	template<class Ty>
	float math::Vector2<Ty>::LengthSq() const
	{
		return x*x + y*y;
	}

	template <class Ty>
	Vector2<Ty>& Vector2<Ty>::Normalize()
	{
		const Ty& len = Length();
		x /= len;
		y /= len;
		return *this;
	}

	typedef Vector2<float> Vector2f;
}

