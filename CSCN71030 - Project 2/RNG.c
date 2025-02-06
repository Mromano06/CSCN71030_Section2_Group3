// Ryan Hackabrt - CSCN7130_Section2_Group3 - RNG Events Implemetnation

#include "RNG.h"
#include <stdio.h>

#define ONE	1

// srand(time(NULL));	Must be input once game is started for RNG to work properly (otherwise will be the same set of numbers)


// this is the function to be used in any "random event" or "Dice Roll"
int RNG(int maxVal, int mod) {
	int val = rand() % (maxVal + ONE);
	return val + mod;
}

// Random number will be 0-100, default miss is 10, so the basic random number will have 90% bigger than 10,
// and if the random number is 1-10(10 numbers 10%), it would be a miss, speed increase the physical hit and
// magic hit(if exists) increase the magic hit.
// If function returns true, hit successed, and if it is false, hit missed.
bool attackHitCheck(int speed) {
	int hit = speed/PHYSICALHITCOEFFICIENT + rand() % (MAXPROBILITY + ONE);
	if (hit > DEFAULTMISS) {
		return true;
	}
	else{
		return false;
	}
}

bool magicHitCheck(int magichit) {
	int hit = magichit + rand() % (MAXPROBILITY + ONE);
	if (hit > DEFAULTMISS) {
		return true;
	}
	else {
		return false;
	}
}

// Physical damage equals strength minus defense, simple~
int damageOfAttack(int strength, int defense) {
	int damage = strength - defense;
	return damage;
}
// Should we design a magic defense number or not? If we do, it might be decrease the magic damage by percentage.
int damageOfMagic(int intelligence, int magicDefense) {
	int damage = intelligence * (MAXPROBILITY - magicDefense) / MAXPROBILITY;
	return damage;
}

int autoBattle(int playerHealth, int monsterHealth, int playerSpd, int monsterSpd, int playerStr, int playerInt, int playerDef, int playerMagicDef,
	int monsterStr, int monsterInt, int monsterDef, int monsterMagicDef) {
	// No need to check the speed because the auto battle option is based on player's turn.
	while (playerHealth > 0) {
		if (playerStr >= playerInt) {
			damageOfAttack(playerStr, monsterDef);
			monsterHealth = monsterHealth - damageOfAttack;
		}
		else {
			damageOfMagic(playerInt, monsterMagicDef);
			monsterHealth = monsterHealth - damageOfMagic;
		}
	}
	while (monsterHealth > 0) {
		if (monsterStr >= monsterInt) {
			damageOfAttack(monsterStr, playerDef);
			playerHealth = playerHealth - damageOfAttack;
		}
		else {
			damageOfMagic(monsterInt, playerMagicDef);
			playerHealth = playerHealth - damageOfMagic;
		}
	}
	printf("You are defeated.")
		return playerHealth;
}