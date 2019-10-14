#include <iostream>
#include <fstream> // string streaming
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>
#include <conio.h> // reading user input

enum TileType
{
	TILETYPE_FLOOR = '.',
	TILETYPE_GOLD = 'G',
	TILETYPE_MONSTER = 'M',
	TILETYPE_START = 'S',
	TILETYPE_PLAYER = 'P',
	TILETYPE_END = 'E'
};

struct Player {
	int x;
	int y;
	int goldCount;
	TileType standingOn;
};


void genMap(std::string mapLocation, std::vector<std::string> &map);
void getPlayerPosition(Player &player, std::vector<std::string> map);
void renderMap(int playerX, int playerY, std::vector<std::string> &map);
void movePlayer(Player &player, std::vector<std::string> &map);
bool willCollideWithWall(Player& player, std::vector<std::string>& map, int newY, int newX);

const std::string mapLocation = "./map.txt";
const std::string playerSymbol = "S";
const int mapX = 31;
const int mapY = 10;

int main()
{
	bool gameEnded = false;
	std::vector<std::string> map(mapY);
	Player player = {0};

	genMap(mapLocation, map);
	getPlayerPosition(player, map);
	renderMap(player.x, player.y, map);

	while (!gameEnded)
	{
		movePlayer(player, map);
		// deal with monsters/gold/etc here
		renderMap(player.x, player.y, map);
	}

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

void getPlayerPosition(Player &player, std::vector<std::string> map) {
	for (int y = 0; y <= mapY; y++)
	{
		int x = map[y].find(std::string(1, TILETYPE_START));
		
		if (x != -1) {
			// player found
			player.x = x;
			player.y = y;
			return;
		}
	}

	std::cerr << "Player position not found";
	exit(1);
}

void renderMap(int playerX, int playerY, std::vector<std::string> &map) {
	system("cls");
	map[playerY][playerX] = TILETYPE_PLAYER;

	std::copy(map.begin(), map.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
}

void movePlayer(Player &player, std::vector<std::string> &map) {
	char direction = tolower(_getch());
	switch (direction)
	{
	case 'w':
		if (!willCollideWithWall(player, map, player.y - 1, NULL))
		{
			map[player.y][player.x] = TILETYPE_FLOOR;
			player.y--;
		}
		break;
	case 'a':
		if (!willCollideWithWall(player, map, NULL, player.x - 1))
		{
			map[player.y][player.x] = TILETYPE_FLOOR;
			player.x--;
		}
		break;
	case 's':
	{
		if (!willCollideWithWall(player, map, player.y + 1, NULL))
		{
			map[player.y][player.x] = TILETYPE_FLOOR;
			player.y++;
		}
	}
		break;
	case 'd':
		if (!willCollideWithWall(player, map, NULL, player.x + 1))
		{
			map[player.y][player.x] = TILETYPE_FLOOR;
			player.x++;
		}
	}
}

bool willCollideWithWall(Player& player, std::vector<std::string>& map, int newY, int newX) {
	bool updateY = newY;
	
	if (updateY)
		return map[newY][player.x] == '#';

	return map[player.y][newX] == '#';
}