#include "1_LinkedList\LinkedList.h"
#include "4_ParticleSystem\ParticleSystem.h"
#include "Random.h"
#include "Vector.h"
#include <limits>
#include <vector>

#undef max
#undef min

void ProblemOne()
{
	LinkedList<float> a;
	float min = std::numeric_limits<float>::min();
	float max = std::numeric_limits<float>::max();
	for (int i = 0; i < 1000; ++i)
	{
		a.PushBack(RandomGetFloat(min, max));
	}
	a.Sort();
}

void ProblemTwo()
{
	std::vector<Vector> collection;
	for (int i = 0; i < 1000; ++i)
	{
		Vector random(RandomGetFloat(0.0, 20.0), RandomGetFloat(0.0, 20.0), RandomGetFloat(0.0, 20.0));
		collection.push_back(random);
	}
	Vector point(RandomGetFloat(0.0, 20.0), RandomGetFloat(0.0, 20.0), RandomGetFloat(0.0, 20.0));
	Vector out = Vector::FindClosest(point, collection);
}

void ProblemThree()
{
	Vector incident (16.0f, -5.5f, -5.2f);
	Vector norm (-2.0f, 1.0f, -2.0f);
	Vector x = Vector::Reflect(incident, norm);
}

void ProblemFour()
{
	Vector startPos(30.0f, 30.0f, 0.0f);
	Plane ground(Vector(0.0f, 1.0f, 0.0f),Vector(0.0f,0.0f,0.0f));
	ParticleSystem sys(startPos, ground, 10000, 5.0f, 20.0f, 1.0f, 1.0f);
	sys.Run();
}