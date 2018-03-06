/********************************************************************************************
** Program Name: Lab3 (Inheritance)
** Author: Jeremy Einhorn
** Date: July 13, 2017
** Description: This is the implementation file for the class LoadedDie. It constructs a 
LoadedDie with the number of sides the user specified and sets the loaded side to number of sides.  
The roll will return that loaded side more often.
*********************************************************************************************/

#include"LoadedDie.hpp"
#include<cstdlib>
#include<ctime>

//constructor created a LoadedDie with the sies entered by the user
//the loadedSide will always be the number of sides
//because in reality, a player would use a loaded die
//that will hopefully land on the higest number
//possible in order to beat the other player
LoadedDie::LoadedDie(int sides) : Die(sides)
{
	this->N = sides;
	this->loadedSide = sides;
}

//a random number is generated from 0 to 1.  if that number is a 1
//the loadedside will be returned.  This means that the loaded side will
//be returned 50% of the time, which means it is in fact loaded.
//if a 0 is generated, the LoadedDie were to roll as if it were regular
//meaning that it still can return the loaded side, but it much more fair
//that the loaded sides get returned too.
int LoadedDie::rollDie()
{
	//generates a 0 or 1
	int odds = rand() % 2;

	if (odds == 1)
		return this->loadedSide;

	//it rolls like a normal die, meaning the odds are all evened out
	//this will execute half of the time, the other half the loaded side
	//will be returned
	else
		return Die::rollDie();
}