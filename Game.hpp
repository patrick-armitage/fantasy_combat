/*******************************************************************************
** Author: Patrick Armitage
** Date: 02/10/2016
** Description: Game function prototypes, used as utility methods and called
** directly within main.cpp, they include getCreatureString and
** initializeCreature for deciding which subclass to use, and printTitle,
** playRound and closeGame to control the flow of the game
*******************************************************************************/

#include <string>
#include "Creature.hpp"

#ifndef GAME_HPP
#define GAME_HPP

using std::string;

string getCreatureString(CREATURES creatureType);
Creature *initializeCreature(CREATURES creatureType, string creatureName);
void playRound(Creature *player1, Creature *player2);
void printTitle(string name1, string name2);
void closeGame();

#endif
