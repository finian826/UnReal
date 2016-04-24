#include <stdio.h>
#include <iostream>
#include <string>
#include "4wordlist.h"
#include "5wordlist.h"
#include "MyFunctions.h"
#include "FBullCowGame.h"

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


