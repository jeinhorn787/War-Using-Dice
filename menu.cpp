/********************************************************************************************
** Program Name: Lab3 (Inheritance)
** Author: Jeremy Einhorn
** Date: July 13, 2017
** Description: This is the implementation file for my menu for this lab. It only has 2 
options; either play War or Quit
*********************************************************************************************/

#include"menu.hpp"
#include"range_limit.hpp"
#include"input_validation.hpp"
#include<iostream>
using std::cout;
using std::cin;
using std::endl;

int menu()
{
	//integer variable holds the users choice
	int choice;

	
	cout << "1: Play War" << endl;
	cout << "2: Quit" << endl;

	cout << "Please enter either 1 or 2 for you choice." << endl;
	//input validation to make sure user entered positive integer
	choice = getUnsignedInt();

	//while the user enters more than 2 or less than 1, they must re-enter
	while (!(isRange(choice, 2, 1)))
	{
		cout << "Error. Please choose either 1 or 2." << endl;

		choice = getUnsignedInt();
	}

	//if the choice is 1, return 1 = play Way
	//if the choise is 2, return 2 = Quit
	switch (choice)
	{
	case 1:
		return 1;
		break;

	case 2:
		return 2;
		break;
	}
}