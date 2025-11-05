#include "Combat.h"
#include <cstdlib>


// constructor
Combat::Combat(Character* p,Character* e)
    : player(p), enemy(e), turnCount(1) {}

// print info
void Combat::printInfo() const {
    cout << "===== Turn: " << turnCount << " =====\n";
}

void Combat::endInfo(Character* w,Character* l) const {
    cout << l->getName() << " HAS FALLEN!" << endl;
    cout << "====================================" << endl;
    cout << "BATTLE HAS ENDED!" << endl;
    cout << "WINNER: " << w->getName() << endl;
    cout << "====================================" << endl << endl;

    // TODO - Print XP, LVL, etc. 

}

// player turn
Skill& Combat::playerChoice() {
    // temp variable for vector or skills
    vector<Skill*> skillList = player->getSkills();
    Skill* pickedSkill;

    // prompt for player's choice
    while(true) {
        // print player's turn
        cout << player->getName() << "'s Turn:\n";

        // print out useable skills
        player->printSkills();

        // get player choice
        int choice;

        if (choice > 0 && choice <= skillList.size()) { // valid choice | return picked skill
            pickedSkill = skillList[choice];
            return *pickedSkill;
        }

        cout << "Invalid Option.\n";
    }

    
    /*
    int choice;

    while(true) {
        cout << player->getName() << "'s turn:" << endl;
        cout << "1. Attack" << endl;
        cout << "2. Defend" << endl;

        cin >> choice;

        if(choice == 1) { return 1; }
        if(choice == 2) { player->defend(); return 2; }

        cout << "Invalid Option." << endl;
    }
    */
}

// enemy turn
Skill& Combat::enemyChoice() {

    // TODO

}

// combat loop
bool Combat::combatLoop() {
    Character* winner;
    Character* loser;

    cout << "====================================" << endl;
    cout << "BATTLE HAS BEGUN!" << endl;
    cout << player->getName() << " VS " << enemy->getName() << endl;
    cout << "====================================" << endl << endl;

    player->printInfo();
    enemy->printInfo();


    /*
    while(player->getIsAlive() && enemy->getIsAlive()) {
        printInfo();
        int playerChoice = playerChoice();
        int enemyChoice = enemyChoice();

        // if (playerChoice == 1) { player->attack(*enemy); }
        // if (enemyChoice == 1) { enemy->attack(*player); }

        player->reset();
        enemy->reset();
        turnCount++;
    }

    if (player->getIsAlive()) { 
        winner = player; 
        loser = enemy; 

        winner->canLevel(*loser);

        endInfo(player,enemy);
        return true; 
    }
    else { 
        winner = enemy; 
        loser = player; 
        endInfo(enemy,player);
        return false; 
    }
    */
}