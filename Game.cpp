/*******************************************************************************
** Author: Patrick Armitage
** Date: 02/10/2016
** Description: Display fucntions file which defines the functions that were
** prototyped within the Display header file
*******************************************************************************/

#include <iostream>
#include <string>
#include "Creature.hpp"
#include "Barbarian.hpp"
#include "Bluemen.hpp"
#include "Harrypotter.hpp"
#include "Medusa.hpp"
#include "Vampire.hpp"

using std::string;
using std::cout;
using std::cin;
using std::endl;

/*----------------------------------------------------------------------------*/
/*
    Function Name: getCreatureString
    Function Parameters: CREATURES enum list item
    What the function does: takes a creature type from CREATURES enum list,
                            and depending on the type of creature, returns the
                            appropriate string name of that creature type
*/
string getCreatureString(CREATURES creatureType) {
    switch (creatureType) {
    case BARBARIAN :
        return "Barbarian";
    case BLUEMEN :
        return "Blue Men";
    case HARRYPOTTER :
        return "Harry Potter";
    case MEDUSA :
        return "Medusa";
    case VAMPIRE :
        return "Vampire";
    }
}

/*----------------------------------------------------------------------------*/
/*
    Function Name: initializeCreature
    Function Parameters: CREATURES enum creature type, creature name string
    What the function does: takes a creature type and creature name string,
                            and depending on the creature type, initializes
                            a new creature of the appropriate creature type
                            subclass and returns a pointer to the new creature
*/
Creature *initializeCreature(CREATURES creatureType, string creatureName) {
    Creature *creature;

    switch (creatureType) {
    case BARBARIAN :
        creature = new Barbarian(creatureName);
        return creature;
    case BLUEMEN :
        creature = new Bluemen(creatureName);
        return creature;
    case HARRYPOTTER :
        creature = new Harrypotter(creatureName);
        return creature;
    case MEDUSA :
        creature = new Medusa(creatureName);
        return creature;
    case VAMPIRE :
        creature = new Vampire(creatureName);
        return creature;
    }
}

/*----------------------------------------------------------------------------*/
/*
    Function Name: playRound
    Function Parameters: two Creature subclasses who will fight each other
    What the function does: alternately has the two creatures attack and defend
                            from one another, decrementing their strength pts
                            based on damage done, and handling special cases
                            where attack may be 0 (when Vampire charms opponent)
                            or where it may be 99 (when Medusa glares), then
                            finally sets the stillAlive creature bool if either
                            creatures dies in combat
*/
void playRound(Creature *player1, Creature *player2) {
    int attack, defense, points1, points2;
    string player1Name = player1->getCreatureName();
    string player2Name = player2->getCreatureName();

    cout << player1Name << " just attacked " << player2Name << "!" << endl;
    attack = player1->tryAttack(player1, player2);
    usleep(100000);
    // first handle the Medusa edge case where she may glare (attack == 99)
    if (attack == 99) {
        cout << player1Name << " just turned " << player2Name << " into stone!!!" << endl;
        usleep(2000000);
        player2->setStrengthPts(0);
        player2->setStillAlive(false);
        return;
    // there is another edge case where Vampire charms and attack == 0,
    // in which case we skip over the defense and updateStrengthPts entirely
    } else if (attack > 0) {
        cout << player1Name << " struck with " << attack << " damage points!" << endl;
        usleep(100000);
        defense = player2->defend();
        cout << player2Name << " blocked with a defense of " << defense << "!" << endl;
        usleep(100000);
        player2->updateStrengthPts(defense, attack);
    }
    points2 = player2->getStrengthPts();
    cout << player2Name << " has " << points2 << " strength points left!" << endl;

    if (points2 == 0) {
        player2->setStillAlive(false);
        cout << player2Name << " got struck down!" << endl;
        return;
    }

    cout << endl;
    usleep(300000);

    // we now have an "alternate attack" section where player2 does the same to player1
    cout << player2Name << " attacked back at " << player1Name << "!" << endl;
    attack = player2->tryAttack(player2, player1);

    if (attack == 99) {
        cout << player2Name << " just turned " << player1Name << " into stone!!!" << endl;
        usleep(2000000);
        player1->setStrengthPts(0);
        player1->setStillAlive(false);
        return;
    } else if (attack > 0) {
        usleep(100000);
        cout << player2Name << " struck with " << attack << " damage points!" << endl;
        usleep(100000);
        defense = player1->defend();
        cout << player1Name << " blocked with a defense of " << defense << "!" << endl;
        usleep(100000);
        player1->updateStrengthPts(defense, attack);
    }
    points1 = player1->getStrengthPts();
    cout << player1Name << " has " << points1 << " strength points left!" << endl;

    if (points1 == 0) {
        player1->setStillAlive(false);
        cout << player1Name << " got struck down!" << endl;
    }
}

/*----------------------------------------------------------------------------*/
/*
    Function Name: printTitle
    Function Parameters: string name of each creature in the contest
    What the function does: using the two provided creature name strings, prints
                            a customized match title with borders declaring
                            which creatures will be contending in the match
*/
void printTitle(string name1, string name2) {
    string titleString = "TITLE MATCH: " + name1 + " vs. " + name2;
    int len = titleString.length();
    for (int i = 0; i < len; i++) {
        cout << "=";
    }
    cout << endl;
    cout << titleString << endl;
    for (int i = 0; i < len; i++) {
        cout << "=";
    }
    cout << endl;
}

/*----------------------------------------------------------------------------*/
/*
    Function Name: closeGame
    Function Parameters: N/A
    What the function does: prints a parting message to the user, along with a
                            (very) fancy ASCII art emblem borrowed ;) off the
                            internet!
*/
void closeGame() {
// ASCII art for Emblem borrowed from joan g stark, who gets all the props :)
// See http://www.retrojunkie.com/asciiart/weapons/swords.htm
    usleep(800000);
    cout << endl << "See you next time in FANTASY COMBAT" << endl << endl;

    cout << "   |\\                     /) " << endl;
    cout << " /\\_\\\\__               (_//" << endl;
    cout << "|   `>\\-`     _._       //`) " << endl;
    cout << " \\ /` \\\\  _.-`:::`-._  //  " << endl;
    cout << "  `    \\|`    :::    `|/     " << endl;
    cout << "        |     :::     |       " << endl;
    cout << "        |.....:::.....|       " << endl;
    cout << "        |:::::::::::::|       " << endl;
    cout << "        |     :::     |       " << endl;
    cout << "        \\     :::     /      " << endl;
    cout << "         \\    :::    /       " << endl;
    cout << "          `-. ::: .-'         " << endl;
    cout << "           //`:::`\\\\        " << endl;
    cout << "          //   '   \\\\       " << endl;
    cout << "         |/         \\\\      " << endl;
}
