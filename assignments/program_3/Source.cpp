#include <iostream>
#include <fstream>
#include <string>

#include "DBList.h"

using namespace std;

int main() {
	int quit = 20, m = 0, Count = 0;
	ifstream fin;
	ofstream fout;
	fin.open("animals.txt");
	fout.open("output.txt");
	cout <<"Please enter a number between 1 and 13 \n";
	while (m < 1 || m > 13)
	{
		cin >> m;
	}
	srand(93487);
	DBList List;
	string a;



	while (fin >> a) {

		List.InsertRear(a);
		
	}

	fout << endl;

	fin.clear();
	fin.seekg(0, std::ios::beg); // back to the start!
	fin >> a;
	fout << "First: ";
	fout << List.Eliminate(a, m) << '\n';
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
	system("pause");
}