#pragma once

// Ryan Hackabrt - CSCN7130_Section2_Group3 - Enemy MOB ADT

#include <stdio.h>
#include <stdbool.h>
#include "PlayerCharacter.h"

#define STATS_ARRAY		6
#define ENEMY_TYPES		2
#define MAX_NAME		15

typedef enum boss { FIN = 0, THIEF = 1 }BOSS;

typedef struct enemy {
	char name[MAX_NAME];	// Boss Bunny, thief
	BOSS type;
	int stats[STATS_ARRAY];		// stored in order: Health, Energy (mana), Str, Int, Defence, Speed

}MOB, * _MOB;

// enemy creation Creation
MOB setEnemy(BOSS c);

// Updating stats
MOB updateStatsMOB(MOB enemy, int arr[]);

// Combat Movesets
int SelectMOBMoveset(MOB enemy, int combatRound); 
int thiefMoveset(int combatRound);
int FinalBossMoveset(int combatRound);

int MovesetDamageMOB(MOB enemy, int defense, int attack);
int thiefAtkkDmg(MOB enemy, int attack, int defense); 
int finalBossAtkDmg(MOB enemy, int attack, int defense);
