#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int genMultiArray(int &arrMap);
int spawnPlayerAtS();

int main()
{
	string arrMap[10][31];

	genMultiArray(&arrMap);
	spawnPlayerAtS();

	system("pause");
}

int genMultiArray(int &arrMap) {
	ifstream inFile;
	string stringLn;

	inFile.open("./map.txt");

	if (inFile.is_open()) {
		// Store the map in multidimensional array
		int rowNo = 0;

		while (getline(inFile, stringLn))
		{
			int charNo = 0;

			for (char& c : stringLn) 
			{
				arrMap[rowNo][charNo] = c;

				if (c == 'S')
				{
					int playerX = rowNo;
					int playerY = charNo;
				}

				charNo++;
			}

			if (rowNo == 9)
				return **arrMap;

			rowNo++;
		}
	}

	inFile.close();
	return 0;
}

int spawnPlayerAtS() {
	return 1;
}