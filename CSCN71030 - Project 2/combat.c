// Ryan Hackabrt & Luis Changyuan Lu - CSCN7130_Section2_Group3 - Combat Module

#include <stdio.h>
#include "combat.h"

#define VICTORY 1
#define LOSER	2

int combatLoop(PC player, MOB enemy) {
	int combatRound = 1;
	int playerHP = player.stats[0];
	int enemyHP = enemy.stats[0];

	while () {
		//Moveset Selection
		int attackPC = SelectPlayerMoveset(player);
		int attackMOB = SelectMOBMoveset(enemy, combatRound);
		
		//Player Moves First
		if (hitCheckPC(player)) {
			//roll for damage
			int damagePC = MovesetDamagePC(player, enemy.stats[DEF], attackPC);
			printf("%s attack the %s, deal %d damage!\n", player.name, enemy.name, &damagePC);
			//deal damage
			enemyHP = enemyHP - damagePC; //this replaced takeDamage()
			if (enemyHP <= 0) {
				print("The %s was defeated!\n", enemy.name);
				return VICTORY;
			}
		}

		//enemy moves second
		if (hitCheckMOB(enemy)) {
			//roll for damage
			int damageMOB = MovesetDamageMOB(enemy, player.stats[DEF], attackMOB);
			printf("%s attack the %s, deal %d damage!\n", enemy.name, player.name,  &damageMOB);
			//deal damage
			playerHP = playerHP - damageMOB; //this replaced takeDamage()
			if (playerHP <= 0) {
				print("The %s was defeated!\n", player.name);
				return LOSER;
			}
		}

		//if you get here, there is no victor or loser yet
		combatRound++;
	}

}

void combat(PC* player, PC* monster) {
	//print opening info.
	printf("Combat Started! %s VS %s\n", player->name, monster->name);

	//order check
	PC* first;
	PC* second;
	if (player->stats[5] >= monster->stats[5]) {
		//Create two new structs to copy player and monster,and decide the order of attack.
		first = player;
		second = monster;
	}
	else {
		first = monster;
		second = player;
	}
	while (player->stats[0] > 0 && monster->stats[0] > 0) {
		// First attack
		if (hitcheckPC == true) {
			printf("%s attack the %s, deal %d damage£¡\n", first->name, second->name, (first->stats[2] - second->stats[4]));
			second->stats[0] -= (first->stats[2] - second->stats[4]);
			if (second->stats[0] <= 0) {
				printf("%s was defeated!\n", second->name);
				return;
			}
		}
		if (hitcheckPC == false) {
			printf("%s's attack was missed£¡\n", first->name);
		}

		// Second attack
		printf("%s attack the %s, deal %d damage£¡\n", second->name, first->name, (second->stats[2] - first->stats[4]));
		first->stats[0] -= (second->stats[2] - first->stats[4]);
		if (first->stats[0] <= 0) {
			printf("%s was defeated!\n", first->name);
			return;
		}
	}
}

bool hitcheckPC(PC player){
	int hit;
	switch (player.charclass)
	{
	case ROG:
		hit = player.stats[5] / 10 + RNG(100, 1);
		if (hit > 10) {
			return true;
		}
		else {
			printf("Attack missed!");
			return false;
		}
	case WAR:
		hit = player.stats[5] / 10 + RNG(100, 1);
		if (hit > 10) {
			return true;
		}
		else {
			printf("Attack missed!");
			return false;
		}
	case MAG:
		hit = 1 + RNG(100, 1);
		if (hit > 10) {
			return true;
		}
		else {
			printf("Attack missed!");
			return false;
		}
		default:
	break;
	}
}

bool hitCheckMOB(MOB enemy) {
	int hit = enemy.stats[SPD] / 10 + RNG(100, 1); //roll for hit
	if (hit > 10) {
		return true;
	}
	else {
		return false;
	}
}