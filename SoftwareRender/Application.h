#pragma once

#include "SDL.h"

class Driver;
class Renderer;
class Geometry;
class GeometryManager;
class ShaderProgram;

class Application
{

	//Screen dimension constants
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;

	SDL_Window*			m_window;
	SDL_Renderer*		m_SDLrenderer;

	GeometryManager*	m_geomMgr;
	Driver*				m_driver;
	Renderer*			m_renderer;

	int					m_dt;


	Geometry* m_triangle;
	ShaderProgram* m_shaderSolid;

	void Update(const int dt);
	void Render(const int dt);
	void OnEvent();

	Application();
	~Application();

public:

	static Application*		GetInstance();


	void					Init();
	bool					Run();
	void					Cleanup();

	
	Driver*					GetDriver();
	int						GetFrameTime();
};

