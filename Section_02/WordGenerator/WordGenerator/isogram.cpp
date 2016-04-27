#include "isogram.h"
#include <map>
#ifndef TMAP
#define TMap std::map
#endif // !TMAP

using int32 = int;
using FString = std::string;
using FText = std::string;

bool Isogram::IsIsogram(FString Word) const
{
	TMap<char, bool> LetterSeen;

	// treat 0 and 1 letter strings as true
	if (Word.length() <= 1) { return true; }

	for (auto Letter : Word)//loop through letters of the word
	{
		Letter = towlower(Letter);
		if (LetterSeen[Letter])
		{
			return false;
		}
		else
		{
			LetterSeen[Letter] = true;
		}
			//if the letter is in the map
				//we don't have isogram
			//otherwise
				// add letter to map as seen
	}
	

	return true;
}
