/**
* Copyright 2016 Erik Luttmer <erik210@live.nl>
 *
 * @file spaceship.h
 *
 * @brief description of SpaceShip behavior.
 */

#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <vector>
#include <rt2d/vectorx.h>
#include <rt2d/scene.h>
#include <rt2d/timer.h>
#include <rt2d/entity.h>

/// @brief The SpaceShip class is the Entity implementation.
class SpaceShip : public Entity
{
public:
	/// @brief Constructor
	SpaceShip();
	/// @brief Destructor
	virtual ~SpaceShip();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

	/// @brief update spaceship automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	void updateSpaceShip(float deltaTime);

	/// @brief the velocity of the spaceship
	Vector2 velocity;
	/// @brief the polar of the spaceship
	Polar polar;


private:
	/// @brief a Timer to rotate the color every n seconds
	Timer t;

};

#endif /* SPACESHIP_H */
