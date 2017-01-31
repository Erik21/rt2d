/**
 * This class describes background behavior.
 * Copyright 2016 Erik Luttmer <erik210@live.nl>
 */

#include "background.h"


BackGround::BackGround() : Entity()
{
  this->addSprite("assets/background.tga");
}

BackGround::~BackGround()
{

}

void BackGround::update(float deltaTime)
{

}
