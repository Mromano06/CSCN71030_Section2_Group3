#pragma once
#include <stdio.h>
#include "Windows.h" 
#include "gameFunctions.h"

void storyBegins();
void storyBeginsAgain();
void actOne();
void actTwo();
void actThree();
void finalBoss();
int checkPoint(int newCheckpoint);
int getUserChoice(int min, int max);
void handleRandomEvent(int numEvents);