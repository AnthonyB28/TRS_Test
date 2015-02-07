////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) 2010-2011, Turtle Rock Studios.  All rights reserved.
//
////////////////////////////////////////////////////////////////////////

Engineering Code Exercises

Please create a separate folder/project for each task below. 
Feel free to re-use code amongst the tasks where appropriate. 
Functionality, coding style, design, and efficient use of time will be evaluated. 
You can use the supplied timer and random number functions in your code, or write your own. 

You can look up the solutions for any of the questions in a book or online. 
If you do this, please cite what sources you used in the ReadMe.txt

The supplied project files are from Microsoft Visual 2005, 
but you can replace them with any version including the free Express Edition. 
You can also use Eclipse or any other method to complete the exercises. 

=====
Anthony Barranco:
Please not that some of the code is organized in such a way that I normally wouldn't
do in production, in order to accomodate the directions of seperate folders for solutions.
Particularly, for question 2-4, any Vector related functions I tried to keep as organized
as the directions instructed while also inlining anything that should ideally be in the header.

Solutions.h is just 4 functions with all the necessary includes that show how each exercise is
solved. Feel free to disregard.

Quick reference for Vector math and reflection algorithms
3D Math Primer for Graphics and Game Development, 2nd Edition by Feltcher Dunn & Ian Parberry
ISBN-13: 9781568817231
======



Complete exercises 1 through 4 below:

1. Write a linked list class. Create a list of 1000 random values, one value  per list element.  
Sort the list in ascending order.

====
Anthony Barranco:
Templated the class so either the random floats or ints could be used. I opted for an O(nlogn) 
mergesort using recursion. While it sacrifices memory on the stack (warning, upwards of 
5000 elements can overflow) its a faster sort with 1000 elements I believe than a 
non-recursive one. I could've also implemented quicksort, but quicksort is
not always garunteed to have O(nlogn) performance especially with random elements.
=====


2. Write a very simple 3D vector class. Given 1000 randomly distributed 
and immobile points in a known volume of space, implement a function that returns the 
closest of these points to the given vector position argument in a time-efficient manner.

====
Anthony Barranco:
Because the question asks for only 1000 points, I decided to not go for complicated implementations
such as a kd tree which is more optimal for millions of points as a collection. 1000 points is
small enough that a simple O(n) linear comparison is even more efficient than other complicated
implementations. 
(Src: http://stackoverflow.com/questions/2486093/millions-of-3d-points-how-to-find-the-10-of-them-closest-to-a-given-point)

The static function Vector::FindClosest takes the Vector point and vector of Vectors in which
to compare the point against. It will return a copy of the Vector that is closest to the provided
point. To achieve this, I iterate over the collection and find the smallest distance^2 from the collection
to the provided point. I use distance^2 because the precise magnitude is not necessary, which is provided
by sqrt(distance^2). sqrt is costly operation that can be avoided.
====

3. Write a function that reflects a 3D vector off of a planar surface, given  the surface normal.

====
Anthony Barranco:
The static function Vector::Reflect takes the vector that is to be reflected and the
normal vector to be reflected off of. This returns a copy of the resulting Vector.
====

4. Write a simple particle system where N particles are given a random initial 
velocity away from a given starting point. After their  creation, each particle is 
influenced only by gravity and bounces 	off of an arbitrarily oriented “ground” plane. 
Each particle should “die” after its random lifetime has elapsed.

====
Anthony Barranco:
The particle system used three classes.

Struct Plane is simply a point on a plane (origin) and a normal vector. Makes it easier to
calculate the "floor" that particles will bounce against. I used projection in order to calculate
a vector point's distance to the plane.

Eg: Plane with a normal of (0,1,0) at position (0,0,0) will be an infinite, flat 3D surface
in the x-z planes, facing up at y (like a real ground floor).

The struct Particle is given a start position, velocity, and lifetime. I opted to not give it any
more information than that because the problem did not specify that more particles could be
created over time. Had that been the case, each particle would also have to know the timestamp
in which they were created. But in this case, all particles are created at the same time, thus
they do not need to store duplicates of that information.

Particle's position can be updated with a provided acceleration, a plane that designates the
floor as instructed, and the delta time since the last position update. I calculate
the precise distance from the plane floor, and should the particle be considered "colliding"
in the COLLISION_MARGIN since a particle's size wasn't specified, it will calculate the particle's
bouncde velocity using Vector::Reflect. The position is calculated using a Verlet integration
which provides consistentency across framerate deltas.

One note about collision detection with floor is that there is no terminal velocity for
Particles. Particles dropped have a constant acceleration of GRAVITY_MS which means that
the longer they fall, the faster they fall which contradicts real world physics where
objects eventually reach a constant velocity due to mass. Particles here don't have mass.
So therefore, its possible for particles to be moving fast enough that between updates,
the they skip the COLLISION_MARGIN. The dt between last position and new position is
greater than the margin, and thus no bounce - moving through the floor. I'm not sure
if it was necessary to accomodate for that so I wanted to make it clear that it exists.

The class Particle System has a somewhat ugly-long constructor. I opted to make it easy to
simply pass it min/max floats for its velocity and lifetime to make it easier to play with
and configure. The particle system has a vector of Particles that will immediately reserve
the provided size. This is efficient because it will prevent the vector from resizing itself
N times if I had just done N push_backs without the reserve call. It creates N particles with
random lifetimes and velocitys.

When Run is called on a particle system, it will simulate all N particles being updated with a
psuedo game-loop. While all particles are "alive", N particles are positions are updated linearly
per the directions (only affected by gravity, bounce). It will check if a particle's life time
has expired. Should it expire, it will be removed from the ParticleSystem and memory. When
all particles are dead, the loop stops, and the ParticleSystem's vector should be size 0.

The problem did not specify if it was necessary to be able to "restart" a particle system,
so I figured storing the configuration from the constructor (the mins/maxes) wasn't required. Just
construct a new ParticleSystem and call Run().

Verlet src:
(http://lolengine.net/blog/2011/12/14/understanding-motion-in-games)
====