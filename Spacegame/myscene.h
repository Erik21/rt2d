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
#include "vuurzee.h"
#include "spacetrash.h"
#include "background.h"
#include "logo.h"
#include <rt2d/text.h>


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

	bool CollideWithPlayer(Entity* other, Vector2 thisRadius, Vector2 otherRadius);
	float timer;

private:
	//
	//std::vector<SpaceTrash*> boids;
	/// @brief the spaceship in the middle of the screen
	SpaceShip* spaceship;
	/// @brief the vuurzee in the left of the screen
	VuurZee* vuurzee;
	/// @brief the SpaceTrash in the screen
	SpaceTrash* spacetrash;
	/// @brief the SpaceTrash2 in the screen
	SpaceTrash* spacetrash2;
	/// @brief the SpaceTrash3 in the screen
	SpaceTrash* spacetrash3;
	/// @brief the spaceship in the middle of the screen
	BackGround* background;
	/// @brief the logo in the middle of the screen
	Logo* logo;
};




#endif /* SCENE00_H */
