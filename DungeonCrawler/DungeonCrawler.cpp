#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

enum TileType
{
	TILETYPE_FLOOR = '.',
	TILETYPE_GOLD = 'G',
	TILETYPE_MONSTER = 'M',
	TILETYPE_START = 'S',
	TILETYPE_END = 'E'
};

struct Player {
	int x;
	int y;
	int goldCount;
	TileType standingOn;
};


void genMap(std::string mapLocation, std::vector<std::string> &map);
void getPlayerPosition(Player player, std::vector<std::string> map);

const std::string mapLocation = "./map.txt";
const std::string playerSymbol = "S";
const int mapX = 31;
const int mapY = 10;

int main()
{
	std::vector<std::string> map(mapY);
	Player player = {0};

	genMap(mapLocation, map);
	getPlayerPosition(player, map);

	system("pause");
}

void genMap(std::string mapLocation, std::vector<std::string> &map) {
	std::string line;
	std::ifstream inFile(mapLocation);

	if (inFile.is_open())
	{
		map.clear();

		while (std::getline(inFile, line))
		{
			map.push_back(line);
		}

		std::cout << "\n";
	}
}

void getPlayerPosition(Player player, std::vector<std::string> map) {
	for (int i = 0; int i < map.; int i++)
	{

	}
}