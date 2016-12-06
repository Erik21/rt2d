/**
 * This file is part of a demo that shows how to use RT2D, a 2D OpenGL framework.
 *
 * - Copyright 2016 Erik Luttmer <erik210@live.nl>
 *     - Initial commit
 */

#include <time.h>
#include "scene03.h"

RGBAColor colors[10] = { WHITE, GRAY, RED, ORANGE, YELLOW, GREEN, CYAN, BLUE, PINK, MAGENTA };

Scene03::Scene03() : SuperScene()
{
	t.start();

	text[0]->message("Scene03: Static or dynamic lines");

	text[4]->message("<Arrow keys> fly spaceship");

	// Or create a new Line and add it to an Entity later.
	// It will be unique once you added it to an Entity.
	// You must delete it yourself after you've added it to all the Entities you want.
	Line* tmp = new Line();
	tmp->addPoint(-10.0f, -10.0f);
	tmp->addPoint(20.0f, 0.0f);
	tmp->addPoint(-10.0f, 10.0f);
	tmp->addPoint(-10.0f, -10.0f);



	//Create a BasicEntity as our spaceship.
	spaceship = new BasicEntity();
	spaceship->addLine(tmp);
	spaceship->position = Point2(SWIDTH/2, SHEIGHT/2);
	delete tmp; // delete when you're done with it.


	// Create Tree
	layers[0]->addChild(spaceship);
}


Scene03::~Scene03()
{
	layers[0]->removeChild(spaceship);

	delete spaceship;
}

void Scene03::update(float deltaTime)
{
	// ###############################################################
	// Make SuperScene do what it needs to do (Escape key stops Scene)
	// ###############################################################
	SuperScene::update(deltaTime);

	// ###############################################################
	// spaceship
	// ###############################################################
	this->updateSpaceShip(deltaTime);
}

void Scene03::updateSpaceShip(float deltaTime)
{
	spaceship->line()->color = WHITE;

	float rotspeed = 3.14f;

	static Vector2 velocity = Vector2((rand()%100)-50, (rand()%100)-50);
	static Polar polar = Polar((rand()%360) * DEG_TO_RAD, 400.0f);

	if (input()->getKey( GLFW_KEY_UP )) {
		spaceship->line()->color = RED;
		velocity += polar.cartesian() * deltaTime; // thrust
	}
	if (input()->getKey( GLFW_KEY_RIGHT )) {
		polar.angle += rotspeed * deltaTime; // rotate right
	}
	if (input()->getKey( GLFW_KEY_LEFT )) {
		polar.angle -= rotspeed * deltaTime; // rotate left
	}

	spaceship->rotation = polar.angle;
	spaceship->position += velocity * deltaTime;

	if (spaceship->position.x < 0) { spaceship->position.x = SWIDTH; }
	if (spaceship->position.x > SWIDTH) { spaceship->position.x = 0; }
	if (spaceship->position.y < 0) { spaceship->position.y = SHEIGHT; }
	if (spaceship->position.y > SHEIGHT) { spaceship->position.y = 0; }
}
