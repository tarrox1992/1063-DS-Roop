#include <iostream>
#include <fstream>
#include <string>

#include "DBList.h"

using namespace std;

int main() {
	// declares user input multiplier, loop count and file variables
	int m = 0, Count = 0;
	ifstream fin;
	ofstream fout;
	fin.open("animals.txt");
	fout.open("output.txt");
	
	// sets multiplier variable to what the user inputs
	cout <<"Please enter a number between 1 and 13 \n";
	while (m < 1 || m > 13)
	{
		cin >> m;
	}
	srand(93487);
	DBList List;
	string a;

	// creates a linked list with strings from file
	while (fin >> a) {

		List.InsertRear(a);
		
	}

	fout << endl;

	// sets file back to beginning
	fin.clear();
	fin.seekg(0, std::ios::beg);
	
	// starts elimination with first item in list
	fin >> a;
	fout << "First: ";
	fout << List.Eliminate(a, m) << '\n';
	// loop using the rest of the file to eliminate animals
	while (fin >> a) {
		if (Count % 11 == 0)
		{
			fout << "- " << List.Eliminate(a, m) << '\n';
		}

		else
			List.Eliminate(a, m);
		Count++;
	}
	fout << "WINNER: " << List.Eliminate(a, m) << '\n';
	fin.close();
	fout.close();
	return 0;
}
