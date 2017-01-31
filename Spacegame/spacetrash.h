/**
* Copyright 2016 Erik Luttmer <erik210@live.nl>
 *
 * @file spacetrash.h
 *
 * @brief description of SpaceTrash behavior.
 */

#ifndef SPACETRASH_H
#define SPACETRASH_H

#include <vector>
#include <rt2d/vectorx.h>
#include <rt2d/scene.h>
#include <rt2d/timer.h>
#include <rt2d/entity.h>

/// @brief The SpaceShip class is the Entity implementation.
class SpaceTrash : public Entity
{
public:
	/// @brief Constructor
	SpaceTrash();
	/// @brief Destructor
	virtual ~SpaceTrash();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

	/// @brief variables
	int a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p;
	/// @brief int firesea
 	int spacetrash;
	/// @brief fireseatimer for delay in Animation
	float spacetrashtimer;
	/// @brief animation timer
	float aniTimer;




private:
	/// @brief a Timer to rotate the color every n seconds
	Timer t;

};

#endif /* SPACETRASH_H */
