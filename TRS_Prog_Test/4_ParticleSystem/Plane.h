#include "..\Vector.h"

struct Plane
{
	Plane(Vector const normal, Vector const originP);

	// Projects target onto normal and returns the distance to plane
	float GetDistanceFrom(Vector const& target) const;

	Vector m_Normal;
	Vector m_OriginPoint;
};