#pragma once
#include "FBullCowGame.h"
#include "isogram.h"
#include <map>
#ifndef TMAP
#define TMap std::map
#endif // !TMAP


#ifndef __MyFunctions__
#define __MyFunctions__

FBullCowGame BCGame;

using FText = std::string;
using int32 = int;
using FString = std::string;


void PrintIntro() {
	

	std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
	std::cout << std::endl;
	std::cout << "          }___{         ___ " << std::endl;
	std::cout << "          (o o)        (o o) " << std::endl;
	std::cout << "   /-------\\ /          \\ /-------\\ " << std::endl;
	std::cout << "  / | BULL |O            O| COW  | \\ " << std::endl;
	std::cout << " *  |-,--- |              |------|  * " << std::endl;
	std::cout << "    ^      ^              ^      ^ " << std::endl;
	std::cout << "Can you guess and " << BCGame.GetHiddenWordLenth() << " letter isogram I'm thinking of? \n";
	std::cout << std::endl;
	return;

}

FText GetValidGuess() 
{
	FText Guess = "";
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do
	{
		
		int32 CurrentTry = BCGame.GetCurrentTry();
		// get guess from the player
		
		std::cout << "Try " << CurrentTry << " of " << BCGame.GetMaxTries();
		std::cout << ". Please enter a guess? ";
		std::getline(std::cin, Guess);
		// submit valid guess

		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLenth() << " letter word. \n\n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter and isogram.\n\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter your word in lowercase.\n\n";
			break;
		case EGuessStatus::OK:
			//ok
			break;
		default:
			// ok
			break;
		}
		
	} while (Status != EGuessStatus::OK);
	return Guess;
}

void PrintGuess(FText &Guess)
{
	//repeat the guess back to them
	std::cout << "Your guess was: " << Guess << std::endl;

}

void PrintGameSummary()
{
	if (BCGame.IsGameWon())
	{
		std::cout << "You Won!/n";
	}
	else
	{
		std::cout << "You Lost!/nThe word was " << BCGame.GetHiddenWord() << std::endl;
	}
	return;
}
void PlayGame()
{
	BCGame.Reset();
	PrintIntro();
	int32 GuessLimit = BCGame.GetMaxTries();
	
	// loop until game won or turns exhausted
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= GuessLimit)
	{
		FText Guess = GetValidGuess();
		PrintGuess(Guess);
		FBullCowcount BullCowCount = BCGame.SubmitValidGuess(Guess);
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << std::endl << std::endl;
	}
	// game summery
	PrintGameSummary();
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
