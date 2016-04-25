#pragma once
#include "FBullCowGame.h"

#ifndef __MyFunctions__
#define __MyFunctions__

FBullCowGame BCGame;

using FText = std::string;
using int32 = int;
using FString = std::string;


void PrintIntro() {
	

	std::cout << "Welcome to Bulls and Cows\n";
	std::cout << std::endl;
	std::cout << "Can you guess and " << BCGame.GetHiddenWordLenth() << " letter isogram I'm thinking of? \n";
	std::cout << std::endl;
	return;

}

FText GetValidGuess() // TODO Change to GetValidGuess
{
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do
	{
		FText Guess = "";
		int32 CurrentTry = BCGame.GetCurrentTry();
		// get guess from the player
		// TODO Add loop for guess checking.
		std::cout << "Try " << CurrentTry << ". Please enter a guess? ";
		std::getline(std::cin, Guess);
		// submit valid guess

		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLenth() << " letter word. \n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter and isogram.\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter your word in lowercase./n";
			break;
		default:
			return Guess;
		}
		std::cout << std::endl;
	} while (Status != EGuessStatus::OK);
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
		FText Guess = GetValidGuess();
		PrintGuess(Guess);
		FBullCowcount BullCowCount = BCGame.SubmitGuess(Guess);
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << std::endl;
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
