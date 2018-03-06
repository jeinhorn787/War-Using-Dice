/********************************************************************************************
** Program Name: Lab3 (Inheritance)
** Author: Jeremy Einhorn
** Date: July 13, 2017
** Description: This is the implementation file for my Input Validation.
It does not include all of my input validation functions, only the ones necessary for this
lab.
*********************************************************************************************/

#include "input_validation.hpp"
#include <iostream>
#include <algorithm>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;
using std::remove;
using std::atoi;

//properly gathers a positive integer from the user
int getUnsignedInt()
{
	//user input is stored as string
	string input;
	//integer variable to store the returned unsigned integer
	int uint;

	do 
	{
		//getline will get every character from the string
		getline(cin, input);

		//the following code taken from 
		//https://stackoverflow.com/questions/16329358/remove-spaces-from-a-string-in-c
		input.erase(remove(input.begin(), input.end(), ' '), input.end());
		//end of copied code. this code will remove
		//all whitespace from the string

		//if the string is found NOT to be an unsigned integer
		if (!(isUnsignedInt(input)))
			cout << "Error.  Please enter a postitive integer." << endl;

	} while (!(isUnsignedInt(input)));

	//converts string to integer
	uint = atoi(input.c_str());

	return uint;
}

//checks to see if the string that holds the user input is in fact 
//an unsigned int
bool isUnsignedInt(string input)
{	
	bool status;
	
	for (int index = 0; index < input.size(); index++)
	{
		if (isdigit(input[index]))
			status = true;
		//if any element in the string is anything but number
		//it automatically returns false
		else
			return false;
	}

	return status;
}
