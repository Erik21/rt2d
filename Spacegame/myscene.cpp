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
#include "spacetrash.h"
#include "background.h"
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

	spacetrash = new SpaceTrash();
	spacetrash->position = Point2(500, 328);
	spacetrash->scale = Point(0.5f, 0.5f);

	spacetrash2 = new SpaceTrash();
	spacetrash2->position = Point2(1200, 328);
	spacetrash2->scale = Point(0.5f, 0.5f);

	spacetrash3 = new SpaceTrash();
	spacetrash3->position = Point2(2000, 328);
	spacetrash3->scale = Point(0.5f, 0.5f);

	background = new BackGround();
	background->position = Point2(SWIDTH/2, SHEIGHT/2);
	background->scale = Point(1.0f, 1.0f);

	// create the scene 'tree'
	// add spaceship, vuurzee and spacetrash to this Scene as a child.
	this->addChild(background);
	this->addChild(spaceship);
	this->addChild(vuurzee);
	this->addChild(spacetrash);
	this->addChild(spacetrash2);
	this->addChild(spacetrash3);
	timer = 0;
}

MyScene::~MyScene()
{
	// deconstruct and delete the Tree
	this->removeChild(spaceship);
	this->removeChild(vuurzee);
	this->removeChild(spacetrash);
	this->removeChild(spacetrash2);
	this->removeChild(spacetrash3);
	this->removeChild(background);

	// delete spaceship, spacetrash and vuurzee from the heap (there was a 'new' in the constructor)
	delete spaceship;
	delete vuurzee;
	delete spacetrash;
	delete spacetrash2;
	delete spacetrash3;
	delete background;
}


void MyScene::update(float deltaTime)
{
	// ###############################################################
	// Timer
	// ###############################################################
	timer += deltaTime;

	if (spacetrash == NULL)
	{
		spacetrash = new SpaceTrash();
		addChild(spacetrash);
		spacetrash->position = Point2(vuurzee->position.x + 1300, spaceship->position.y);
		spacetrash->scale = Point(0.5f, 0.5f);
	}

	if (spacetrash2 == NULL)
	{
		spacetrash2 = new SpaceTrash();
		addChild(spacetrash2);
		spacetrash2->position = Point2(vuurzee->position.x + 1300, spaceship->position.y);
		spacetrash2->scale = Point(0.5f, 0.5f);
	}

	if (spacetrash3 == NULL)
	{
		spacetrash3 = new SpaceTrash();
		addChild(spacetrash3);
		spacetrash3->position = Point2(vuurzee->position.x + 1300, spaceship->position.y);
		spacetrash3->scale = Point(0.5f, 0.5f);
	}

	// ###############################################################
	// updateSpaceShip
	// ###############################################################
	spaceship->updateSpaceShip(deltaTime);

	// ###############################################################
	// //SpaceShip vs FireSea
	// ###############################################################
	if (spaceship->position.x <= vuurzee->position.x + 90)
	{
		this->stop();
	}

	// ###############################################################
	// //SpaceTrash vs FireSea
	// ###############################################################
	if (spacetrash->position.x <= vuurzee->position.x + 90)
	{
		std::cout << "Destroy SpaceTrash" << std::endl;
		removeChild(spacetrash);
		delete spacetrash;
		spacetrash = NULL;
	}

	if (spacetrash2->position.x <= vuurzee->position.x + 90)
	{
		std::cout << "Destroy SpaceTrash2" << std::endl;
		removeChild(spacetrash2);
		delete spacetrash2;
		spacetrash2 = NULL;
	}

	if (spacetrash3->position.x <= vuurzee->position.x + 90)
	{
		std::cout << "Destroy SpaceTrash3" << std::endl;
		removeChild(spacetrash3);
		delete spacetrash3;
		spacetrash3 = NULL;
	}

	if(spacetrash == NULL)
	{
		std::cout << "/* SpaceTrash NULLLLL */" << std::endl;
	}

	if(spacetrash2 == NULL)
	{
		std::cout << "/* SpaceTrash2 NULLLLL */" << std::endl;
	}

	if(spacetrash3 == NULL)
	{
		std::cout << "/* SpaceTrash3 NULLLLL */" << std::endl;
	}
	// ###############################################################
	// Circle Collision
	// ###############################################################
	int r1 = 32;
	int r2 = 64;

	if (spacetrash != NULL) {
		Vector2 dv = Vector2(spaceship->position, spacetrash->position);
		float d = dv.getLength();
		if ( d <= (r1 + r2))
		{
			this->stop();
			//::cout << d << " : " << r1 << " -> " << r2 << std::endl;
		}
	}

	if (spacetrash2 != NULL) {
		Vector2 dv = Vector2(spaceship->position, spacetrash2->position);
		float d = dv.getLength();
		if ( d <= (r1 + r2))
		{
			this->stop();
			//::cout << d << " : " << r1 << " -> " << r2 << std::endl;
		}
	}

	if (spacetrash3 != NULL) {
		Vector2 dv = Vector2(spaceship->position, spacetrash3->position);
		float d = dv.getLength();
		if ( d <= (r1 + r2))
		{
			this->stop();
			//::cout << d << " : " << r1 << " -> " << r2 << std::endl;
		}
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
	if(timer >= 0.0f)
	{
	vuurzee->position.x += 0.4f;
	}

	if(timer >= 10.0f)
	{
	vuurzee->position.x += 0.5f;
	}

	if(timer >= 20.0f)
	{
	vuurzee->position.x += 0.6f;
	}

	if(timer >= 30.0f)
	{
	vuurzee->position.x += 0.7f;
	}

	if(timer >= 40.0f)
	{
	vuurzee->position.x += 0.65f;
	}

	// ###############################################################
	// Camera follows vuurzee
	// ###############################################################
	if(timer >= 0.0f)
	{
	camera()->position.x += 0.4f;
	}

	if(timer >= 10.0f)
	{
	camera()->position.x += 0.5f;
	}

	if(timer >= 20.0f)
	{
	camera()->position.x += 0.6f;
	}

	if(timer >= 30.0f)
	{
	camera()->position.x += 0.65f;
	}

	if(timer >= 40.0f)
	{
	camera()->position.x += 0.7f;
	}

	// ###############################################################
	// BackGround follows vuurzee
	// ###############################################################
	if(timer >= 0.0f)
	{
	background->position.x += 0.4f;
	}

	if(timer >= 10.0f)
	{
	background->position.x += 0.5f;
	}

	if(timer >= 20.0f)
	{
	background->position.x += 0.6f;
	}

	if(timer >= 30.0f)
	{
	background->position.x += 0.65f;
	}

	if(timer >= 40.0f)
	{
	background->position.x += 0.7f;
	}

	// ###############################################################
	// Move SpaceShip Up
	// ###############################################################
	if ((input()->getKey(GLFW_KEY_W)) || (input()->getKey(GLFW_KEY_UP)))  {
		spaceship->addSprite("assets/spaceship_up.tga");
		spaceship->velocity.y -= 1 * deltaTime;
	}

	if ((input()->getKeyUp(GLFW_KEY_W)) || (input()->getKeyUp(GLFW_KEY_UP)))  {
		spaceship->addSprite("assets/spaceship.tga");
	}

	// ###############################################################
	// Move SpaceShip Down
	// ###############################################################
	if ((input()->getKey(GLFW_KEY_S)) || (input()->getKey(GLFW_KEY_DOWN))) {
		spaceship->velocity.y += 1 * deltaTime;
		spaceship->addSprite("assets/spaceship_down.tga");
	}

	if ((input()->getKeyUp(GLFW_KEY_S)) || (input()->getKeyUp(GLFW_KEY_DOWN))) {
		spaceship->velocity.y += 1 * deltaTime;
		spaceship->addSprite("assets/spaceship.tga");
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
			camera()->position.y -= 2;
	}

		if (input()->getKey( GLFW_KEY_K )) {
			camera()->position.y += 2;
	}

		if (input()->getKey( GLFW_KEY_J )) {
			camera()->position.x -= 2;
	}

		if (input()->getKey( GLFW_KEY_L )) {
			camera()->position.x += 2;
	}
}

// ###############################################################
// Square Collision
// ###############################################################
//CollideWithPlayer(spaceship, Vector2(0, 328), Vector2(70,328));

bool MyScene::CollideWithPlayer(Entity* other, Vector2 thisRadius, Vector2 otherRadius)
{
  bool collide = false;
  int thisLeft = vuurzee->position.x - thisRadius.x;
  int thisRight = vuurzee->position.x + thisRadius.x;
  int thisTop = vuurzee->position.y - thisRadius.y;
  int thisBottom = vuurzee->position.y + thisRadius.y;

  int otherLeft = other->position.x - otherRadius.x;
  int otherRight = other->position.x + otherRadius.x;
  int otherTop = other->position.y - otherRadius.y;
  int otherBottom = other->position.y + otherRadius.y;

  if (thisRight >= otherLeft && thisLeft <= otherRight && thisBottom >= otherTop && thisTop <= otherBottom) {

  //Checking this bottom side, and other top side
  if (this->position.y + thisRadius.y >= other->position.y - otherRadius.y && this->position.y + thisRadius.y - 1 <= other->position.y - otherRadius.y + 1)
    {
      other->position.y = this->position.y + (thisRadius.y + otherRadius.y + 1);
    }

  //Checking this top side, and other bottom side
  if (this->position.y - thisRadius.y <= other->position.y + otherRadius.y && this->position.y - thisRadius.y + 1 >= other->position.y + otherRadius.y - 1)
    {
      other->position.y = this->position.y - (thisRadius.y + otherRadius.y + 1);
    }

  //Checking this right side, and other left side
  if (this->position.x + thisRadius.x >= other->position.x - otherRadius.x && this->position.x + thisRadius.x - 1 <= other->position.x - otherRadius.x + 1)
    {
      other->position.x = this->position.x + (thisRadius.x + otherRadius.x + 1);
    }

  //Checking this left side, and other right side
  if (this->position.x - thisRadius.x <= other->position.x + otherRadius.x && this->position.x - thisRadius.x + 1 >= other->position.x + otherRadius.x - 1)
    {
      other->position.x = this->position.x - (thisRadius.x + otherRadius.x + 1);
    }
  }
  return collide;
}
