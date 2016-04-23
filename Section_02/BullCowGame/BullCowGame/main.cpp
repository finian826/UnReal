#include <stdio.h>
#include <iostream>
#include "4wordlist.h"
#include "5wordlist.h"

using namespace std;


int main()
{
	int RetVal = 0;
	constexpr int WORD_LENGTH = 6;

	cout << "Welcome to Bulls and Cows\n";
	cout << endl;
	cout << "Can you guess and " << WORD_LENGTH << " letter isogram I'm thinking of? \n";
	cout << endl;

	return RetVal;
}