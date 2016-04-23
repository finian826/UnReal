#include <stdio.h>
#include <iostream>
#include <string>
#include "4wordlist.h"
#include "5wordlist.h"
#include "MyFunctions.h"

using namespace std;


int main()
{
	int RetVal = 0;
	int GuessLimit = 5;
	
	PrintIntro();

	for (int count = 1; count <= GuessLimit; count++)
	{
		GetGuess();
	}

	return RetVal;
}