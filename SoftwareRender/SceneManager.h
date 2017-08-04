#pragma once

#include <vector>

class RenderNode;
class Renderer;

class SceneManager
{
	std::vector<RenderNode*> m_renderNodes;
	Renderer* m_renderer;
public:
	
	void AddToScene(RenderNode*);
	void RemoveFromScene(RenderNode*);
	void Render(RenderNode* node = nullptr);

	SceneManager(Renderer*);
	~SceneManager();
};

