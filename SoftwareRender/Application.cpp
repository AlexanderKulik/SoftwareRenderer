#if _MSC_VER > 1800
#include <stdio.h>
#pragma comment(lib, "legacy_stdio_definitions.lib")

FILE _iob[] = { *stdin, *stdout, *stderr };

extern "C" FILE * __cdecl __iob_func(void)
{
	return _iob;
}

#endif

#include "Application.h"

#include <chrono>
#include <iostream>

#include "Geometry.h"
#include "GeometryManager.h"
#include "Render/SoftwareRenderer.h"
#include "Shaders/ShaderSolid.h"
#include "Driver.h"

////////////debug/////////
#include <array>
#include "Math/Matrix.h"
#include "Math/Math.h"
#include "Math/AABB2.h"
#include "Geometry/Vertex.h"
#include "Geometry/Color.h"
#include "Geometry/Texture.h"

struct MeshData
{
	math::Vector3f pos;
	float scale;
	float angle;

	math::Matrix CalculateModelMatrix()
	{
		math::Matrix mScale;
		mScale.MakeScale({ scale });

		math::Matrix mRotation;
		mRotation.MakeRotateZ(angle);

		math::Matrix mTranslation;
		mTranslation.MakeTranslation(pos);

		return mScale * mRotation * mTranslation;
	}

};

MeshData meshData;

math::Matrix3 vpMat;

Texture checkerTexture;

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
			m_SDLrenderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_SOFTWARE);
			if (m_SDLrenderer == NULL)
			{
				throw ("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
			}

			
		}
	}

	m_driver = new Driver();

	m_renderer = new SoftwareRenderer(m_window);
	m_driver->SetRenderer(m_renderer);


	m_shaderSolid = new ShaderSolid;
	m_triangle = GeometryManager::GetInstance()->CreateTriangle();

	//meshData.pos.Set(SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f, 0.0f);
	meshData.angle = 0.0f;
	meshData.scale = 1.0f;

	vpMat[0][0] = SCREEN_WIDTH * 0.5f;
	vpMat[2][0] = SCREEN_WIDTH * 0.5f;
	vpMat[1][1] = -SCREEN_HEIGHT * 0.5f;
	vpMat[2][1] = SCREEN_HEIGHT * 0.5f;

	auto vpInv = vpMat;
	vpInv.Inverse();

	auto mat = vpMat * vpInv;

	auto ndcCoords = math::Transform(vpInv, { SCREEN_WIDTH * 0.5f ,SCREEN_HEIGHT * 0.5f });

	/// texture 

	Color c[8][8];

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (j % 2 == 0)
			{ 
				c[i][j].R = c[i][j].G = c[i][j].B = 255;
			}
			else
			{
				c[i][j].R = c[i][j].G = c[i][j].B = 128;
				c[i][j].R = 255;
				c[i][j].G = 0;
				c[i][j].B = 0;
			}

			c[i][j].A = 255;
		}
	}

	checkerTexture.UploadData(c, 8, 8);

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

			if (e.type == SDL_EventType::SDL_KEYDOWN)
			{
				if (e.key.keysym.sym == SDLK_DOWN)
				{
					meshData.pos.y -= 1.0f / SCREEN_HEIGHT;
				}
				else if (e.key.keysym.sym == SDLK_UP)
				{
					meshData.pos.y += 1.0f / SCREEN_HEIGHT;
				}
				else if (e.key.keysym.sym == SDLK_RIGHT)
				{
					meshData.pos.x += 1.0f / SCREEN_WIDTH;
				}
				else if (e.key.keysym.sym == SDLK_LEFT)
				{
					meshData.pos.x -= 1.0f / SCREEN_WIDTH;
				}
				else if (e.key.keysym.sym == SDLK_KP_PLUS)
				{
					meshData.scale += 0.1f;
				}
				else if (e.key.keysym.sym == SDLK_KP_MINUS)
				{
					meshData.scale -= 0.1f;
				}
				else if (e.key.keysym.sym == SDLK_KP_MULTIPLY)
				{
					meshData.angle -= (M_PI * 1.0f / 180.0f);
				}
				else if (e.key.keysym.sym == SDLK_KP_DIVIDE)
				{
					meshData.angle += (M_PI * 1.0f / 180.0f);
				}
				
			}
			else if (e.type == SDL_EventType::SDL_KEYUP)
			{
				
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

	delete m_driver;
	delete m_renderer;

	//Destroy window
	SDL_DestroyWindow(m_window);

	//Quit SDL subsystems
	SDL_Quit();

}

void Application::Update(const int dt)
{
	std::cout << "" << 1000 / dt << std::endl;

	Render(dt);
	
}

math::Vector3f getBarycentricCoords(const math::Vector2f& p, 
	const math::Vector2f& a, const math::Vector2f& b, const math::Vector2f& c)
{
	math::Vector3f bary;

	const math::Vector2f v0 = b - a, v1 = c - a, v2 = p - a;

	const float d00 = math::Dot(v0, v0);
	const float d01 = math::Dot(v0, v1);
	const float d11 = math::Dot(v1, v1);
	const float d20 = math::Dot(v2, v0);
	const float d21 = math::Dot(v2, v1);
	const float denom = d00 * d11 - d01 * d01;

	const float v = (d11 * d20 - d01 * d21) / denom;
	const float w = (d00 * d21 - d01 * d20) / denom;
	const float u = 1.0f - v - w;

	return math::Vector3f(u, v, w);
};

math::Vector3f getBarycentricCoords2(const math::Vector2f& p,
	const math::Vector2f& a, const math::Vector2f& b, const math::Vector2f& c)
{
	const float areaABC = math::Cross(b - a, c - a);
	const float areaPBC = math::Cross(b - p, c - p);
	const float areaPCA = math::Cross(c - p, a - p);

	const float u = areaPBC / areaABC;
	const float v = areaPCA / areaABC;
	const float w = 1.0f - u - v;

	return math::Vector3f(u, v, w);

	// float area ABC = dot(normal, cross(b-a, c-a));
	// float area PBC
	// float area PCA
	//
	// bary.x = areaPBC / areaABC;
	// 
	//
};

void Application::Render(const int dt)
{
	m_triangle->Render();

	//Initialize renderer color//Clear screen
	SDL_SetRenderDrawColor(m_SDLrenderer, 0x00, 0x00, 0x00, 0x00);
	SDL_RenderClear(m_SDLrenderer);


	SDL_SetRenderDrawColor(m_SDLrenderer, 0xFF, 0x00, 0x00, 0xFF);





	auto renderAABB = [this](const Vertex& v0, const Vertex& v1, const Vertex& v2)
	{
		const math::Vector2f v2f0 = math::Transform(vpMat, { v0.pos.x, v0.pos.y });
		const math::Vector2f v2f1 = math::Transform(vpMat, { v1.pos.x, v1.pos.y });
		const math::Vector2f v2f2 = math::Transform(vpMat, { v2.pos.x, v2.pos.y });

		math::AABB2 aabb(v2f0);
		aabb.AddPoints(v2f1, v2f2);

		Uint8 RGBA[4];
		SDL_GetRenderDrawColor(m_SDLrenderer, RGBA, RGBA + 1, RGBA + 2, RGBA + 3);
		SDL_SetRenderDrawColor(m_SDLrenderer, 255, 255, 255, 20);
		SDL_SetRenderDrawBlendMode(m_SDLrenderer, SDL_BlendMode::SDL_BLENDMODE_BLEND);
		SDL_Rect rect;
		rect.x = aabb.minPoint.x;
		rect.y = aabb.minPoint.y;
		rect.w = aabb.maxPoint.x - aabb.minPoint.x;
		rect.h = aabb.maxPoint.y - aabb.minPoint.y;
		SDL_RenderFillRect(m_SDLrenderer, &rect);
		SDL_SetRenderDrawColor(m_SDLrenderer, RGBA[0], RGBA[1], RGBA[2], RGBA[3]);
	};

	auto renderTriangle = [this](const Vertex& v0, const Vertex& v1, const Vertex& v2)
	{
		const math::Vector2f v2f0 = math::Transform(vpMat, { v0.pos.x, v0.pos.y });
		const math::Vector2f v2f1 = math::Transform(vpMat, { v1.pos.x, v1.pos.y });
		const math::Vector2f v2f2 = math::Transform(vpMat, { v2.pos.x, v2.pos.y });

		const math::Vector2f side0 = v2f1 - v2f0;
		const math::Vector2f side1 = v2f2 - v2f1;
		const math::Vector2f side2 = v2f0 - v2f2;

		math::AABB2 aabb(v2f0);
		aabb.AddPoints(v2f1, v2f2);

		for (float x = aabb.minPoint.x; x <= aabb.maxPoint.x; x += 1.0f)
		{
			for (float y = aabb.minPoint.y; y <= aabb.maxPoint.y; y += 1.0f)
			{
				const math::Vector2f point{ x, y };

				const math::Vector3f bary = getBarycentricCoords(point, v2f0, v2f1, v2f2);

				//const math::Vector2f vector0 = point - v2f0;
				//const float cross0 = -math::Cross(vector0, side0);
				//
				//const math::Vector2f vector1 = point - v2f1;
				//const float cross1 = -math::Cross(vector1, side1);
				//
				//const math::Vector2f vector2 = point - v2f2;
				//const float cross2 = -math::Cross(vector2, side2);
				//
				//
				//
				//if (cross0 >= 0.0f && cross1 >= 0.0f && cross2 >= 0.0f)
				if (bary.x >= 0.0f && bary.y >= 0.0f && bary.z >= 0.0f)
				{
					//auto bary = getBarycentricCoords(point, v2f0, v2f1, v2f2);

					const float A = bary.x, B = bary.y, C = bary.z;
					
					const math::Vector3f finalColor = v0.color * A + v1.color * B + v2.color * C;
					const math::Vector2f uv = v0.uv * A + v1.uv * B + v2.uv * C;

					const Color samplerColor = checkerTexture.Sample(uv);

					Uint8 r = static_cast<Uint8>(finalColor.x * samplerColor.R);
					Uint8 g = static_cast<Uint8>(finalColor.y * samplerColor.G);
					Uint8 b = static_cast<Uint8>(finalColor.z * samplerColor.B);

					SDL_SetRenderDrawColor(m_SDLrenderer, r, g, b, 255);
					//SDL_SetRenderDrawColor(m_SDLrenderer, samplerColor.R, samplerColor.G, samplerColor.B, 255);
					SDL_RenderDrawPoint(m_SDLrenderer, x, y);
				}
			}

		}
		
		//SDL_RenderDrawLine(m_SDLrenderer, v0.x, v0.y, v1.x, v1.y);
		//SDL_RenderDrawLine(m_SDLrenderer, v1.x, v1.y, v2.x, v2.y);
		//SDL_RenderDrawLine(m_SDLrenderer, v2.x, v2.y, v0.x, v0.y);
	};

	std::array<Vertex, 4> vertices;
	vertices[0].pos.Set(-0.5f, 0.5f, 0.0f);
	vertices[0].color.Set(1.0f, 0.0f, 0.0f);
	vertices[0].uv.Set(0.0f, 0.0f);

	vertices[1].pos.Set(0.5f, 0.5f, 0.0f);
	vertices[1].color.Set(0.0f, 1.0f, 0.0f);
	vertices[1].uv.Set(1.0f, 0.0f);

	vertices[2].pos.Set(0.5f, -0.5f, 0.0f);
	vertices[2].color.Set(0.0f, 0.0f, 1.0f);
	vertices[2].uv.Set(1.0f, 1.0f);

	vertices[3].pos.Set(-0.5f, -0.5f, 0.0f);
	vertices[3].color.Set(1.0f, 1.0f, 0.0f);
	vertices[3].uv.Set(0.0f, 1.0f);


	short indices[6] = 
	{
		0, 1, 2,
		0, 2, 3,
	};

	const int vertCnt = vertices.size();// sizeof(vertices) / sizeof(vertices[0]);
	const int indCnt = sizeof(indices) / sizeof(indices[0]);
	const int triCnt = indCnt / 3;

	Vertex verticesTransformed[vertCnt];
	
	math::Matrix mModel = meshData.CalculateModelMatrix();

	for (int i = 0; i < vertCnt; i++)
	{
		verticesTransformed[i] = vertices[i];
		verticesTransformed[i].pos = math::Transform(mModel, vertices[i].pos);
	}

	for (int i = 0; i < triCnt; i++)
	{
		const int nextIdx = i * 3;
		const short& idx0 = indices[nextIdx];
		const short& idx1 = indices[nextIdx + 1];
		const short& idx2 = indices[nextIdx + 2];
		renderTriangle(verticesTransformed[idx0], verticesTransformed[idx1], verticesTransformed[idx2]);
	}

	for (int i = 0; i < triCnt; i++)
	{
		const int nextIdx = i * 3;
		const short& idx0 = indices[nextIdx];
		const short& idx1 = indices[nextIdx + 1];
		const short& idx2 = indices[nextIdx + 2];
		renderAABB(verticesTransformed[idx0], verticesTransformed[idx1], verticesTransformed[idx2]);
	}

	/////////////////////////////////////
	//math::Vector2f v1(10, 10);
	//math::Vector2f v2(100, 40);
	//
	//const float dy = fabsf((v1.y - v2.y) / (v1.x - v2.x));
	//float x = v1.x;
	//float y = v1.y;
	//for (; x <= v2.x; )
	//{
	//	
	//	x += 1.0f;
	//	y += dy;
	//	SDL_RenderDrawPoint(m_SDLrenderer, x, y);
	//
	//}
	//
	//SDL_RenderDrawLine(m_SDLrenderer, v1.x + 20, v1.y, v2.x + 20, v2.y);

	//Update screen
	SDL_RenderPresent(m_SDLrenderer);
}

void Application::OnEvent()
{

}

Driver*	Application::GetDriver()
{
	return m_driver;
}

int Application::GetFrameTime()
{
	return m_dt;
}
