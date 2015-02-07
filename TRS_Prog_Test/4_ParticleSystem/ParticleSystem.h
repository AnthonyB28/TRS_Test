#include "Particle.h"
#include "Plane.h"
#include "..\Vector.h"
#include <vector>

#define GRAVITY_MS -9.82f

class ParticleSystem
{
public:
	ParticleSystem(Vector const position, Plane const ground, int const size,
		float const minVelocity, float const maxVelocity, float const minLifetime,
		float const maxLifetime);

	void Run();

private:
	std::vector<Particle> m_Particles;
	Plane m_Floor;
	Vector m_Position; // Not needed for the question, but proper to store otherwise
};