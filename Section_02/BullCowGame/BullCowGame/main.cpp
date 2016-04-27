#include <stdio.h>
#include <iostream>
#include <string>
#include "MyFunctions.h"
#include "FBullCowGame.h"
#include "isogram.h"
#include <map>
#ifndef TMAP
#define TMap std::map
#endif // !TMAP

using FText = std::string;
using int32 = int;
using FString = std::string;

int main()
{
	int32 RetVal = 0;
	
	do
	{
		PrintIntro();
		PlayGame();
		
	} while (AskToPlayAgain());
	

	return RetVal;
}


