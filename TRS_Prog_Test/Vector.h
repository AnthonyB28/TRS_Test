////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) 2010-2011, Turtle Rock Studios.  All rights reserved.
//
//	Vector.h
//  Description: Header file for Vector class
//
////////////////////////////////////////////////////////////////////////

#include <vector>
#include <math.h>

#pragma once
struct Vector
{
	Vector();
	Vector(float x, float y, float z);
	Vector operator*(float const scalar) const;
	Vector operator-(Vector const& right) const;
	Vector& operator+=(Vector const& right);

	static inline float Dot(Vector const& vec1, Vector const& vec2)
	{
		return vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z;
	}

	static float GetDistanceSqrd(Vector const& vec1, Vector const& vec2);
	// Returns closest vector to point from collection O(n)
	static Vector FindClosest(Vector const& point, std::vector<Vector>const & collection);
	// Returns the vector reflection off normal
	static Vector Reflect(Vector const& toReflect, Vector const& normal);

	float inline GetMagnitude() const
	{
		return sqrt(x*x + y*y + z*z);
	}

	Vector GetNormal() const;

	float x;
	float y;
	float z;
};

// Nonmember overloads
inline Vector operator+(Vector const& left, Vector const& right)
{
	Vector result = left;
	result.x += right.x;
	result.y += right.y;
	result.z += right.z;
	return result;
}

inline Vector operator*(float scalar, Vector const& right)
{
	Vector result = right;
	result.x *= scalar;
	result.y *= scalar;
	result.z *= scalar;
	return result;
}

inline Vector operator/(Vector const& left, float const scalar)
{
	Vector result = left;
	result.x /= scalar;
	result.y /= scalar;
	result.z /= scalar;
	return result;
}