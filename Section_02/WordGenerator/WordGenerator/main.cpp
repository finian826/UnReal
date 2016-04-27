#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <regex>
#include "isogram.h"

using namespace std;

Isogram IsIsogram;


int main(int argc, char * argv[]) {
	
	string Words[20000];
	int i = 0;

	fstream in(argv[1]);
	if (!in)
	{
		cout << "Unable to open " << argv[1] << endl;	
	}
	else 
	{
		cout << "Processing " << argv[1] << endl;
	}
		
	
	// String Variables to read input file
	string date;
	string temp;
	
	string lineIn;

	while(getline(in, lineIn)) 
	{
		stringstream linestr(lineIn);
		//cout << "Raw:" << lineIn << endl;
		while (getline(linestr, date, ','))
		{
			date = regex_replace(date, regex("^ +"), "");
				if (IsIsogram.IsIsogram(date))
				{
					Words[i] = date;
					i++;
				}
		}
	}
	in.close();
	cout << "\nWord 533 is " << Words[532] << endl;
	cout << "\nSize of Words struct " << i -1 << endl;
	int k = 0;
	int j;
	fstream outfile;
	outfile.open("MasterList.txt", ios::out | ios::app);
	cout << "Wrinting Words\n";
	outfile.seekg(0, ios::end);
	cout << "Moved to end of file.\n";
	for (j = 0; j <= i - 2; j = j + 1)
	{

		outfile << Words[j] << ",";
		outfile.flush();
		//cout << Words[j] << ",";
	}
	outfile << Words[j] << endl;
	//cout << Words[j] << endl;
	
	
	outfile.close();

	return 0;
}