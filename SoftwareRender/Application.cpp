#include "Application.h"

#include <chrono>
#include <iostream>

#include "SceneManager.h"
#include "GeometryManager.h"
#include "RenderNode.h"
#include "Renderer.h"

Application::Application()
	:m_renderer(nullptr),
	m_window(nullptr),
	m_dt(16)
{
}

Application* Application::GetInstance()
{
	static Application s_instance;
	return &s_instance;
}

Application::~Application()
{
}

void Application::Init()
{
	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		throw ("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		//Create window
		m_window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (m_window == NULL)
		{
			throw ("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{

			
			//Create renderer for window
			m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
			if (m_renderer == NULL)
			{
				throw ("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
			}

			
		}
	}


	m_sceneMgr = new SceneManager(new Renderer);
	
	m_sceneMgr->AddToScene(new RenderNode(GeometryManager::GetInstance()->CreatePlane()));
}

bool Application::Run()
{

	while (true)
	{

		auto frameStart = std::chrono::high_resolution_clock::now();

		SDL_Event e;
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				return false;
			}
		}


		Update(m_dt);

		if (m_dt < 16)
			SDL_Delay(16 - m_dt);

		auto frameEnd = std::chrono::high_resolution_clock::now();

		m_dt = std::chrono::duration_cast<std::chrono::milliseconds>(frameEnd - frameStart).count();

	}
}


void Application::Cleanup()
{
	//Destroy window
	SDL_DestroyWindow(m_window);

	//Quit SDL subsystems
	SDL_Quit();
}

void Application::Update(const int dt)
{
	std::cout << "" << dt << std::endl;

	//Initialize renderer color//Clear screen
	SDL_SetRenderDrawColor(m_renderer, 0x00, 0x00, 0x00, 0x00);
	SDL_RenderClear(m_renderer);


	SDL_SetRenderDrawColor(m_renderer, 0xFF, 0x00, 0x00, 0xFF);
	SDL_RenderDrawLine(m_renderer, 10, 10, 100, 200);

	//Update screen
	SDL_RenderPresent(m_renderer);
}

void Application::OnEvent()
{

}

Driver*	Application::GetDriver()
{
	return nullptr;
}