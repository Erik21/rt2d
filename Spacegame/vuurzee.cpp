/**
 * This class describes VuurZee behavior.
 * Copyright 2016 Erik Luttmer <erik210@live.nl>
 */
#include <time.h>
#include <fstream>
#include <sstream>
#include "vuurzee.h"
#include "vector"
using namespace std;

VuurZee::VuurZee() : Entity()
{
    // Sets variables of firesea Animation
    a = 1;
    b = 2;
    c = 3;
    d = 4;
    e = 5;
    f = 6;
    g = 7;
    h = 8;
    i = 9;
    j = 10;
    k = 11;
    l = 12;

    firesea = a;
    fireseatimer = 0;
    aniTimer = 0.1f;
}

VuurZee::~VuurZee()
{

}

void VuurZee::update(float deltaTime)
{
  // ###############################################################
  // FireSea Animation
  // ###############################################################
  fireseatimer += deltaTime;

  if (firesea == a) {
      this->addSprite("assets/Fire1.tga");
      cout << firesea;
      firesea = b;
      fireseatimer = 0;
    }

  if (fireseatimer >= 0.1f && firesea == b) {
      this->addSprite("assets/Fire2.tga");
      firesea = c;
      cout << firesea;
      fireseatimer = 0;
    }

  if (fireseatimer >= 0.1f && firesea == c) {
      this->addSprite("assets/Fire3.tga");
      firesea = d;
      cout << firesea;
      fireseatimer = 0;
    }

  if (fireseatimer >= 0.1f && firesea == d) {
      this->addSprite("assets/Fire4.tga");
      firesea = e;
      cout << firesea;
      fireseatimer = 0;
    }

  if (fireseatimer >= 0.1f && firesea == e) {
      this->addSprite("assets/Fire5.tga");
      firesea = f;
      cout << firesea;
      fireseatimer = 0;
    }


  if (fireseatimer >= 0.1f && firesea == f) {
      this->addSprite("assets/Fire6.tga");
      firesea = g;
      cout << firesea;
      fireseatimer = 0;
    }

  if (fireseatimer >= 0.1f && firesea == g) {
      this->addSprite("assets/Fire7.tga");
      firesea = h;
      cout << firesea;
      fireseatimer = 0;
    }

  if (fireseatimer >= 0.1f && firesea == h) {
      this->addSprite("assets/Fire8.tga");
      firesea = i;
      cout << firesea;
      fireseatimer = 0;
    }

  if (fireseatimer >= 0.1f && firesea == i) {
      this->addSprite("assets/Fire9.tga");
      firesea = j;
      cout << firesea;
      fireseatimer = 0;
    }

  if (fireseatimer >= 0.1f && firesea == j) {
      this->addSprite("assets/Fire10.tga");
      firesea = k;
      cout << firesea;
      fireseatimer = 0;
    }
  if (fireseatimer >= 0.1f && firesea == k) {
      this->addSprite("assets/Fire11.tga");
      firesea = l;
      cout << firesea;
      fireseatimer = 0;
    }

  if (fireseatimer >= 0.1f && firesea == l) {
      this->addSprite("assets/Fire11.tga");
      firesea = a;
      cout << firesea;
      fireseatimer = 0;
    }
}
