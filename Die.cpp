/********************************************************************************************
** Program Name: Lab3 (Inheritance)
** Author: Jeremy Einhorn
** Date: July 13, 2017
** Description: This is the implementation file for the class Die.  It constructs a Die with
the number of sides specified by the user.  The only function in Die is to generate a random
number from 1 to the number of sides.
*********************************************************************************************/

#include"Die.hpp"
#include<ctime>
#include<cstdlib>


//Die constructor takes user specified number of sides
Die::Die(int sides)
{
	this->N = sides;
}

//a random number is generated from 1 to N, inclusive.
//this random number is returned as the roll
int Die::rollDie()
{

	int randNum = rand() % (N - 1 + 1) + 1;

	return randNum;
}