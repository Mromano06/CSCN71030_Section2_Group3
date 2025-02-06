#pragma once
#define MAXPROBILITY 100
#define DEFAULTMISS 10
#define PHYSICALHITCOEFFICIENT 10

// Ryan Hackabrt - CSCN7130_Section2_Group3 - RNG Events ADT

// srand(time(NULL));	Must be input once game is started for RNG to work properly (otherwise will be the same set of numbers)

#include <stdlib.h>
#include <time.h>

// random number generator function
int RNG(int maxVal, int mod);

// The miss of the physical attack and the magic attack
bool attackHitCheck(int speed);
bool magicHitCheck(int magichit);

// Damage of attack will be fixed.
int damageOfAttack(int strength, int defense);
int damageOfMagic(int intelligence);