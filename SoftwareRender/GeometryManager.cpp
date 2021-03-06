#include "GeometryManager.h"

#include "Geometry.h"

GeometryManager::GeometryManager()
{
}


GeometryManager::~GeometryManager()
{
}

GeometryManager* GeometryManager::GetInstance()
{
	static GeometryManager s_instance;
	return &s_instance;
}

Geometry* GeometryManager::CreatePlane()
{
	Geometry* geometry = new Geometry;
	
	auto& vertexBuffer = geometry->m_vertices;
	vertexBuffer.resize(4);
	vertexBuffer[0].pos = math::Vector3f(-1, 1, 0);
	vertexBuffer[1].pos = math::Vector3f(1, 1, 0);
	vertexBuffer[2].pos = math::Vector3f(1, -1, 0);
	vertexBuffer[3].pos = math::Vector3f(-1, -1, 0);

	auto& indexBuffer = geometry->m_indices;
	indexBuffer.resize(6);
	indexBuffer[0] = 0;
	indexBuffer[1] = 1;
	indexBuffer[2] = 2;

	indexBuffer[3] = 0;
	indexBuffer[4] = 2;
	indexBuffer[5] = 3;

	return geometry;
}

Geometry* GeometryManager::CreateCube()
{
	return nullptr;
}

Geometry* GeometryManager::CreateSphere()
{
	return nullptr;
}

Geometry * GeometryManager::CreateTriangle()
{
	Geometry* geometry = new Geometry;

	auto& vertexBuffer = geometry->m_vertices;
	vertexBuffer.resize(3);
	vertexBuffer[0].pos = math::Vector3f(0, 0.5, 0);
	vertexBuffer[1].pos = math::Vector3f(0.5, -0.5, 0);
	vertexBuffer[2].pos = math::Vector3f(-0.5, -0.5, 0);

	auto& indexBuffer = geometry->m_indices;
	indexBuffer.resize(3);
	indexBuffer[0] = 0;
	indexBuffer[1] = 1;
	indexBuffer[2] = 2;

	return geometry;
}
