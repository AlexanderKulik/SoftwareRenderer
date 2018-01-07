#pragma once

#include "Math/Vector4.h"
#include "Color.h"
#include "Vertex.h"

class ShaderProgram
{
public:
	virtual math::Vector4 VertexShader(const Vertex&) = 0;
	virtual Color FragmentShader() = 0;

};