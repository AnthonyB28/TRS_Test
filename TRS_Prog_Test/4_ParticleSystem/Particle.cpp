#include "Particle.h"
#include "Plane.h"

Particle::Particle(Vector const startPosition, Vector const velocity, float const lifetime)
	: m_CurPosition(startPosition)
	, m_Velocity(velocity)
	, m_TimeToLive(lifetime)
{}

void Particle::UpdatePosition(Vector const acceleration, Plane const& floor, float const dt)
{
	// Collision detection
	// Don't know mass for terminal velocity, so its possible that dt jumps can skip collision
	float distanceToGround = floor.GetDistanceFrom(m_CurPosition);
	if (distanceToGround > 0.0f && distanceToGround < COLLISION_MARGIN)
	{
		m_Velocity = BOUNCE * Vector::Reflect(m_Velocity, floor.m_Normal);
	}

	// Verlet - consistent across framerate/dt gaps
	Vector oldV = m_Velocity;
	m_Velocity += acceleration * dt;
	m_CurPosition += (oldV + m_Velocity) * 0.5f * dt;
}
