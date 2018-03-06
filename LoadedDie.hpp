/********************************************************************************************
** Program Name: Lab3 (Inheritance)
** Author: Jeremy Einhorn
** Date: July 13, 2017
** Description: This is the header file for the class LoadedDie.
*********************************************************************************************/

#ifndef LOADEDDIE_HPP
#define LOADEDDIE_HPP
#include"Die.hpp"

class LoadedDie : public Die
{
protected:	//should be private
	int N;
	//loadedSide holds which side is loaded, thus it will roll to it more often
	int loadedSide;

public:
	LoadedDie(int);
	int rollDie();
};

#endif
