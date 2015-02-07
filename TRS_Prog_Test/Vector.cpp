////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) 2010-2011, Turtle Rock Studios.  All rights reserved.
//
//	Vector.cpp
//  Description: Implementation file for Vector class
//
////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Vector.h"

Vector::Vector() 
	: x(0)
	, y(0)
	, z(0)
{}

Vector::Vector(float x, float y, float z) 
	: x(x)
	, y(y)
	, z(z)
{}

Vector Vector::operator*(float const scalar) const
{
	Vector result = *this;
	result.x *= scalar;
	result.y *= scalar;
	result.z *= scalar;
	return result;
}

Vector& Vector::operator+=(Vector const& right)
{
	this->x += right.x;
	this->y += right.y;
	this->z += right.z;
	return *this;
}

Vector Vector::operator-(Vector const& right) const
{
	Vector result = *this;
	result.x -= right.x;
	result.y -= right.y;
	result.z -= right.z;
	return result;
}

float Vector::GetDistanceSqrd(Vector const& vec1, Vector const& vec2)
{
	float dx = vec2.x - vec1.x;
	float dy = vec2.y - vec1.y;
	float dz = vec2.z - vec1.z;
	return dx * dx + dy * dy + dz * dz; // no need to sqrt this
}

Vector Vector::GetNormal() const
{
	return (*this) / GetMagnitude();
}
