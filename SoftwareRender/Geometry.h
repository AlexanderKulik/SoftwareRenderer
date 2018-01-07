#pragma once

#include <vector>
#include "Geometry/Vertex.h"

class GeometryManager;

class Geometry
{
	friend class GeometryManager;

	std::vector<Vertex> m_vertices;
	std::vector<int> m_indices; 

public:

	Geometry();
	~Geometry();

	void Render();

};

