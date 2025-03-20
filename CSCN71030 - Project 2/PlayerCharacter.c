// Ryan Hackabrt - CSCN7130_Section2_Group3 - PlayerCharacter Implementation

#define _CRT_SECURE_NO_WARNINGS
#include "PlayerCharacter.h"
#include "enemy.h"
#include <stdio.h>
#include <stdbool.h>


// Character Selection Menu
PC characterSelectMenu() {	//TODO: UPDATE Visuals
	int selection = 0;
	printf("\nPlease Pick a Character\n");
	printf("Rogue:			Warrior:			Mage:\n");
	printf("HP:	75		HP:	100			HP:	50\n");
	printf("MP:	50		MP:	25			MP:	100\n");
	printf("STR:	15		STR:	20			STR:	10\n");
	printf("INT:	10		INT:	5			INT:	20\n");
	printf("DEF:	10		DEF:	15			DEF:	10\n");
	printf("SPD:	20		SPD:	5			SPD:	5\n");
	printf("\n1 FOR ROGUE		2 FOR WARRIOR			3 FOR MAGE\n\n");
	do {
		printf("SELECTION: ");
		scanf("%d", &selection);
		if (selection > 3 || selection < 0)								// input validation
			printf("\n\nINVALID INPUT, PLEASE ENTER NEW ");
	} while (selection > 3 || selection < 0);

	selection--;	//just to make enums and switch case easier to read, not necessary
	
	return setCharacter(selection);
}

// Character Creation

PC setCharacter(int c) {
	PC newChar = { 0 };
	int Classes[PLAYER_CLASSES][STATS_ARRAY] = { { 75, 50, 15, 10, 10, 20 }, 
		{ 100, 25, 20, 5, 15, 5 }, { 50, 100, 10, 20, 10, 5 } };
	//Stats Order:		ROG		WAR		MAG	
	//	Health			75,		100,	50
	//	Mana			50,		25,		100
	//	Strength		15,		20,		10
	//	Intelligence	10,		5,		20
	//  Defence			10,		15,		10
	//	Speed			20,		5,		5
		
	switch (c) {
	case ROG:
		strncpy(newChar.name, "Rogue", MAX_NAME);	
		newChar.charclass = ROG;
		return updateStatsPC(newChar, Classes[c]);
		//return newChar;
	case WAR:
		strncpy(newChar.name, "Warrior", MAX_NAME);
		newChar.charclass = WAR; 
		return updateStatsPC(newChar, Classes[c]);
		//return newChar;
	case MAG:
		strncpy(newChar.name, "Mage", MAX_NAME);
		newChar.charclass = MAG; 
		return updateStatsPC(newChar, Classes[c]);
		//return newChar;
	}
	return newChar;
}



// Updating stats

//resets stats to values in an array
PC updateStatsPC(PC player, int arr[]) {
	for (int i = 0; i < STATS_ARRAY; i++) {
		player.stats[i] = arr[i];
	}
	return player;
}


//Update stat function to increase/decrease individual stats easily
PC increaseStatPC(PC player, STAT type, int mod) {
	player.stats[type] = player.stats[type] + mod;
	return player;
}



// Combat Integration

//Moveset Menus
int SelectPlayerMoveset(PC player) {
	printf("Please Select an Attack Type:\n");
	switch (player.charclass){
	case ROG:
		return rogueMovesetMenu();
	case WAR:
		return warriorMovesetMenu();
	case MAG:
		return mageMovesetMenu();
	}
}
int rogueMovesetMenu() {	//TODO: ask for user input
	printf("1 = Basic Attack, etc...\n");
	return 1;
}
int warriorMovesetMenu() {
	printf("1 = Basic Attack, etc...\n");
	return 1;
}
int mageMovesetMenu() {
	printf("1 = Basic Attack, etc...\n");
	return 1;
}

//Moveset Damage Calculations
int MovesetDamagePC(PC player, int defense, int attack) {
	switch (player.charclass) {
	case ROG:
		return rogueAtkkDmg(player, attack, defense);
	case WAR:
		return warriorAtkDmg(player, attack, defense);
	case MAG:
		return mageAtkDmg(player, attack, defense);
	}
}
int rogueAtkkDmg(PC player, int attack, int defense) {	//TODO: Implement more attacks, and crit chance
	int damage = 0;
	int critMod = 1;
	switch (attack) {

	case 1: // basic attack (stab)
		damage = (player.stats[STR] - defense) * critMod;
		return damage;
	}
}
int warriorAtkDmg(PC player, int attack, int defense) {	//TODO: Implement more attacks, and crit chance
	int damage = 0;
	int critMod = 1;
	switch (attack) {


	case 1: // basic attack (slash)
		damage = (player.stats[STR] - defense) * critMod;
		return damage;
	}
}
int mageAtkDmg(PC player, int attack, int defense) {	//TODO: Implement more attacks, and crit chance
	int damage = 0;
	int critMod = 1;
	switch (attack) {

	case 1: // basic attack = (Magic Missile)
		damage = (player.stats[INT] - (defense/2)) * critMod;
		return damage;
	}
}



//Other

//Display Current Character Stats on Screen
void printCharacter(PC player) {	
	printf("\n%s\n", player.name);
	printf("Hp:	%d\nMp:	%d\nStr:	%d\nInt:	%d\nDef:	%d\nSpd:	%d\n",
		player.stats[0], player.stats[1], player.stats[2], player.stats[3], player.stats[4], player.stats[5]);
}
