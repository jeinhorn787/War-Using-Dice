/********************************************************************************************
** Program Name: Lab3 (Inheritance)
** Author: Jeremy Einhorn
** Date: July 13, 2017
** Description: This is the implementation file for the class Game.  The function play() uses
the other functions in this class inside of it to set up a fully working game.
*********************************************************************************************/

#include"Game.hpp"
#include<iostream>
#include<cstdlib>
#include<ctime>
using std::cout;
using std::cin;
using std::endl;
using std::getline;

//asks the user the number of sides for the dice
int Game::askForSides(int player)
{
	int sides;

	cout << "Please enter a positive integer greater than 1 for the number of sides for player " 
		<< player << endl;
	cout << "Please do not exceed 200." << endl;
	//input validation to make sure a positive integer is entered
	sides = getUnsignedInt();

	//while the user enters less than 2 or more than 200, they must re-enter
	while (!(isRange(sides, 200, 2)))
	{
		cout << "Error.  Please enter a positive integer from 2 to 200." << endl;

		sides = getUnsignedInt();
	}

	return sides;
}

//asks the user for the dicec type
int Game::askForDieType(int player)
{
	//integer to hold dice type. 1 for regular, 2 for loaded
	int type;

	cout << "Please enter either 1 for a regular dice, or 2 for a loaded dice for player "
		<< player << endl;
	//input validation to make sure user enters positive integer
	type = getUnsignedInt();

	//if user enters more than 2 or less than 1, they must re-enter
	while (!(isRange(type, 2, 1)))
	{
		cout << "Error.  Please enter either only 1 for a regular die, or 2 for a"
			" loaded die." << endl;

		type = getUnsignedInt();
	}

	return type;
}

//the number of sides and dice type entered by the user are passed to this
//if they want a regular dice, a dynamically allocated Die is constructed and returned
//if the want a loaded dice, a dynamically allocated LoadedDie is constructed and returned
Die* Game::makeDie(int sides, int type)
{
	
	//if a regular dice
	if (type == 1)
		return new Die(sides);

	//if a loaded dice
	else
		return new LoadedDie(sides);
}

//creates and runs a fully working game of War using 2 kinds of Die
void Game::play()
{
	//integers to hold the number of rounds the user wants, the number of sides
	//the user chooses for player 1 and 2, the dice type for player 1 and 2,
	//an accumulator for the round, for player 1's score, and player's 2 score
	int rounds, player1Sides, player1Type, player2Sides, player2Type;
	int roundAccum = 0, p1Accum = 0, p2Accum = 0;

	cout << "Please enter a positive integer greater than 0 for the number of rounds"
		" to be played." << endl;
	cout << "Please do not exceed 200." << endl;
	//input validation to make sure user enters positive integer
	rounds = getUnsignedInt();

	//while user enters more than 200 or less than 1, they must re-enter
	while (!(isRange(rounds, 200, 1)))
	{
		cout << "Error. Please choose between 1 to 200 rounds." << endl;

		rounds = getUnsignedInt();
	}

	//player 1 and 2 sides numbers are created by calling Game's askForSide() fuction
	//player 1 and 2 dice types are created by calling Game's askForDieType() function
	player1Sides = this->askForSides(1);
	player1Type = this->askForDieType(1);
	player2Sides = this->askForSides(2);
	player2Type = this->askForDieType(2);

	//2 pointers to a Die are created, 1 for player 1 and 1 for player 2
	//it uses Game's makeDie() function to create the right dice that each player
	//will be using as specified by the user
	Die *player1Die = makeDie(player1Sides, player1Type);
	Die *player2Die = makeDie(player2Sides, player2Type);
	//needed 1 time to seed a random number, this cannot be called in any kind
	//of loop
	srand(time(NULL));

	//keeps the game going until the last round has been played
	while (roundAccum < rounds)
	{
		//add 1 for the round number after every new iteration
		roundAccum += 1;

		//integers that hold the number the die returned, whether it is
		//loaded or not
		int p1 = player1Die->rollDie();
		int p2 = player2Die->rollDie();

		cout << "Round " << roundAccum << ":	Player 1 rolled a " << p1 << " while Player 2 rolled a "
			<< p2 << endl;

		//if player 1 rolled higher, they win the round
		if (p1 > p2)
			p1Accum += 1;

		//if player 2 rolled higher, they win the round
		//if rolls were the same, round is a tie and no one gets
		//a point
		if (p1 < p2)
			p2Accum += 1;
	}

	//if player 1's score is higher at the end, player 1 wins
	if (p1Accum > p2Accum)
		cout << "Player 1 won!" << endl;

	//if player 2's score is higher at the end, player 2 wins
	else if (p1Accum < p2Accum)
		cout << "Player 2 won!" << endl;

	//if player 1 and player 2 have the same score, it is a drawa
	else
		cout << "It's a draw." << endl;

	//outputs player 1's type of die and how many sides it was
	if (player1Type == 1)
		cout << "Player 1 was using a " << player1Sides << "-sided regular die." << endl;
	else
		cout << "Player 1 was using a " << player1Sides << "-sided loaded die." << endl;

	//outputs player 2's type of die and how many sides it was
	if (player2Type == 1)
		cout << "Player 2 was using a " << player2Sides << "-sided regular die." << endl;
	else
		cout << "Player 2 was using a " << player2Sides << "-sided loaded die." << endl;

	//free the memory taken from the heap
	delete[] player1Die;
	delete[] player2Die;
}