/**
 * This class describes VuurZee behavior.
 * Copyright 2016 Erik Luttmer <erik210@live.nl>
 */
#include <time.h>
#include <fstream>
#include <sstream>
#include "spacetrash.h"
#include "vector"
using namespace std;

SpaceTrash::SpaceTrash() : Entity()
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
  m = 13;
  n = 14;
  o = 15;
  p = 16;

  spacetrash = a;
  spacetrashtimer = 0;
}

SpaceTrash::~SpaceTrash()
{

}

void SpaceTrash::update(float deltaTime)
{
  // ###############################################################
  // SpaceTrash Animation
  // ###############################################################
  spacetrashtimer += deltaTime;
  aniTimer = 0.05f;

  if (spacetrash == a) {
      this->addSprite("assets/spacetrasha.tga");
      cout << spacetrash;
      spacetrash = b;
      spacetrashtimer = 0;
    }

  if (spacetrashtimer >= aniTimer && spacetrash == b) {
      this->addSprite("assets/spacetrasha2.tga");
      spacetrash = c;
      cout << spacetrash;
      spacetrashtimer = 0;
    }

  if (spacetrashtimer >= aniTimer && spacetrash == c) {
      this->addSprite("assets/spacetrasha.3tga");
      spacetrash = d;
      cout << spacetrash;
      spacetrashtimer = 0;
    }

  if (spacetrashtimer >= aniTimer && spacetrash == d) {
      this->addSprite("assets/spacetrasha4.tga");
      spacetrash = e;
      cout << spacetrash;
      spacetrashtimer = 0;
    }

  if (spacetrashtimer >= aniTimer && spacetrash == e) {
      this->addSprite("assets/spacetrasha5.tga");
      spacetrash = f;
      cout << spacetrash;
      spacetrashtimer = 0;
    }


  if (spacetrashtimer >= aniTimer && spacetrash == f) {
      this->addSprite("assets/spacetrasha6.tga");
      spacetrash = g;
      cout << spacetrash;
      spacetrashtimer = 0;
    }

  if (spacetrashtimer >= aniTimer && spacetrash == g) {
      this->addSprite("assets/spacetrasha7.tga");
      spacetrash = h;
      cout << spacetrash;
      spacetrashtimer = 0;
    }

  if (spacetrashtimer >= aniTimer && spacetrash == h) {
      this->addSprite("assets/spacetrasha8.tga");
      spacetrash = i;
      cout << spacetrash;
      spacetrashtimer = 0;
    }

  if (spacetrashtimer >= aniTimer && spacetrash == i) {
      this->addSprite("assets/spacetrasha9.tga");
      spacetrash = j;
      cout << spacetrash;
      spacetrashtimer = 0;
    }

  if (spacetrashtimer >= aniTimer && spacetrash == j) {
      this->addSprite("assets/spacetrasha10.tga");
      spacetrash = k;
      cout << spacetrash;
      spacetrashtimer = 0;
    }
  if (spacetrashtimer >= aniTimer && spacetrash == k) {
      this->addSprite("assets/spacetrasha11.tga");
      spacetrash = l;
      cout << spacetrash;
      spacetrashtimer = 0;
    }

  if (spacetrashtimer >= aniTimer && spacetrash == l) {
      this->addSprite("assets/spacetrasha12.tga");
      spacetrash = m;
      cout << spacetrash;
      spacetrashtimer = 0;
    }

  if (spacetrashtimer >= aniTimer && spacetrash == m) {
      this->addSprite("assets/spacetrasha13.tga");
      spacetrash = n;
      cout << spacetrash;
      spacetrashtimer = 0;
    }

  if (spacetrashtimer >= aniTimer && spacetrash == n) {
      this->addSprite("assets/spacetrasha14.tga");
      spacetrash = o;
      cout << spacetrash;
      spacetrashtimer = 0;
    }

  if (spacetrashtimer >= aniTimer && spacetrash == o) {
      this->addSprite("assets/spacetrasha15.tga");
      spacetrash = a;
      cout << spacetrash;
      spacetrashtimer = 0;
    }


  if (spacetrashtimer >= aniTimer && spacetrash == p) {
      this->addSprite("assets/spacetrasha16.tga");
      spacetrash = a;
      cout << spacetrash;
      spacetrashtimer = 0;
    }


}
