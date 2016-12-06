/**
 * Copyright 2016 Erik Luttmer <erik210@live.nl>
 *
 * @file myscene.h
 *
 * @brief description of MyScene behavior.
 */

#ifndef MYSCENE_H
#define MYSCENE_H

#include <rt2d/scene.h>
#include <vector>
#include "boidentity.h"
#include "myentity.h"
#include "spaceship.h"

/// @brief The MyScene class is the Scene implementation.
class MyScene : public Scene
{
public:
	/// @brief Constructor
	MyScene();
	/// @brief Destructor
	virtual ~MyScene();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);
	void updateSpaceShip(float deltaTime);
	Vector2 velocity;

private:
	/// @brief the rotating square in the middle of the screen
	MyEntity* myentity;
	/// @....
	SpaceShip* spaceship;
	/// @brief a Timer to rotate the color every n seconds
	Timer t;

	Polar polar;
	float rotspeed;
};

#endif /* SCENE00_H */
