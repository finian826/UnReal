#pragma once
#include <string>
#include <map>

#ifndef TMAP
#define TMap std::map
#endif // !TMAP

#ifndef __FBullCowGame__
#define __FBullCowGame__

using FString = std::string;
using int32 = int;
using FText = std::string;

// all values initialized to 0
struct FBullCowcount
{
	int32 Bulls = 0;
	int32 Cows = 0;

};

enum class EGuessStatus
{
	Invalid_Status,
	OK,
	Not_Isogram,
	Not_Lowercase,
	Wrong_Length
};

class FBullCowGame
{
public:
	FBullCowGame();

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLenth() const;
	FString GetHiddenWord() const;
	bool IsGameWon() const;
	EGuessStatus CheckGuessValidity(FString) const; 

	// count bulls and cows, increase try #
	FBullCowcount SubmitValidGuess(FString);
	FString GetNewWord();

	void Reset();

private:
	// Values set in constructor
	int32 MyCurrentTry;
	FString MyHiddenWord;
	bool bGameIsWon;
	FString WordList[25000];
	int32 TotalWords;

	bool IsLowerCase(FString) const;
};
#endif // !__FBullCowGame__
