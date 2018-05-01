```c++
/////////////////////////////////////////////////////////////////////////////////////////////
// ProgramName: Program-3 Survival
// Author: Tyler Roop
// Description:
//   This program reads in a list of animals from a file. It then asks a user for an integer to use an
//   a multiplier. The program uses the multiplier and the number of digits in the name of the current animal
//   to select the next animal to 'eliminate'. The first animal eliminated and every 11th animal eliminated are
//   printed to a file along with the only remaining animal.
// Course: 1063 Data Structures
// Semester: Spring 2018
// Date: 30 04 2018
/////////////////////////////////////////////////////////////////////////////////////////////
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

	// prints header to file

	fout << "/////////////////////////////////////////////////////////////////////////////////////////////\n";
	fout << "// ProgramName: Program-3 Survival\n";
	fout << "// Author: Tyler Roop\n";
	fout << "// Description:\n";
	fout << "//   This program reads in a list of animals from a file. It then asks a user for an integer to use as\n";
	fout << "//   a multiplier. The program uses the multiplier and the number of digits in the name of the current animal\n";
	fout << "//   to select the next animal to 'eliminate'. The first animal eliminated and every 11th animal eliminated are\n";
	fout << "//   printed to a file along with the only remaining animal.\n";
	fout << "// Course: 1063 Data Structures\n";
	fout << "// Semester: Spring 2018\n";
	fout << "// Date: 30 04 2018\n";
	fout << "/////////////////////////////////////////////////////////////////////////////////////////////\n\n";


	// sets multiplier variable to what the user inputs
	cout << "Please enter a number between 1 and 13 \n";
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
	fout << List.Eliminate(m) << '\n';
	// loop using the rest of the animals to decide on the eliminated one
	// prints first animal eliminated and then every 11th animal after
	while (fin >> a) {
		if (Count % 11 == 0)
		{
			fout << "- " << List.Eliminate(m) << '\n';
		}
		else
			List.Eliminate(m);
		Count++;
	}
	fout << "WINNER: " << List.Eliminate(m) << '\n';
	fin.close();
	fout.close();
	return 0;
}
