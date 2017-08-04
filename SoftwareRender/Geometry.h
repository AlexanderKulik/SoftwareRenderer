#pragma once

#include <vector>
#include "vec3.h"

class GeometryManager;

class Geometry
{
	friend class GeometryManager;

	std::vector<math::vec3> m_vertices;
	std::vector<int> m_indices; 

public:

	Geometry();
	~Geometry();


};

