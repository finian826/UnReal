#pragma once
#include "FBullCowGame.h"

#ifndef __MyFunctions__
#define __MyFunctions__

FBullCowGame BCGame;

using FText = std::string;
using int32 = int;
using FString = std::string;


void PrintIntro() {
	constexpr int32 WORD_LENGTH = 4;

	std::cout << "Welcome to Bulls and Cows\n";
	std::cout << std::endl;
	std::cout << "Can you guess and " << WORD_LENGTH << " letter isogram I'm thinking of? \n";
	std::cout << std::endl;
	return;

}

FText GetGuess() {
	FText Guess = "";
	int32 CurrentTry = BCGame.GetCurrentTry();
	// get guess from the player
	// TODO Add loop for guess checking.
	std::cout << "Try " << CurrentTry << ". Please enter a guess? ";
	std::getline(std::cin, Guess);
	// submit valid guess

	// print number of bulls and cows

	return Guess;
}

void PrintGuess(FText &Guess)
{
	//repeat the guess back to them
	std::cout << "Your guess was: " << Guess << std::endl << std::endl;

}

void PlayGame()
{
	BCGame.Reset();
	int32 GuessLimit = BCGame.GetMaxTries();
	// TODO change to while loop once validation is done
	for (int32 count = 1; count <= GuessLimit; count++)
	{
		PrintGuess(GetGuess());
	}
	// TODO Add game summery
	return;
}

bool AskToPlayAgain()
{
	FText Response = "";
	bool PlayAgain = false;
	std::cout << "Do you want to play again (y/n)? ";
	std::getline(std::cin, Response);

	return ((Response[0] == 'y') || (Response[0] == 'Y'));
	
}
#endif // !__MyFunctions__
