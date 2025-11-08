#include "Combat.h"
#include <cstdlib>


// constructor
Combat::Combat(vector<Character*> player, vector<Character*> enemy)
    : playerParty(player), enemyParty(enemy), turnCount(1) {}

// print info
void Combat::printTurn() const {
    cout << "===== Turn: " << turnCount << " =====\n";
}

void Combat::endInfo(vector<Character*> winners,vector<Character*> losers) const {
    // cout << losers->getName() << " HAS FALLEN!" << endl;
    cout << "====================================" << endl;
    cout << "BATTLE HAS ENDED!" << endl;
    cout << "WINNERS: " << winners->getName() << endl;
    cout << "====================================" << endl << endl;

    // TODO - Print XP, LVL, etc. 

}

void Combat::battleStart() const {
    cout << "====================================" << endl;
    cout << "BATTLE HAS BEGUN!" << endl;
    cout << player->getName() << " VS " << enemy->getName() << endl;
    cout << "====================================" << endl << endl;
}

// player turn
Skill* Combat::playerChoice(Character* partyCharacter) {
    // temp variable for vector or skills
    vector<Skill*> skillList = partyCharacter->getSkills();
    Skill* pickedSkill;

    // prompt for player's choice
    while(true) {
        // print player's turn
        cout << partyCharacter->getName() << "'s Turn:\n";

        // print out useable skills
        partyCharacter->printSkills();

        // get player choice
        int choice;

        if (choice > 0 && choice <= skillList.size()) { // valid choice | return picked skill
            pickedSkill = skillList[choice - 1]; // offset by 1

            if(pickedSkill->canUse(partyCharacter)) return pickedSkill;
            else { pickedSkill->cantUse(partyCharacter); }
        }
        else { cout << "Invalid Option.\n"; }
    }
}

// enemy turn
Skill* Combat::enemyChoice(Character* partyCharacter) {
    vector<Skill*> skillList = partyCharacter->getSkills();
    Skill* pickedSkill;

    // TODO - Make better (more sophisticated)
    while(true) {
        int choice = (1 + rand() % 100) * skillList.size() / 100; // generate choice randomly
        pickedSkill = skillList[choice];
        if(pickedSkill->canUse(partyCharacter)) return pickedSkill;
    }
}

// combat loop
bool Combat::combatLoop() {
    Character* winner;
    Character* loser;

    battleStart();

    player->printInfo();
    enemy->printInfo();

    while(player->getIsAlive() && enemy->getIsAlive()) {
        printTurn();
        
        
    }


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