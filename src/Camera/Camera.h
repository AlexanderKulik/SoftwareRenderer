#pragma once

#include "Math/Vector3.h"
#include "Math/Matrix.h"

class Camera
{
public:

	void Init();
	void Update();

	void SetPosition(const math::Vector3f&);
	void SetTarget(const math::Vector3f&);

	const math::Matrix& GetViewTransform();
	const math::Matrix& GetProjectionTransform();

private:

	math::Matrix	m_projMat;
	math::Matrix	m_viewMat;

	math::Vector3f	m_pos;
	math::Vector3f	m_target;
	float			m_fov;
};
