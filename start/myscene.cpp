/**
 * This class describes MyScene behavior.
 *
* Copyright 2016 Erik Luttmer <erik210@live.nl>
 */

#include <fstream>
#include <sstream>
#include "myscene.h"
#include "spaceship.h"
#include "boidentity.h"


MyScene::MyScene() : Scene()
{
	// start the timer.
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

	// create a single instance of MyEntity in the screen.
	// the Sprite is added in Constructor of MyEntity.
	myentity = new MyEntity();
	myentity->position = Point2(SWIDTH/3, SHEIGHT/3);


	// create the scene 'tree'
	// add myentity and spaceship to this Scene as a child.
	this->addChild(myentity);
	this->addChild(spaceship);
}


MyScene::~MyScene()
{
	// deconstruct and delete the Tree
	this->removeChild(myentity);
	this->removeChild(spaceship);

	// delete myentity and spaceship from the heap (there was a 'new' in the constructor)
	delete myentity;
	delete spaceship;

//	spaceship->updateSpaceShip(deltaTime);
}


void MyScene::update(float deltaTime)
{
	//spaceship->updateSpaceShip(deltaTime);
	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	if (input()->getKeyUp( GLFW_KEY_ESCAPE )) {
		this->stop();
	}

	// ###############################################################
	// Spacebar scales myentity
	// ###############################################################
	if (input()->getKeyDown( GLFW_KEY_SPACE )) {
		myentity->scale = Point(0.5f, 0.5f);
	}
	if (input()->getKeyUp( GLFW_KEY_SPACE )) {
		myentity->scale = Point(1.0f, 1.0f);
	}

	// ###############################################################
	// Move SpaceShip
	// ###############################################################
	if (input()->getKeyDown( GLFW_KEY_UP )) {
		spaceship->line()->color = RED;
		spaceship->velocity += polar.cartesian() * deltaTime; // thrust
		//spaceship->velocity * deltaTime; // thrust
	}
	if (input()->getKeyDown( GLFW_KEY_RIGHT )) {
		spaceship->polar.angle += rotspeed * deltaTime; // rotate right
		//spaceship->velocity += rotspeed * deltaTime; // rotate right
	}
	if (input()->getKeyDown( GLFW_KEY_LEFT)) {
		spaceship->polar.angle -= rotspeed * deltaTime; // rotate left
		//spaceship->velocity -= rotspeed * deltaTime; // rotate left

	}

	// ###############################################################
	// Rotate color
	// ###############################################################
	if (t.seconds() > 0.0333f) {
		RGBAColor color = myentity->sprite()->color;
		myentity->sprite()->color = Color::rotate(color, 0.01f);
		t.start();
	}
}
