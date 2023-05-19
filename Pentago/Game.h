#pragma once
#include "ServerHandler.h"
#include <vector>

ref class Game
{
	System::EventHandler^ fillHandler;
	
	bool isWhiteMove = true;
	bool isMove = true;

	int fieldSize;
	int fieldsAmount;

	bool isSocketWhite;
	bool isDuel = true;

	ServerHandler^ handler;

	cli::array<cli::array<cli::array<int>^>^>^ field; // 1 - 4 fileds 2, 3 - 3 * 3 field size

	int checkLine(std::vector<int> line);

	void checkBoundsAndAdd(std::vector<int>* v, std::vector<std::vector<int>> matrix, int x, int y);

	void updateField();

	void moveHandler(System::Object^ o, System::EventArgs^ e);

	void rotateHandler(System::Object^ o, System::EventArgs^ e);

	void winHandler(System::Object^ o, System::EventArgs^ e);


public:

	Game(int fieldsAmount, int fieldSize);

	bool move(int i, int x, int y, bool isSocket);// player => 1 - white 2 - black

	bool rotate(int i, bool clockwise, bool isSocket);

	cli::array<cli::array<cli::array<int>^>^>^ getField();

	int checkGame(); // int - player who won

	void addFillHandler(System::EventHandler^ handler);

	void initServer(System::String^ ip);

	void initClient(System::String^ ip);

	void initBot();

	bool whiteMove() {
		return isWhiteMove;
	};
};