/**
* Copyright 2017 Erik Luttmer <erik210@live.nl>
 *
 * @file background.h
 *
 * @brief description of Logo behavior.
 */

#ifndef LOGO_H
#define LOGO_H

#include <vector>
#include <rt2d/vectorx.h>
#include <rt2d/scene.h>
#include <rt2d/timer.h>
#include <rt2d/entity.h>

/// @brief The BackGround class is the Entity implementation.
class Logo : public Entity
{
public:
	/// @brief Constructor
	Logo();
	/// @brief Destructor
	virtual ~Logo();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

	/// @brief the velocity of the spaceship




private:


};

#endif /* LOGO_H */
