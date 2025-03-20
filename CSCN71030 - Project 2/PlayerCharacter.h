#pragma once

// Ryan Hackabrt - CSCN7130_Section2_Group3 - ADT for Playable Character

#include <stdio.h>
#include <stdbool.h>
#include "enemy.h"
#define STATS_ARRAY		6
#define PLAYER_CLASSES	3
#define MAX_NAME		7

typedef enum type{ROG = 0, WAR = 1, MAG = 2}TYPE;
typedef enum stat { HP = 0, MP = 1, STR = 2, INT = 3, DEF = 4, SPD = 5 }STAT;

typedef struct PlayerCharacter {
	char name[MAX_NAME];	// Warrior, Rogue, or Mage
	TYPE charclass;
	int stats[STATS_ARRAY];		// stored in order: Health, Energy (mana), Str, Int, Defence, Speed
}PC, * _PC;

// Character Selection Menu
PC characterSelectMenu();

// Character Creation

PC setCharacter(int c);

// Updating stats


PC updateStatsPC(PC player, int arr[]);
PC increaseStatPC(PC player, STAT type, int mod);


// Combat Movesets
int SelectPlayerMoveset(PC player);
int rogueMovesetMenu();
int warriorMovesetMenu();
int mageMovesetMenu();

int MovesetDamagePC(PC player, int defense, int attackPC);
int rogueAtkkDmg(PC player, int attack, int defense);
int warriorAtkDmg(PC player, int attack, int defense);
int mageAtkDmg(PC player, int attack, int defense);



//Other
void printCharacter(PC player);



