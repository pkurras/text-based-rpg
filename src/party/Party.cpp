#include "party.h"

Party::Party() {};

vector<Character*> Party::getParty() const { return party; }

Character* Party::operator[](int index) const {
    return party[index];
}

size_t Party::getPartySize() const { return party.size(); }

void Party::printMemberNames() const {
    cout << " | ";
    for (int i = 0; i < party.size(); i++) {
        cout << party[i]->getName() << " | ";
    }
}

void Party::insertMember(Character* member) {
    party.emplace_back(member);
}

void Party::removeMember(int index) {
    party.erase(party.begin() + index);
}