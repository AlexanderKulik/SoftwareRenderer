#pragma once

#include "Geometry/Shader.h"

class ShaderSolid 
	: public ShaderProgram
{
public:
	math::Vector4 VertexShader(const Vertex&) override;
	Color FragmentShader() override;

};