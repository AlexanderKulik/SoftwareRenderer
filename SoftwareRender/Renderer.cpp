#include "Renderer.h"


#include "RenderNode.h"
#include "Application.h"

Renderer::Renderer()
{
}


Renderer::~Renderer()
{
}


void Renderer::Render(RenderNode* node)
{
	auto driver = Application::GetInstance()->GetDriver();
	auto geometry = node->GetGeometry();
	//auto transform = node->GetTransform();


	/// assemble triangle from vertex list

	/// perform a transform

	/// rasterize
	//// driver->DrawPixel();
}
