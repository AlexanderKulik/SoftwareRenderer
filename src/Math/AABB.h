
#pragma once

#include "Vector3.h"

namespace math
{
	struct AABB
	{
		Vector3f minPoint;
		Vector3f maxPoint;

		AABB(const Vector3f&);

		void AddPoint(const Vector3f&);

		template <typename... Args>
		void AddPoints(const Vector3f& p, Args&&... args);

		void AddPoints(const Vector3f& p);
	};

	template <typename... Args>
	void AABB::AddPoints(const Vector3f& p, Args&&... args)
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