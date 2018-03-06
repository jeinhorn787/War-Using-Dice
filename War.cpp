/********************************************************************************************
** Program Name: Lab3 (Inheritance)
** Author: Jeremy Einhorn
** Date: July 13, 2017
** Description: This is the main file to play War.
*********************************************************************************************/

#include"Game.hpp"
#include<iostream>
using namespace std;

int main()
{
	//a simple menu is brought up which allows a use to eitehr play War
	//or quite the programs
	int choice = menu();

	//if the user choosese to play War
	while (choice == 1)
	{
		//an object of game is created and it's play() function
		//is called
		Game game;
		game.play();

		//the menu pops up again at the end of the game
		choice = menu();
	}

	//if the user chooses to Quit, the program ends
	if (choice == 2)
		return 0;

}