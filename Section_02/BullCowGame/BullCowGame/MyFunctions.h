#pragma once
#include <iostream>
#include <string>

#ifndef __MyFunctions__
#define __MyFunctions__

using namespace std;

void PrintIntro() {
	constexpr int WORD_LENGTH = 4;

	cout << "Welcome to Bulls and Cows\n";
	cout << endl;
	cout << "Can you guess and " << WORD_LENGTH << " letter isogram I'm thinking of? \n";
	cout << endl;
	return;

}

string GetGuess() {
	string Guess = "";

	// get guess from the player
	cout << "Please enter a guess? ";
	getline(cin, Guess);

	//repeat the guess back to them
	cout << "Your guess was: " << Guess << endl << endl;

	return Guess;
}
#endif // !__MyFunctions__
