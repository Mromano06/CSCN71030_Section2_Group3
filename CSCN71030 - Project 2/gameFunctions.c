#define _CRT_SECURE_NO_WARNINGS
#include "gameFunctions.h"
#include "PlayerCharacter.h"
#include "Storyline.h"
#include <stdio.h>
#include <stdlib.h>

// Matthew Romano - CSCN71030_Section2_Group3 - Game Functions Implementation
// A bunch of useful functions needed in multipule places



// same as the save game but used specifically for new game creat
bool newGame() {
	FILE* newGameFile;							// creates new file pointer

	newGameFile = fopen("SaveGame.txt", "w");
	if (newGameFile == NULL) {					// checking for null
		printf("ERROR OVERWRITING FILE");
		return false;
	}

	return true;
}

// saves the player stats to the file
bool saveGame(PC* toSave) {
	FILE* newGameFile;							// creates new file pointer

	newGameFile = fopen("SaveGame.txt", "w");
	if (newGameFile == NULL) {					// checking for null
		printf("ERROR OPENING FILE");
		exit(EXIT_FAILURE);
        return false;
	}
	fprintf(newGameFile, "%s, ", toSave->name);

	fprintf(newGameFile, "%d, ", toSave->stats[0]);
	fprintf(newGameFile, "%d, ", toSave->stats[1]);
	fprintf(newGameFile, "%d, ", toSave->stats[2]);
	fprintf(newGameFile, "%d, ", toSave->stats[3]);
	fprintf(newGameFile, "%d, ", toSave->stats[4]);
	fprintf(newGameFile, "%d, ", toSave->stats[5]);
	fprintf(newGameFile, "%d", checkPoint(0));       // hopefully this works

	// character stats obv but how is the more important part

	fclose(newGameFile);
	// this isnt a final point, can return to the game after

    return true;
}

// this function checks for file to load
PC loadGame() {
    FILE* loadGameFile;                      // Creates new file
    PC player;
    char line[200];                          // Buffer to store each line from the file
    char tempName[MAX_NAME];
    int health = 0, mana = 0, str = 0,
        itl = 0, def = 0, speed = 0;

    loadGameFile = fopen("SaveGame.txt", "r");
    if (loadGameFile == NULL) {               // Checking for null
        printf("EXISTING FILE NOT FOUND");
        exit(EXIT_FAILURE);
    }

    // Read each line from the file
    while (fgets(line, sizeof(line), loadGameFile)) {
        // Use sscanf to parse the line into the variables
        if (sscanf(line, "%49[^,], %d, %d, %d, %d, %d, %d", tempName,
            &health, &mana, &str, &itl, &def, &speed) == 7) {

            // Copy the name into the player struct
            strncpy(player.name, tempName, MAX_NAME);
            // Store the stats in the player struct
            player.stats[0] = health;
            player.stats[1] = mana;
            player.stats[2] = str;
            player.stats[3] = itl;
            player.stats[4] = def;
            player.stats[5] = speed;
            
        }
    }

    fclose(loadGameFile);

    return player;
}