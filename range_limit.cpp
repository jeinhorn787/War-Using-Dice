/***********************************************************************************************
** Program Name: Lab 3 (Inheritance)
** Author: Jeremy Einhorn
** Date: July 13, 2017
** Description: This is the implementation file for my range limimt function.  If the user enters
anything lower than the min, it returns false.  If the user enters anything more than the max, it 
returns false.
*************************************************************************************************/

#include"range_limit.hpp"
#include<iostream>
using std::cout;
using std::endl;

//input that is either lower than the min or
//higher than the max has this function return false
bool isRange(int input, int max, int min)
{
	if (input > max)
		return false;
	if (input < min)
		return false;

	return true;
}