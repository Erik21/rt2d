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
	Line* tmp = new Line();
	tmp->addPoint(-10.0f, -10.0f);
	tmp->addPoint(20.0f, 0.0f);
	tmp->addPoint(-10.0f, 10.0f);
	tmp->addPoint(-10.0f, -10.0f);

	// create a single instance of SpaceShip in the middle of the screen.
	// the Sprite is added in Constructor of SpaceShip.
	spaceship = new SpaceShip();
	spaceship->addLine(tmp);
	spaceship->position = Point2(SWIDTH/2, SHEIGHT/2);
	delete tmp; // delete when you're done with it.

	// create the scene 'tree'
	// add spaceship to this Scene as a child.
	this->addChild(spaceship);

//polar = Polar((rand()%360) * DEG_TO_RAD, 400.0f);
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
	rotspeed = 3.14f;

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
	// Move myentity
	if ((input()->getKey(GLFW_KEY_W)) || (input()->getKey(GLFW_KEY_UP)))  {
		spaceship->velocity.y -= 2 * deltaTime;
	}
	if ((input()->getKey(GLFW_KEY_S)) || (input()->getKey(GLFW_KEY_DOWN))) {
		spaceship->velocity.y += 2 * deltaTime;
	}
	if ((input()->getKey(GLFW_KEY_A)) || (input()->getKey(GLFW_KEY_LEFT))) {
		spaceship->velocity.x -= 2 * deltaTime;
	}
	if ((input()->getKey(GLFW_KEY_D)) || (input()->getKey(GLFW_KEY_RIGHT)))  {
		spaceship->velocity.x += 2 * deltaTime;
	}
}
