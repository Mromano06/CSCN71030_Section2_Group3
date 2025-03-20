// Ryan Hackabrt - CSCN7130_Section2_Group3 - Enemy MOB Implementation

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include "enemy.h"
#include "PlayerCharacter.h"


// enemy creation Creation
MOB setEnemy(BOSS c) {		//these current stats are based on character stats since we do not have stats designed yet	TODO: Update stats to properly represent MOB stats
	MOB newMOB = { 0 };
	int Enemies[ENEMY_TYPES][STATS_ARRAY] = { { 75, 50, 15, 10, 10, 20 },
		{ 100, 25, 20, 5, 15, 5 } };
	//Stats Order:		THIEF	FIN			
	//	Health			75,		100
	//	Mana			50,		25
	//	Strength		15,		20
	//	Intelligence	10,		5
	//  Defence			10,		15
	//	Speed			20,		5

	switch (c) {
	case THIEF:
		strncpy(newMOB.name, "Thief", MAX_NAME);
		newMOB.type = ROG;
		return updateStatsMOB(newMOB, Enemies[c]);
	case FIN:
		strncpy(newMOB.name, "Boss Bunny", MAX_NAME);	//TODO: placeholder name
		newMOB.type = ROG;
		return updateStatsMOB(newMOB, Enemies[c]);
	}
	return newMOB;
}

// Updating stats
MOB updateStatsMOB(MOB enemy, int arr[]) {
	for (int i = 0; i < STATS_ARRAY; i++) {
		enemy.stats[i] = arr[i];
	}
	return enemy;
}


// Combat Integration

// Combat Movesets
int SelectMOBMoveset(MOB enemy, int combatRound) {
	switch (enemy.type) {
	case THIEF:
		return thiefMoveset(combatRound);
	case FIN:
		return FinalBossMoveset(combatRound);
	}
}
int thiefMoveset(int combatRound) {	
	return 1;
}
int FinalBossMoveset(int combatRound) {	//TODO: change this to randomize attacks depending on combat round (something big attack on round 3, and 6) when other attacks get implemented
	return 1;
}


//Moveset Damage Calculations
int MovesetDamageMOB(MOB enemy, int defense, int attack) {
	switch (enemy.type) {
	case ROG:
		return thiefAtkkDmg(enemy, attack, defense);
	case WAR:
		return finalBossAtkDmg(enemy, attack, defense);
	}
}
int thiefAtkkDmg(MOB enemy, int attack, int defense) {		//TODO: Implement more attacks, and crit chance
	int damage = 0;
	int critMod = 1;
	switch (attack) {

	case 1: // basic attack (stab)
		damage = (enemy.stats[STR] - defense) * critMod;
		return damage;
	}
}
int finalBossAtkDmg(MOB enemy, int attack, int defense) {	//TODO: Implement more attacks, and crit chance
	int damage = 0;
	int critMod = 1;
	switch (attack) {

	case 1: // basic attack (stab)
		damage = (enemy.stats[STR] - defense) * critMod;
		return damage;
	}
}
