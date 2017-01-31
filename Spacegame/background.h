/**
* Copyright 2016 Erik Luttmer <erik210@live.nl>
 *
 * @file background.h
 *
 * @brief description of BackGround behavior.
 */

#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <vector>
#include <rt2d/vectorx.h>
#include <rt2d/scene.h>
#include <rt2d/timer.h>
#include <rt2d/entity.h>

/// @brief The BackGround class is the Entity implementation.
class BackGround : public Entity
{
public:
	/// @brief Constructor
	BackGround();
	/// @brief Destructor
	virtual ~BackGround();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

	/// @brief the velocity of the spaceship




private:


};

#endif /* BACKGROUND_H */
