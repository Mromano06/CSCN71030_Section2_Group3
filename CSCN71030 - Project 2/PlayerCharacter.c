// Ryan Hackabrt - CSCN7130_Section2_Group3 - PlayerCharacter Implementation

#define _CRT_SECURE_NO_WARNINGS

#include "PlayerCharacter.h"
#include <stdio.h>


// Character Selection Menu
int CharacterSelectMenu() {	//TODO: UPDATE Visuals
	int selection = 0;
	printf("Please Pick a Character\n");
	printf("\nROGUE = 1\n\nWARRIOR = 2\n\nMAGE = 3\n\nEXIT TO MAIN MENU = 0\n");
	do {
		printf("SELECTION: ");
		scanf("%d", &selection);
		if (selection > 3 || selection < 0)								// input validation
			printf("\n\nINVALID INPUT, PLEASE ENTER NEW ");
	} while (selection > 3 || selection < 0);

	selection--;	//just to make enums and switch case easier to read, not necessary
	
	return selection;
}

// Character Creation

PC SetCharacter(int c) {
	PC newChar = { 0 };
	int Classes[PLAYER_CLASSES][STATS_ARRAY] = { { 75, 50, 15, 10, 10, 20 }, { 75, 50, 15, 10, 10, 20 }, { 75, 50, 15, 10, 10, 20 } };


	switch (c) {
	case ROG:
		strncpy(newChar.name, "Rogue", MAX_NAME);	//TODO: Not finished
		newChar.charclass = ROG;
		return updateStats(newChar, Classes[c]);
		//return newChar;
	case WAR:
		strncpy(newChar.name, "Warrior", MAX_NAME);
		newChar.charclass = WAR; 
		return updateStats(newChar, Classes[c]);
		//return newChar;
	case MAG:
		strncpy(newChar.name, "Mage", MAX_NAME);
		newChar.charclass = MAG; 
		return updateStats(newChar, Classes[c]);
		//return newChar;
	}
	return newChar;
}

// Updating stats
PC updateStats(PC player, int arr[]) {
	for (int i = 0; i < STATS_ARRAY; i++) {
		player.stats[i] = arr[i];
	}
	return player;
}
bool TakeDamage(int dmg) {
	return true;
}

// Combat Movesets


//Save/Load to/from file
