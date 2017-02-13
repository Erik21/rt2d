/**
 * This class describes background behavior.
 * Copyright 2017 Erik Luttmer <erik210@live.nl>
 */

#include "logo.h"


Logo::Logo() : Entity()
{
  this->addSprite("assets/logo.tga");
}

Logo::~Logo()
{

}

void Logo::update(float deltaTime)
{

}
