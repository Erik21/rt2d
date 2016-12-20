/**
 * This class describes MyScene behavior.
 *
* Copyright 2016 Erik Luttmer <erik210@live.nl>
 */

#include <fstream>
#include <sstream>
#include <rt2d/vectorx.h>
#include <vector>
#include "myscene.h"
#include "spaceship.h"



MyScene::MyScene() : Scene()
{
	t.start();

	spaceship = new SpaceShip();
	spaceship->position = Point2(SWIDTH/2, SHEIGHT/2);
	spaceship->scale = Point(0.5f, 0.5f);

	// create the scene 'tree'
	// add spaceship to this Scene as a child.
	this->addChild(spaceship);
}


MyScene::~MyScene()
{
	// deconstruct and delete the Tree
	this->removeChild(spaceship);

	// delete spaceship from the heap (there was a 'new' in the constructor)
	delete spaceship;
}


void MyScene::update(float deltaTime)
{
	spaceship->updateSpaceShip(deltaTime);

	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	if (input()->getKeyUp( GLFW_KEY_ESCAPE )) {
		this->stop();
	}

	// ###############################################################
	// Move SpaceShip
	// ###############################################################
/*
	if (input()->getKey( GLFW_KEY_UP )) {
		spaceship->line()->color = RED;
		spaceship->velocity += spaceship->polar.cartesian() * deltaTime; // thrust
		std::cout << spaceship->velocity.x << std::endl;
	}
	if (input()->getKey( GLFW_KEY_RIGHT )) {
		spaceship->line()->color = WHITE;
		spaceship->polar.angle += rotspeed * deltaTime; // rotate right
	}
	if (input()->getKey( GLFW_KEY_LEFT)) {
		spaceship->line()->color = WHITE;
		spaceship->polar.angle -= rotspeed * deltaTime; // rotate left
	}
	*/
	if ((input()->getKey(GLFW_KEY_W)) || (input()->getKey(GLFW_KEY_UP)))  {
		spaceship->velocity.y -= 1 * deltaTime;
	//	spaceship->line()->color = RED;
	}
	if ((input()->getKey(GLFW_KEY_S)) || (input()->getKey(GLFW_KEY_DOWN))) {
		spaceship->velocity.y += 1 * deltaTime;
	//	spaceship->line()->color = RED;
	}
	if ((input()->getKey(GLFW_KEY_A)) || (input()->getKey(GLFW_KEY_LEFT))) {
		spaceship->velocity.x -= 1 * deltaTime;
	//	spaceship->line()->color = WHITE;
	}
	if ((input()->getKey(GLFW_KEY_D)) || (input()->getKey(GLFW_KEY_RIGHT)))  {
		spaceship->velocity.x += 1 * deltaTime;
	//	spaceship->line()->color = WHITE;
	}
}
