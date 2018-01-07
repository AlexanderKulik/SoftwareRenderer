#pragma once

#include "Math/Vector2.h"
#include "Math/Vector3.h"

struct Vertex
{
	math::Vector3f pos;
	math::Vector3f norm;
	math::Vector3f color;
	math::Vector2f uv;
};