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
			//deal damage
			enemyHP = enemyHP - damagePC; //this replaced takeDamage()
			if ( enemyHP <= 0)
				return VICTORY;
		}

		//enemy moves second
		if (hitCheckMOB(enemy)) {
			//roll for damage
			int damageMOB = MovesetDamageMOB(enemy, player.stats[DEF], attackMOB);
			//deal damage
			if (takeDamagePC(&playerHP, damageMOB) = 0)
				return LOSER;
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
		printf("%s attack the %s, deal %d damage£¡\n", first->name, second->name, (first->stats[2] - second->stats[4]));
		second->stats[0] -= (first->stats[2] - second->stats[4]);
		if (second->stats[0] <= 0) {
			printf("%s was defeated!\n", second->name);
			return;
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
			return false;
		}
	case WAR:
		hit = player.stats[5] / 10 + RNG(100, 1);
		if (hit > 10) {
			return true;
		}
		else {
			return false;
		}
	case MAG:
		hit = 1 + RNG(100, 1);
		if (hit > 10) {
			return true;
		}
		else {
			return false;
		}
		default:
	break;
	}
}
