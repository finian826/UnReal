#include "FBullCowGame.h"
#include"isogram.h"
#include <map>
#ifndef TMAP
#define TMap std::map
#endif // !TMAP

using int32 = int;
using FString = std::string;
using FText = std::string;

int32 FBullCowGame::GetMaxTries() const {return MyMaxTries;}
int32 FBullCowGame::GetCurrentTry() const {return MyCurrentTry;}
int32 FBullCowGame::GetHiddenWordLenth() const {return MyHiddenWord.length();}
bool FBullCowGame::IsGameWon() const { return bGameIsWon;}

FBullCowGame::FBullCowGame() {Reset();}

Isogram ChkIsogram;

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 5;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;
	
	MyCurrentTry = 1;
	bGameIsWon = false;

	return;
}

bool FBullCowGame::IsLowerCase(FString Word) const
{
	if (Word.length() <= 1) { return true; }

	for (auto Letter : Word)
	{
		if (!islower(Letter))
		{
			return false;
		}
	}
	return true;
}



EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	
	if (!ChkIsogram.IsIsogram(Guess)) // TODO Write function for isogram
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (!IsLowerCase(Guess)) // TODO if not all lowercase
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
