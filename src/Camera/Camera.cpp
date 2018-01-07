#include "Camera.h"

void Camera::Init()
{
	// TODO: init view and projection matrices
}

void Camera::Update()
{
	// if position or target changed, regenerate view matrix
	// if projection params changed, regenerate projection matrix
}

void Camera::SetPosition(const math::Vector3f& pos)
{
	m_pos = pos;
}

void Camera::SetTarget(const math::Vector3f& target)
{
	m_target = target;
}

const math::Matrix& Camera::GetViewTransform()
{
	return m_viewMat;
}

const math::Matrix& Camera::GetProjectionTransform()
{
	return m_projMat;
}
