#include "AABB2.h"

namespace math
{
	AABB2::AABB2(const Vector2f & point)
	{
		minPoint = maxPoint = point;
	}

	void AABB2::AddPoint(const Vector2f & point)
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


	void AABB2::AddPoints(const Vector2f & p)
	{
		AddPoint(p);
	}
}

