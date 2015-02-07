#include "..\Vector.h"

#define BOUNCE 0.7f // 1.0f = full speed from bounce, 0.0f = stop
#define COLLISION_MARGIN 0.5f // How close does particle collide with floor

struct Plane;

struct Particle
{
	Particle(Vector const startPosition, Vector const m_Velocity, float lifetime );

	inline bool IsDead(float const timeCreated) { return timeCreated > m_TimeToLive; }
	void UpdatePosition(Vector const acceleration, Plane const& floor, float const dt);
	
	Vector m_CurPosition;
	Vector m_Velocity;
	float m_TimeToLive;
};