#pragma once

#include <vector>

struct Vertex;
class Camera;
class ShaderProgram;
class Renderer;

class Driver
{
public:

	enum class eRenderMode
	{
		ERM_TRIANGLE_LIST,
		ERM_TRIANGLE_STRIP,
		ERM_LINE_LIST,
		ERM_LINE_STRIP,
	};

	Driver();
	virtual ~Driver();

	void SetCamera(Camera* const);
	void SetShader(ShaderProgram* const);
	void SetRenderer(Renderer* const);
	
	Camera*			GetCamera() const;
	ShaderProgram*	GetShaderProgram() const;
	Renderer*		GetRenderer() const;

	void DrawArrays(const std::vector<Vertex>& vertices, eRenderMode);
	void DrawElements(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices, eRenderMode);

private:

	Renderer*		m_renderer;
	ShaderProgram*	m_shader;
	Camera*			m_camera;
};

