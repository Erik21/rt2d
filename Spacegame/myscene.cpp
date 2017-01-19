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
#include "vuurzee.h"
#include "camera.h"
using namespace std;

MyScene::MyScene() : Scene()
{
	t.start();
	spaceship = new SpaceShip();
	spaceship->position = Point2(SWIDTH/2, SHEIGHT/2);
	spaceship->scale = Point(0.5f, 0.5f);


	vuurzee = new VuurZee();
	vuurzee->position = Point2(0, 328);
	vuurzee->scale = Point(1.0f, 1.6f);

	// create the scene 'tree'
	// add spaceship to this Scene as a child.
	this->addChild(spaceship);
	this->addChild(vuurzee);

	a = 1;
	b = 2;
	c = 3;
	d = 4;
	firesea = 1;
}



MyScene::~MyScene()
{
	// deconstruct and delete the Tree
	this->removeChild(spaceship);
	this->removeChild(vuurzee);

	// delete spaceship from the heap (there was a 'new' in the constructor)
	delete spaceship;
	delete vuurzee;
}


void MyScene::update(float deltaTime)
{
	if (firesea == 1) {
      cout << firesea;
			firesea = 2;
			vuurzee->addSprite("assets/FireSea.tga");
		}

	if (firesea == 2) {
      firesea = 3;
      cout << firesea;
			vuurzee->addSprite("assets/FireSea2.tga");
		}

  if (firesea == 3) {
  		vuurzee->addSprite("assets/FireSea3.tga");
      firesea = 4;
      cout << firesea;
  	}

  if (firesea == 4) {
      vuurzee->addSprite("assets/FireSea4.tga");
      firesea = 1;
      cout << firesea;
  	}
	// ###############################################################
	// //
	// ###############################################################
	spaceship->updateSpaceShip(deltaTime);

	// ###############################################################
	// Collision
	// ###############################################################
	vuurzee->CollideWithPlayer(spaceship, Vector2(0, 328), Vector2(90,328));

	if(vuurzee->CollideWithPlayer(spaceship, Vector2(0, 328), Vector2(90,328)))
	{
			this->stop();
	}

	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	if (input()->getKeyUp( GLFW_KEY_ESCAPE )) {
		this->stop();
	}

	// ###############################################################
	// Move vuurzee
	// ###############################################################
	vuurzee->position.x += 0.4f;

	// ###############################################################
	// Camera follows vuurzee
	// ###############################################################
	camera()->position.x += 0.4f;

	// ###############################################################
	// Move SpaceShip Up
	// ###############################################################
	if ((input()->getKey(GLFW_KEY_W)) || (input()->getKey(GLFW_KEY_UP)))  {
		spaceship->addSprite("assets/spaceship_up.tga");
		vuurzee->addSprite("assets/FireSea2.tga");
		spaceship->velocity.y -= 1 * deltaTime;
	}

	if ((input()->getKeyUp(GLFW_KEY_W)) || (input()->getKeyUp(GLFW_KEY_UP)))  {
		spaceship->addSprite("assets/spaceship.tga");
		vuurzee->addSprite("assets/FireSea3.tga");
	}

	// ###############################################################
	// Move SpaceShip Down
	// ###############################################################
	if ((input()->getKey(GLFW_KEY_S)) || (input()->getKey(GLFW_KEY_DOWN))) {
		spaceship->velocity.y += 1 * deltaTime;
		spaceship->addSprite("assets/spaceship_down.tga");
		vuurzee->addSprite("assets/FireSea.tga");
	}

	if ((input()->getKeyUp(GLFW_KEY_S)) || (input()->getKeyUp(GLFW_KEY_DOWN))) {
		spaceship->velocity.y += 1 * deltaTime;
		spaceship->addSprite("assets/spaceship.tga");
		vuurzee->addSprite("assets/FireSea7.tga");
	}

	// ###############################################################
	// Move SpaceShip to the Left
	// ###############################################################
	if ((input()->getKey(GLFW_KEY_A)) || (input()->getKey(GLFW_KEY_LEFT))) {
		spaceship->velocity.x -= 1 * deltaTime;
		spaceship->addSprite("assets/spaceship_left.tga");
	}

	if ((input()->getKeyUp(GLFW_KEY_A)) || (input()->getKeyUp(GLFW_KEY_LEFT))) {
		spaceship->velocity.x -= 1 * deltaTime;
		spaceship->addSprite("assets/spaceship.tga");
	}

	// ###############################################################
	// Move SpaceShip to the Right
	// ###############################################################
	if ((input()->getKey(GLFW_KEY_D)) || (input()->getKey(GLFW_KEY_RIGHT)))  {
		spaceship->velocity.x += 1 * deltaTime;
		spaceship->addSprite("assets/spaceship_right.tga");
	}

	if ((input()->getKeyUp(GLFW_KEY_D)) || (input()->getKeyUp(GLFW_KEY_RIGHT)))  {
		spaceship->velocity.x += 1 * deltaTime;
		spaceship->addSprite("assets/spaceship.tga");
	}

	// ###############################################################
	// Camera Movement
	// ###############################################################
		if (input()->getKey( GLFW_KEY_I )) {
			camera()->position.y -= 1;
			std::cout << camera()->position.y;
	}

		if (input()->getKey( GLFW_KEY_K )) {
			camera()->position.y += 1;
			std::cout << camera()->position.y;
	}

		if (input()->getKey( GLFW_KEY_J )) {
			camera()->position.x -= 1;
			std::cout << camera()->position.x;
	}

		if (input()->getKey( GLFW_KEY_L )) {
			camera()->position.x += 1;
			std::cout << camera()->position.x;
	}
}
