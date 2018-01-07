
#pragma once

#include "Vector2.h"

namespace math
{
	struct AABB2
	{
		Vector2f minPoint;
		Vector2f maxPoint;

		AABB2(const Vector2f&);

		void AddPoint(const Vector2f&);

		template <typename... Args>
		void AddPoints(const Vector2f& p, Args&&... args);

		void AddPoints(const Vector2f& p);
	};

	template <typename... Args>
	void AABB2::AddPoints(const Vector2f& p, Args&&... args)
	{
		AddPoint(p);
		AddPoints(std::forward<Args>(args)...);
	}


	//AABB::AABB(const Vector3f & point)
	//{
	//	minPoint = maxPoint = point;
	//}

	//void AABB::AddPoint(const Vector3f & point)
	//{
	//	if (point.x < minPoint.x)
	//		minPoint.x = point.x;
	//	else if (point.x > maxPoint.x)
	//		maxPoint.x = point.x;

	//	if (point.y < minPoint.y)
	//		minPoint.y = point.y;
	//	else if (point.y > maxPoint.y)
	//		maxPoint.y = point.y;
	//}

}