#pragma once

class Geometry;

class GeometryManager
{

	GeometryManager();
	~GeometryManager();
public:


	static GeometryManager* GetInstance();

	Geometry* CreatePlane();
	Geometry* CreateCube();
	Geometry* CreateSphere();
};

