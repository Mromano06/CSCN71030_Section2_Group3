#include "Storyline.h"

int checkPoint(int newCheckpoint){

    static int currentCheckPoint = 0;

    if(newCheckpoint > 0){
        currentCheckPoint = newCheckpoint;
    }

    return currentCheckPoint;
}


void storyBegins() {
    int userInput;
    checkPoint(1); //checkpoint
    printf("          # #### ####  \n");
    printf("       ### \\/#|### |/####\n");
    printf("      ##\\/#/\\||/##/_/##/_#\n");
    printf("    ### \\/###|/\\/ # ##_###\n");
    printf("  ##_\\_#\\_\\| #/###_/_####?#\n");
    printf(" ## #### #\\ #| /  #### ## / ##\n");
    printf("  __#_--###`  |{,###---###-~\n");
    printf("           \\}{{\n");
    printf("             }}{\n");
    printf("             }}{\n");
    printf("             {{}\n");
    printf("        , -=-~{ .-^- _\n");
    Sleep(1000);
    printf("You wake up in the middle of the woods, with your head pounding.\n");
    Sleep(2000);
    printf("The damp earth clings to your clothes, and the scent of pine and decay lingers in the air.\n");
    Sleep(2000);
    printf("Shadows stretch between the trees as a cold breeze cuts through the silence.\n");
    Sleep(2000);
    printf("Your body aches, but nothing seems broken. Your weapons and supplies are gone, but your gear remains.\n");
    Sleep(2000);
    printf("It's as if someone wanted you alive, but defenseless...\n");
    Sleep(2000);
    printf("You have no memory of how you got here. \n");
    Sleep(2000);
    printf("Through the trees to your right, you see the distant glow of lanterns.\n");
    Sleep(2000);
    printf("It is a small village, quiet but eerily familiar.\n");
    Sleep(2000);
    printf("To your left, the woods grow darker and denser, the path uncertain.\n");
    Sleep(2000);
    printf("Which way do you go?\n");
    printf("(1) To the forest! or (2) To the Village: ");
    scanf_s("%d", &userInput);
    if (userInput == 1) {
        printf("No turning back now. Your adventure begins!\n ");
        return;
    }
    else {
        printf("The villagers recognize you the moment you step foot inside.\n");
        Sleep(2000);
        printf("Angry murmurs turn into shouts.\n");
        Sleep(2000);
        printf("Before you can react, fists and boots drive you back into the dirt.\n");
        Sleep(2000);
        printf("You wake up in the woods again, battered and bruised. (Lose -2 HP) \n");
        Sleep(3000);
        storyBeginsAgain();
    }
}
void storyBeginsAgain() {
    int userInput;
    checkPoint(100)//loop checkpoint
    printf("          # #### ####  \n");
    printf("       ### \\/#|### |/####\n");
    printf("      ##\\/#/\\||/##/_/##/_#\n");
    printf("    ### \\/###|/\\/ # ##_###\n");
    printf("  ##_\\_#\\_\\| #/###_/_####?#\n");
    printf(" ## #### #\\ #| /  #### ## / ##\n");
    printf("  __#_--###`  |{,###---###-~\n");
    printf("           \\}{{\n");
    printf("             }}{\n");
    printf("             }}{\n");
    printf("             {{}\n");
    printf("        , -=-~{ .-^- _\n");
    printf("You wake up in the middle of the woods, with your head pounding.\n");
    printf("The damp earth clings to your clothes, and the scent of pine and decay lingers in the air.\n");
    printf("Shadows stretch between the trees as a cold breeze cuts through the silence.\n");
    printf("Your body aches, but nothing seems broken. Your weapons and supplies are gone, but your gear remains.\n");
    printf("It's as if someone wanted you alive, but defenseless...\n");
    printf("You have no memory of how you got here. \n");
    printf("Through the trees to your right, you see the distant glow of lanterns.\n");
    printf("It is a small village, quiet but eerily familiar.\n");
    printf("To your left, the woods grow darker and denser, the path uncertain.\n");
    printf("Which way do you go?");
    printf("(1) To the forest! or (2) To the Village: ");
    scanf_s("%d", &userInput);
    if (userInput == 1) {
        printf("No turning back now. Your adventure begins!\n ");
        return;
    }
    else {
        printf("The villagers recognize you the moment you step foot inside.\n");
        printf("Angry murmurs turn into shouts.\n");
        Sleep(2000);
        printf("Before you can react, fists and boots drive you back into the dirt.\n");
        Sleep(2000);
        printf("You wake up in the woods again, battered and bruised. (Lose -2 HP) \n");//Need to add in function to remove health
        Sleep(3000);
        storyBeginsAgain();
    }
}

void actOne() {
    int userInput;
    checkPoint(2)
    printf("\nThe scent of damp earth and crushed leaves fills the air as you weave through the underbrush.\n");
    Sleep(2000);
    printf("Your hands stained with berry juice from picking the small red berries you find in the bushes.\n");
    Sleep(2000);
    printf("A cool breeze rustles the trees, whispering secrets you can't quite decipher.\n");
    Sleep(2000);
    printf("Up ahead, a small figure sits in the middle of the path. \n");
    Sleep(2000);
    printf("       __\n");
    printf("      / \\`\\         __\n");
    printf("     |  \\ `\\       /` /\\ \n");
    printf("      \\_/`\\  \\-\"\"-/`/\\  \\ \n");
    printf("           |       |  \\  | \n");
    printf("           (d     b)   \\_/\n");
    printf("           /       \\ \n");
    printf("      , -.|.'.\\_/.'.|.-,\n ");
    printf("     /   /\\' _|_ '/\\   \\ \n");
    printf("      |  /  '-`-`-'  \\  |\n");
    printf("      | |             | |\n");
    printf("      | \\    \\   /    / |\n");
    printf("       \\ \\    \\ /    / /\n");
    printf("        `-`\\   :   /'-'\n");
    printf("            `--`--`\n");
    Sleep(2000);
    printf("It's a bunny! White, small, fluffy, and sporting an adorable pair of droopy ears.\n");
    printf("It tilts its head at you, completely unbothered by your approach. \n");
    printf("You pause.What do you do ?\n");
    printf("(1) Offer the bunny a berry or (2) Kick the bunny out of your way: \n");
    scanf_s("%d", &userInput);
    if (userInput == 1) {
        checkPoint(4)
        printf("You crouch, extending a berry toward the tiny creature.\n");
        Sleep(2000);
        printf("The bunny sniffs, hesitates, then snatches it with a wiggle of its nose.\n");
        Sleep(2000);
        printf("Nothing happens except, now you know the berries aren't poisonous.\n");
        Sleep(2000);
        printf("A moment later, it hops off the path, disappearing into the underbrush. \n");
        Sleep(2000);
        printf("You shake your head, chuckling at the randomness of it all, and keep walking. \n");
        Sleep(2000);
        printf("The woods thicken,the path narrows and soon, a figure emerges from the shadows.\n");
        Sleep(2000);
        printf("A thief blocks your path, blade drawn. A fight? Just what you've been waiting for.\n");
        //insert fight function
        return;
    }
    else {
        checkPoint(99)
        printf("You're on an adventure, no time for distractions.\n");
        Sleep(2000);
        printf("Your foot swings forward but the moment your boot makes contact, the world shifts.\n");
        Sleep(2000);
        printf("The trees around you contort unnaturally, the air turns heavy.\n");
        Sleep(2000);
        printf("the once-innocent bunny erupts into a nightmarish form.\n");
        Sleep(2000);
        printf("Its fur blackens, its eyes glow with malice, and the air trembles with an ancient force now awake.\n");
        Sleep(2000);
        printf("Final Boss Fight Begins.\n");
        Sleep(2000);
        //insert final boss function
    }
    return;
}

void actTwo() {

}
void actThree() {

}
void finalBoss() {
checkPoint(101)
}