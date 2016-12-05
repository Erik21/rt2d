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
#include "boidentity.h"

/// @brief The SpaceShip class is the Entity implementation.
class SpaceShip : public Entity
{
public:
	SpaceShip();
	virtual ~SpaceShip();

	virtual void update(float deltaTime);

private:
	Timer t;

//	SpaceShip* spaceship; //?

	void updateSpaceShip(float deltaTime);
};

#endif /* SPACESHIP_H */
