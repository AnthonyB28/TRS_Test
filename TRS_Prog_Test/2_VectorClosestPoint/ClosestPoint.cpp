#include "..\Vector.h"

Vector Vector::FindClosest(Vector const& point, std::vector<Vector>const & collection)
{
	if (collection.size() == 0)
	{
		return point; //  throw an exception, assertion, warning, ect maybe
	}
	Vector closest = collection.at(0);
	float closestDistance = Vector::GetDistanceSqrd(point, closest);
	for (auto it = collection.cbegin() + 1; it != collection.cend(); ++it)
	{
		float distance = Vector::GetDistanceSqrd(point, *it);
		if (distance < closestDistance)
		{
			closestDistance = distance;
			closest = *it;
		}
	}
	return closest;
}