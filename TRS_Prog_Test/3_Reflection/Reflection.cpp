#include "..\Vector.h"

// I would inline this but wanted to keep consist with directions for separate files
Vector Vector::Reflect(Vector const& toReflect, Vector const& normal)
{
	return toReflect - 2 *  normal * Vector::Dot(normal, toReflect);
}