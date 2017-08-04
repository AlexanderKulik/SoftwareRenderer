#pragma once

#include "vec3.h"
#include "mat.h"

class Geometry;

class RenderNode
{

	math::vec3 m_pos;
	math::vec3 m_scale;
	math::vec3 m_rot;

	Geometry* m_geom;

public:
	RenderNode(Geometry*, math::vec3 pos = math::vec3(), math::vec3 rot = math::vec3(), math::vec3 scale = math::vec3(1.0));
	~RenderNode();

	Geometry* GetGeometry();
	math::mat4 GetTransform();
};

