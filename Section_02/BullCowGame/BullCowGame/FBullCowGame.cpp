#pragma once

#include "FBullCowGame.h"
#include"isogram.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <random>

#include <map>
#ifndef TMAP
#define TMap std::map
#endif // !TMAP

using int32 = int;
using FString = std::string;
using FText = std::string;


int32 FBullCowGame::GetCurrentTry() const {return MyCurrentTry;}
int32 FBullCowGame::GetHiddenWordLenth() const {return MyHiddenWord.length();}
FString FBullCowGame::GetHiddenWord() const { return MyHiddenWord;}
bool FBullCowGame::IsGameWon() const { return bGameIsWon;}

int32 FBullCowGame::GetMaxTries() const 
{
	TMap<int32, int32> WordLengthToMaxTries{ {3,5},{4,7},{5,9},{6,15},{7,20},{8,25},{9,30},{10,35} };

	return WordLengthToMaxTries[MyHiddenWord.length()];
}
FBullCowGame::FBullCowGame() 
{
	int32 i = 0;
	std::fstream in("MasterList.txt");
	if (!in)
	{
		std::cout << "Error opening word list";
	}
	else
	{
		std::cout << "Reading Words\n";
	}

	FString word;
	FString lineIn;

	while (std::getline(in, lineIn))
	{
		std::stringstream linestr(lineIn);
		//std::cout << "Raw:" << lineIn << std::endl;
		while (std::getline(linestr, word, ','))
		{
			WordList[i] = word;
			i++;
		}
	}
	in.close();
	TotalWords = i - 1;

	Reset();
}

Isogram ChkIsogram;


void FBullCowGame::Reset()
{
	const FString HIDDEN_WORD = GetNewWord();
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
	
	if (!ChkIsogram.IsIsogram(Guess)) 
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (!IsLowerCase(Guess)) 
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

FString FBullCowGame::GetNewWord()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dist(0, TotalWords);
	FString NewWord;

	NewWord = WordList[dist(gen)];

	return NewWord;
}
