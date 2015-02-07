#include "Plane.h"
#include <math.h>

Plane::Plane(Vector const normal, Vector const originP)
	: m_Normal(normal)
	, m_OriginPoint(originP)
{}

float Plane::GetDistanceFrom(Vector const& target) const
{
	float originToTarget = -Vector::Dot(m_Normal, (target - m_OriginPoint));
	float normMagSqr = Vector::Dot(m_Normal, m_Normal);
	float projection = originToTarget / normMagSqr;
	Vector collisionPoint = target + projection * m_Normal;
	return sqrt(Vector::GetDistanceSqrd(target, collisionPoint));
}
