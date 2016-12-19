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
#include <rt2d/vectorx.h>
#include <vector>
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

	//Polar polar = Polar((rand()%360) * DEG_TO_RAD, 400.0f);
	//Vector2 velocity = Vector2(0.001f, 0.001f);

	float rotspeed;

private:
	/// @...
	SpaceShip* spaceship;
	/// @brief a Timer to rotate the color every n seconds
	Timer t;
	//float rotspeed;
};

#endif /* SCENE00_H */
