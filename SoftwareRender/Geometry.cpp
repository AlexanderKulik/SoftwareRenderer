#include "Geometry.h"

#include "Application.h"
#include "Driver.h"

Geometry::Geometry()
{
}


Geometry::~Geometry()
{
}

void Geometry::Render()
{
	Driver* driver = Application::GetInstance()->GetDriver();

	driver->DrawArrays(m_vertices, Driver::eRenderMode::ERM_TRIANGLE_LIST);
}
