/**
 * This class describes SpaceShip behavior.
 * Copyright 2016 Erik Luttmer <erik210@live.nl>
 */
#include <time.h>
#include <fstream>
#include <sstream>
#include "spaceship.h"


SpaceShip::SpaceShip() : Entity()
{
  this->addSprite("assets/spaceship.tga");

  polar = Polar(0.0f, 1.0f);
  velocity = Vector2(0.1f, 0.1f);
}

SpaceShip::~SpaceShip()
{

}

void SpaceShip::update(float deltaTime)
{

}

void SpaceShip::updateSpaceShip(float deltaTime)
{
  this->position += velocity;
  this->rotation = polar.angle;


  //this->position += velocity * deltaTime;

	if (this->position.x < 0) { this->position.x = SWIDTH; }
	if (this->position.x > SWIDTH) { this->position.x = 0; }
	if (this->position.y < 0) { this->position.y = SHEIGHT; }
	if (this->position.y > SHEIGHT) { this->position.y = 0; }
}
