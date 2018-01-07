#include "AABB.h"

namespace math
{
	AABB::AABB(const Vector3f & point)
	{
		minPoint = maxPoint = point;
	}

	void AABB::AddPoint(const Vector3f & point)
	{
		if (point.x < minPoint.x)
			minPoint.x = point.x;
		else if (point.x > maxPoint.x)
			maxPoint.x = point.x;

		if (point.y < minPoint.y)
			minPoint.y = point.y;
		else if (point.y > maxPoint.y)
			maxPoint.y = point.y;
	}


	void AABB::AddPoints(const Vector3f & p)
	{
		AddPoint(p);
	}
}

