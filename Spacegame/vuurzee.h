/**
* Copyright 2016 Erik Luttmer <erik210@live.nl>
 *
 * @file vuurzee.h
 *
 * @brief description of VuurZee behavior.
 */

#ifndef VUURZEE_H
#define VUURZEE_H

#include <vector>
#include <rt2d/vectorx.h>
#include <rt2d/scene.h>
#include <rt2d/timer.h>
#include <rt2d/entity.h>

/// @brief The SpaceShip class is the Entity implementation.
class VuurZee : public Entity
{
public:
	/// @brief Constructor
	VuurZee();
	/// @brief Destructor
	virtual ~VuurZee();
	void CollideWithPlayer(Entity* other, Vector2 thisRadius, Vector2 otherRadius);
	int a, b, c, d;
 	int firesea;

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

	/// @brief the velocity of the spaceship
	Vector2 velocity;



private:
	/// @brief a Timer to rotate the color every n seconds
	Timer t;

};

#endif /* VUURZEE_H */
