#pragma once
#include <string>

#ifndef __FBullCowGame__
#define __FBullCowGame__

using FString = std::string;
using int32 = int;
using FText = std::string;

// all values initialized to 0
struct BullCowcount
{
	int32 Bulls = 0;
	int32 Cows = 0;

};
class FBullCowGame
{
public:
	FBullCowGame();

	void Reset();
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;
	bool CheckGuessValidity(FText); // TODO make a more rich return value
	// count bulls and cows, increase try #
	BullCowcount SubmitGuess(FString);

private:
	// Values set in constructor
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
	
};
#endif // !__FBullCowGame__
