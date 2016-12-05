/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */
#include <time.h>
#include <fstream>
#include <sstream>
#include "spaceship.h"

RGBAColor colors[10] = { WHITE, GRAY, RED, ORANGE, YELLOW, GREEN, CYAN, BLUE, PINK, MAGENTA };

SpaceShip::SpaceShip() : Entity()
{
		//t.start();
}

SpaceShip::~SpaceShip()
{

}

 void SpaceShip::update(float deltaTime)
	{
		this->updateSpaceShip(deltaTime);
	}

//
void SpaceShip::updateSpaceShip(float deltaTime)
{
	this->line()->color = WHITE;

	float rotspeed = 3.14f;

	static Vector2 velocity = Vector2((rand()%100)-50, (rand()%100)-50);
	static Polar polar = Polar((rand()%360) * DEG_TO_RAD, 400.0f);

	this->rotation = polar.angle;
	this->position += velocity * deltaTime;

	if (this->position.x < 0) { this->position.x = SWIDTH; }
	if (this->position.x > SWIDTH) { this->position.x = 0; }
	if (this->position.y < 0) { this->position.y = SHEIGHT; }
	if (this->position.y > SHEIGHT) { this->position.y = 0; }
}
