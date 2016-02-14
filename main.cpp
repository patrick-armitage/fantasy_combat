#include <iostream>
#include <string>

#include "Creature.hpp"
#include "Game.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {
    /* Initialize empty config vars */
    Creature *fighter1, *fighter2;
    CREATURES creature1, creature2;
    string creatureName1, creatureName2;
    int sel1, sel2;

    /* Game intro */
    cout << "Welcome to Fantasy Combat!" << endl << endl;

    /* Get Fighter 1 */
    cout << "Please select type for first creature: " << endl;
    cout << "[0] Barbarian, [1] Blue Men, [2] Harry Potter, [3] Medusa, [4] Vampire" << endl;
    cin >> sel1;
    creature1 = static_cast<CREATURES>(sel1);
    creatureName1 = getCreatureString(creature1);
    cout << "For our first combatant, " << creatureName1 << "!" << endl << endl;

    /* Get Fighter 2 */
    cout << "Please select type for second creature: " << endl;
    cout << "[0] Barbarian, [1] Blue Men, [2] Harry Potter, [3] Medusa, [4] Vampire" << endl;
    cin >> sel2;
    creature2 = static_cast<CREATURES>(sel2);
    creatureName2 = getCreatureString(creature2);
    cout << "For our second combatant, " << creatureName2 << "!" << endl << endl;

    usleep(800000);

    /* Initialize fighters, control vars for game loop */
    int numRounds = 1;
    if (creature1 == creature2) {
        creatureName1 = creatureName1 + " 1";
        creatureName2 = creatureName2 + " 2";
    }
    fighter1 = initializeCreature(creature1, creatureName1);
    fighter2 = initializeCreature(creature2, creatureName2);
    bool fighter1StillAlive = true, fighter2StillAlive = true;

    printTitle(creatureName1, creatureName2);
    cout << endl << "Let's fight!  Hit enter after each round to keep fighting!" << endl << endl;
    usleep(800000);

    /* Game Loop */
    while ((fighter1StillAlive == true) && (fighter2StillAlive == true)) {
        cin.ignore();
        cout << "Round " << numRounds << ", fight!" << endl;
        playRound(fighter1, fighter2);

        fighter1StillAlive = fighter1->getStillAlive();
        fighter2StillAlive = fighter2->getStillAlive();
        numRounds++;
    }

    /* Loop has been exited because 1 figher died.  Game over! */
    cout << endl << "That's game over, folks!  Thanks for playing!" << endl;
    closeGame();
    return 0;
}
