#include "RenderNode.h"


RenderNode::RenderNode(Geometry* geom, math::vec3 pos, math::vec3 rot, math::vec3 scale)
	:m_geom(geom), m_pos(pos), m_rot(rot), m_scale(scale)
{
}


RenderNode::~RenderNode()
{
}


Geometry* RenderNode::GetGeometry()
{
	return m_geom;
}