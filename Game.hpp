/********************************************************************************************
** Program Name: Lab3 (Inheritance)
** Author: Jeremy Einhorn
** Date: July 13, 2017
** Description: This is the header file for the class Game.  Game handles asking the user
for the amount of sides and what type of dice they will be using.  Game also then creates
a pointer to a Die object, which can also be a LoadedDie due to inheritance.  These functions
are used in Game's play function.
*********************************************************************************************/

#ifndef GAME_HPP
#define GAME_HPP
#include"LoadedDie.hpp"
#include"input_validation.hpp"
#include"range_limit.hpp"
#include"menu.hpp"

class Game
{
private:

public:
	int askForSides(int);
	int askForDieType(int);
	Die* makeDie(int, int);
	void play();
};


#endif
