/**
 * This class describes VuurZee behavior.
 * Copyright 2016 Erik Luttmer <erik210@live.nl>
 */
#include <time.h>
#include <fstream>
#include <sstream>
#include "spaceship.h"
#include "vuurzee.h"
#include "vector"
// using namespace std;





VuurZee::VuurZee() : Entity()
{
  t.start();
  this->addSprite("assets/FireSea7.tga");

  /*
  a = 1;
  b = 2;
  c = 3;
  d = 4;
  firesea = 1;
  */
}

VuurZee::~VuurZee()
{

}

void VuurZee::update(float deltaTime)
{
/*
  if (firesea == 1) {
		  this->addSprite("assets/FireSea.tga");
      firesea ++;
      cout << firesea;
		}

	if (firesea == 2) {
      this->addSprite("assets/FireSea2.tga");
      firesea ++;
      cout << firesea;
		}

  if (firesea == 3) {
  		this->addSprite("assets/FireSea3.tga");
      firesea ++;
      cout << firesea;
  	}

  if (firesea == 4) {
      this->addSprite("assets/FireSea4.tga");
      firesea = 1;
      cout << firesea;
  	}
  */

}

void VuurZee::CollideWithPlayer(Entity* other, Vector2 thisRadius, Vector2 otherRadius)
{
  int thisLeft = this->position.x - thisRadius.x;
  int thisRight = this->position.x + thisRadius.x;
  int thisTop = this->position.y - thisRadius.y;
  int thisBottom = this->position.y + thisRadius.y;

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
}
