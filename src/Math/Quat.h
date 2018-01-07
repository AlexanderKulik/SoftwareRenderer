
#pragma once

#include "Vector3.h"

namespace math
{
	
	struct Quat
	{
		float x, y, z, w;

		Quat operator * (const Quat&);
		Vector3f operator * (const Vector3f&);
	};

}