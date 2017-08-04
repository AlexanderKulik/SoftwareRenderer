#pragma once

#include "SDL.h"

class Driver;
class SceneManager;
class GeometryManager;

class Application
{

	//Screen dimension constants
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;

	SDL_Window*			m_window;
	SDL_Renderer*		m_renderer;

	SceneManager*		m_sceneMgr;
	GeometryManager*	m_geomMgr;

	int					m_dt;

	void Update(const int dt);
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

