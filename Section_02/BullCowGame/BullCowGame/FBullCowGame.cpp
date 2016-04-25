#include "FBullCowGame.h"

using int32 = int;
using FString = std::string;
using FText = std::string;

int32 FBullCowGame::GetMaxTries() const {return MyMaxTries;}
int32 FBullCowGame::GetCurrentTry() const {return MyCurrentTry;}
int32 FBullCowGame::GetHiddenWordLenth() const {return MyHiddenWord.length();}

FBullCowGame::FBullCowGame() {Reset();}

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;
	
	MyCurrentTry = 1;

	return;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FText Guess) const
{
	if (false) // if not an isogram
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (false) // if not all lowercase
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetHiddenWordLenth())
	{
		return EGuessStatus::Wrong_Length;
	}
	else
	{
		return EGuessStatus::OK;
	}

	
}


FBullCowcount FBullCowGame::SubmitGuess(FString Guess)
{
	// increse turn
	MyCurrentTry++;

	//setup return variable
	FBullCowcount BullCowCount;
	BullCowCount.Bulls = 0;
	BullCowCount.Cows = 0;

	int32 HiddenWordLength = MyHiddenWord.length();
	//loop through each letter
	for (int32 MHWChar = 0; MHWChar < HiddenWordLength; MHWChar++)
	{
		//compare each letter to hidden word
		for (int32 GChar = 0;GChar < HiddenWordLength;GChar++)
		{
			// if they match then
			if (Guess[MHWChar] == MyHiddenWord[GChar])
			{
				// if in right spot
				if (MHWChar == GChar)
				{
					// increment bulls
					BullCowCount.Bulls++;
				}
				else
				{
					// increment cows if not
					BullCowCount.Cows++;
				}
			}

		}
	}
	return BullCowCount;
}
