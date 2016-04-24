#include "FBullCowGame.h"

using int32 = int;
using FString = std::string;
using FText = std::string;

int32 FBullCowGame::GetMaxTries() const {return MyMaxTries;}
int32 FBullCowGame::GetCurrentTry() const {return MyCurrentTry;}

FBullCowGame::FBullCowGame() {Reset();}

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "plant";
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;

	return;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(FText)
{
	return false;
}


BullCowcount FBullCowGame::SubmitGuess(FString)
{
	// increse turn
	MyCurrentTry++;

	//setup return variable
	BullCowcount BullCowCount;

	//loop through each letter
		//compare each letter to hidden word

	return BullCowcount;
}
