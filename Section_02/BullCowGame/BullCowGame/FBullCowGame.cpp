#include "FBullCowGame.h"

using int32 = int;
using FString = std::string;
using FText = std::string;

int32 FBullCowGame::GetMaxTries() const {return MyMaxTries;}
int32 FBullCowGame::GetCurrentTry() const {return MyCurrentTry;}
int32 FBullCowGame::GetHiddenWordLenth() const {return MyHiddenWord.length();}
bool FBullCowGame::IsGameWon() const { return bGameIsWon;}

FBullCowGame::FBullCowGame() {Reset();}

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;
	
	MyCurrentTry = 1;
	bGameIsWon = false;

	return;
}



EGuessStatus FBullCowGame::CheckGuessValidity(FText Guess) const
{
	if (false) // TODO Write function for isogram
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (false) // TODO if not all lowercase
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


FBullCowcount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;

	FBullCowcount BullCowCount;
	BullCowCount.Bulls = 0;
	BullCowCount.Cows = 0;

	int32 WordLength = MyHiddenWord.length();
	//loop through each letter
	for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++)
	{
		//compare each letter to hidden word
		for (int32 GChar = 0;GChar < WordLength;GChar++)
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
	if (BullCowCount.Bulls == WordLength) 
	{ 
		bGameIsWon = true;
	}
	else 
	{ 
		bGameIsWon = false;
	}

	return BullCowCount;
}
