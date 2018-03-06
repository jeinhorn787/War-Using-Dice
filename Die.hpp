/********************************************************************************************
** Program Name: Lab3 (Inheritance)
** Author: Jeremy Einhorn
** Date: July 13, 2017
** Description: This is the header file for the class Die.
*********************************************************************************************/

#ifndef DIE_HPP
#define DIE_HPP

class Die
{
protected:
	int N;

public:
	Die(int);
	//was unsure if virtual was necessary but I feel it is good to have just in case
	virtual int rollDie();
};

#endif