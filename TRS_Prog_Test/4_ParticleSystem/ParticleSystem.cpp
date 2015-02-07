#include "ParticleSystem.h"
#include "..\Random.h"
#include "..\Timer.h"

ParticleSystem::ParticleSystem(Vector const position, Plane const ground, int const size,
	float const minVelocity, float const maxVelocity, float const minLifetime, float const maxLifetime)
	: m_Particles()
	, m_Floor(ground)
	, m_Position(position)
{
	m_Particles.reserve(size);
	for (int i = 0; i < size; ++i)
	{
		float randomLifetime = RandomGetFloat(minLifetime, maxLifetime);
		Vector randomVelocity(RandomGetFloat(minVelocity, maxVelocity), RandomGetFloat(minVelocity, maxVelocity),
			RandomGetFloat(minVelocity, maxVelocity));
		m_Particles.push_back(Particle(position, randomVelocity, randomLifetime));
	}
}

// Simulates until all particles are "dead". 
// Different use case could be used with a proper game loop logic.
void ParticleSystem::Run()
{
	float const timeStarted = TimerGetTime32();
	Vector acceleration(0.0f, GRAVITY_MS, 0.0f);
	float dt = 0.0f;

	auto endIt = m_Particles.end();
	while (!m_Particles.empty())
	{
		float curTime = TimerGetTime32();
		auto it = m_Particles.begin();
		float timeSinceStart = curTime - timeStarted;
		while (it != endIt)
		{
			if (it->IsDead(timeSinceStart))
			{
				it = m_Particles.erase(it);
				endIt = m_Particles.end();
			}
			else
			{
				it->UpdatePosition(acceleration, m_Floor, dt);
				++it;
			}
		}
		dt = TimerGetTime32() - curTime;
	}
}





