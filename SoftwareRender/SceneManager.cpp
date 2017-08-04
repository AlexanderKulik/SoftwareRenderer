#include "SceneManager.h"
#include "Renderer.h"

SceneManager::SceneManager(Renderer* renderer)
	:m_renderer(renderer)
{
}


SceneManager::~SceneManager()
{
}


void SceneManager::AddToScene(RenderNode* node)
{
	_ASSERT(std::find(m_renderNodes.begin(), m_renderNodes.end(), node) == m_renderNodes.end());
	m_renderNodes.push_back(node);
}

void SceneManager::RemoveFromScene(RenderNode* node)
{
	_ASSERT(std::find(m_renderNodes.begin(), m_renderNodes.end(), node) != m_renderNodes.end());
	//m_renderNodes.push_back(node);
}

void SceneManager::Render(RenderNode* node)
{
	if (node == nullptr)
	{
		for (auto& renderNode : m_renderNodes)
		{
			m_renderer->Render(renderNode);
		}
	}
	else
	{
		m_renderer->Render(node);
	}
}