#include "Driver.h"
#include "Geometry/Color.h"
#include "Geometry/Vertex.h"
#include "Geometry/Shader.h"
#include "Render/Renderer.h"
#include "SDL_assert.h"

Driver::Driver()
	: m_camera(nullptr)
	, m_renderer(nullptr)
	, m_shader(nullptr)
{
}

Driver::~Driver()
{
}

void Driver::SetCamera(Camera * const camera)
{
	m_camera = camera;
}

void Driver::SetShader(ShaderProgram * const shader)
{
	m_shader = shader;
}

void Driver::SetRenderer(Renderer * const renderer)
{
	m_renderer = renderer;
}

void Driver::DrawArrays(const std::vector<Vertex>& vertices, eRenderMode)
{
	//SDL_assert(m_camera);
	SDL_assert(m_renderer);
	//SDL_assert(m_shader);

	/*std::vector<Vertex> verticesTransformed;
	for (const Vertex& vertex : vertices)
	{
		Vertex vertexTransformed = m_shader->VertexShader(vertex);
		verticesTransformed.push_back(vertexTransformed);
	}*/


	// clipping

	// assemble triangle

	// for each triangle {
	//
	// calc BBox
	// 
	// if inside triangle
	// 	 Color color = m_shader->FragmentShader();
	//   m_renderer->DrawPixel(0, 0, color.RGBA);
	// 
	// }


	// convert to viewport coords


}
