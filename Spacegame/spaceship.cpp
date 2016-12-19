/**
 * This class describes SpaceShip behavior.
 * Copyright 2016 Erik Luttmer <erik210@live.nl>
 */
#include <time.h>
#include <fstream>
#include <sstream>
#include "spaceship.h"
#include "boidentity.h"

SpaceShip::SpaceShip() : Entity()
{

  polar = Polar(0.0f, 1.0f);
  velocity = Vector2(0.001f, 0.001f);
  t.start();
//  polar = Polar((rand()%360) * DEG_TO_RAD, 400.0f);
//	velocity = Vector2(0.001f, 0.001f);
}

SpaceShip::~SpaceShip()
{

}

void SpaceShip::update(float deltaTime)
{
 //this->updateSpaceShip(deltaTime);
}

void SpaceShip::updateSpaceShip(float deltaTime)
{
  this->position += velocity;
  this->rotation = polar.angle;
  //this->rotation = velocity.getAngle();

  this->line()->color = BLUE;

  //this->position += velocity * deltaTime;

	if (this->position.x < 0) { this->position.x = SWIDTH; }
	if (this->position.x > SWIDTH) { this->position.x = 0; }
	if (this->position.y < 0) { this->position.y = SHEIGHT; }
	if (this->position.y > SHEIGHT) { this->position.y = 0; }
}
