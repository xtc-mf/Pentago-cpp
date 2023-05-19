#include "Game.h"
#include <vector>
#include "ServerHandler.h"
#include "BotHandler.h"
#include "PointEvent.h"
#include "Server.h"
#include "Client.h"

using namespace System::Threading;

Game::Game(int fieldsAmount, int fieldSize) {
	this->fieldsAmount = fieldsAmount;
	this->fieldSize = fieldSize;

	field = gcnew cli::array<cli::array<cli::array<int>^>^>(fieldsAmount);
	for (int i = 0; i < fieldsAmount; i++)
	{
		field[i] = gcnew cli::array<cli::array<int>^>(fieldSize);
		for (int j = 0; j < fieldSize; j++)
		{
			field[i][j] = gcnew cli::array<int>(fieldSize);

			for (int k = 0; k < fieldSize; k++)
			{
				field[i][j][k] = 0;
			}
		}
	}
}

int Game::checkLine(std::vector<int> line) {
	int number = 1;
	int previous = 0;

	for each (int el in line) {
		if (el == 0) {
			number = 1;
			continue;
		}

		if (previous == el)
			number++;
		else
			number = 1;

		if (number == 5) return el;

		previous = el;
	}

	return 0;
}

void Game::checkBoundsAndAdd(std::vector<int>* v, std::vector<std::vector<int>> matrix, int x, int y) {
	if (x < 0 || y < 0 || x >= matrix.size() || y >= matrix[x].size()) return;

	v->push_back(matrix[x][y]);
}


int Game::checkGame() {
	// начало проверки поля (алгоритм, который вычисляет победу одного из игроков)
	std::vector<std::vector<int>> matrix;
	// проверка первой платформы
	for (int i = 0; i < fieldSize; i++) {
		matrix.push_back(std::vector<int>());
		for (int j = 0; j < fieldSize; j++) {
			matrix[i].push_back((int)field[0][i][j]);
			}
	}
	for (int i = 0; i < fieldSize; i++)
		for (int j = 0; j < fieldSize; j++)
			matrix[i].push_back((int)field[1][i][j]);
	// проверка второй платформы
	for (int i = 0; i < fieldSize; i++) {
		matrix.push_back(std::vector<int>());
		for (int j = 0; j < fieldSize; j++)
			matrix[3 + i].push_back((int)field[2][i][j]);
	}
	// проверка четвертой платформы
	for (int i = 0; i < fieldSize; i++)
		for (int j = 0; j < fieldSize; j++)
			matrix[i + 3].push_back((int)field[3][i][j]);
	std::vector<int> d1, d2, h, v;
	bool isZero = false;
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size(); j++) {
			if (matrix[i][j] == 0) isZero = true;
			checkBoundsAndAdd(&d1, matrix, i - 4, j - 4);
			checkBoundsAndAdd(&d1, matrix, i - 3, j - 3);
			checkBoundsAndAdd(&d1, matrix, i - 2, j - 2);
			checkBoundsAndAdd(&d1, matrix, i - 1, j - 1);
			checkBoundsAndAdd(&d1, matrix, i, j);
			checkBoundsAndAdd(&d1, matrix, i + 1, j + 1);
			checkBoundsAndAdd(&d1, matrix, i + 2, j + 2);
			checkBoundsAndAdd(&d1, matrix, i + 3, j + 3);
			checkBoundsAndAdd(&d1, matrix, i + 4, j + 4);

			checkBoundsAndAdd(&d2, matrix, i - 4, j + 4);
			checkBoundsAndAdd(&d2, matrix, i - 3, j + 3);
			checkBoundsAndAdd(&d2, matrix, i - 2, j + 2);
			checkBoundsAndAdd(&d2, matrix, i - 1, j + 1);
			checkBoundsAndAdd(&d2, matrix, i, j);
			checkBoundsAndAdd(&d2, matrix, i + 1, j - 1);
			checkBoundsAndAdd(&d2, matrix, i + 2, j - 2);
			checkBoundsAndAdd(&d2, matrix, i + 3, j - 3);
			checkBoundsAndAdd(&d2, matrix, i + 4, j - 4);

			checkBoundsAndAdd(&v, matrix, i, j - 4);
			checkBoundsAndAdd(&v, matrix, i, j - 3);
			checkBoundsAndAdd(&v, matrix, i, j - 2);
			checkBoundsAndAdd(&v, matrix, i, j - 1);
			checkBoundsAndAdd(&v, matrix, i, j);
			checkBoundsAndAdd(&v, matrix, i, j + 1);
			checkBoundsAndAdd(&v, matrix, i, j + 2);
			checkBoundsAndAdd(&v, matrix, i, j + 3);
			checkBoundsAndAdd(&v, matrix, i, j + 4);

			checkBoundsAndAdd(&h, matrix, i - 4, j);
			checkBoundsAndAdd(&h, matrix, i - 3, j);
			checkBoundsAndAdd(&h, matrix, i - 2, j);
			checkBoundsAndAdd(&h, matrix, i - 1, j);
			checkBoundsAndAdd(&h, matrix, i, j);
			checkBoundsAndAdd(&h, matrix, i + 1, j);
			checkBoundsAndAdd(&h, matrix, i + 2, j);
			checkBoundsAndAdd(&h, matrix, i + 3, j);
			checkBoundsAndAdd(&h, matrix, i + 4, j);

			auto checked = checkLine(d1);
			if (checked != 0) {
				if (!isDuel && this->handler != nullptr) this->handler->sendMsg(L"win");
				return checked; 
			}
			checked = checkLine(d2);
			if (checked != 0) {
				if (!isDuel && this->handler != nullptr) this->handler->sendMsg(L"win");
				return checked;
			}
			checked = checkLine(v);
			if (checked != 0) {
				if (!isDuel && this->handler != nullptr) this->handler->sendMsg(L"win");
				return checked;
			}
			checked = checkLine(h);
			if (checked != 0) {
				if (!isDuel && this->handler != nullptr) this->handler->sendMsg(L"win");
				return checked;
			}
			d1.clear(); // очищение 
			d2.clear(); // очищение
			v.clear(); // очищение вертикального рядов
			h.clear(); // очищение горизонтального рядов
			// конец алгоритма
		}
	}
	return isZero ? 0 : 3;
}

void Game::updateField() {
	if (this->fillHandler != nullptr)
		this->fillHandler->Invoke(nullptr, nullptr);
}

bool Game::rotate(int i, bool clockwise, bool isSocket) {
	if (!this->isDuel && ((isSocket && isWhiteMove != isSocketWhite) || (!isSocket && isWhiteMove == isSocketWhite))) return false;
	if (this->isMove) return false;

	for (int x = 0; x < 3 / 2; x++) {
		for (int y = x; y < 3 - x - 1; y++) {
			int temp = field[i][x][y];

			if (clockwise) {
				field[i][x][y] = field[i][3 - 1 - y][x];
				field[i][3 - 1 - y][x] = field[i][3 - 1 - x][3 - 1 - y];
				field[i][3 - 1 - x][3 - 1 - y] = field[i][y][3 - 1 - x];
				field[i][y][3 - 1 - x] = temp;
			}
			else {
				field[i][x][y] = field[i][y][3 - 1 - x];
				field[i][y][3 - 1 - x] = field[i][3 - 1 - x][3 - 1 - y];
				field[i][3 - 1 - x][3 - 1 - y] = field[i][3 - 1 - y][x];
				field[i][3 - 1 - y][x] = temp;
			}
		}
	}


	this->isMove = true;
	isWhiteMove = !isWhiteMove;
	if (!isSocket && !isDuel && this->handler != nullptr) this->handler->sendMsg(L"rotate_" + System::Convert::ToString(i));

	updateField();

	return true;
}

bool Game::move(int i, int x, int y, bool isSocket) 
{
	if (field[i][x][y] != 0 || !this->isMove) return false;
	if (!this->isDuel && ((isSocket && isWhiteMove != isSocketWhite) || (!isSocket && isWhiteMove == isSocketWhite))) return false;
	field[i][x][y] = isWhiteMove ? 1 : 2;
	updateField();
	this->isMove = false;
	if (!isSocket && !isDuel && this->handler != nullptr) this->handler->sendMsg(L"move_" + System::Convert::ToString(i) + "_" + System::Convert::ToString(x) + "_" + System::Convert::ToString(y));
	return true;
}

void Game::addFillHandler(System::EventHandler^ handler) {
	this->fillHandler = handler;
}

cli::array<cli::array<cli::array<int>^>^>^ Game::getField() {
	return this->field;
}

void Game::initServer(System::String^ ip) {
	this->isDuel = false;
	this->isSocketWhite = false;

	auto moveEvent = gcnew System::EventHandler(this, &Game::moveHandler);
	auto rotateEvent = gcnew System::EventHandler(this, &Game::rotateHandler);
	auto winEvent = gcnew System::EventHandler(this, &Game::winHandler);

	this->handler = gcnew ServerHandler(moveEvent, rotateEvent, winEvent);
	this->handler->start(initServerSocket(ip, 1000));
}

void Game::initClient(System::String^ ip) {
	this->isDuel = false;
	this->isSocketWhite = true;

	auto moveEvent = gcnew System::EventHandler(this, &Game::moveHandler);
	auto rotateEvent = gcnew System::EventHandler(this, &Game::rotateHandler);
	auto winEvent = gcnew System::EventHandler(this, &Game::winHandler);

	this->handler = gcnew ServerHandler(moveEvent, rotateEvent, winEvent);
	this->handler->start(initClientSocket(ip, 1000));
}

void Game::initBot() {
	this->isDuel = false;
	this->isSocketWhite = false;

	auto moveEvent = gcnew System::EventHandler(this, &Game::moveHandler);
	auto rotateEvent = gcnew System::EventHandler(this, &Game::rotateHandler);

	gcnew BotHandler(moveEvent, rotateEvent);
}

void Game::moveHandler(System::Object^ o, System::EventArgs^ e)
{
	auto point = (PointEvent^)e;

	move(point->i, point->x, point->y, true);
}

void Game::rotateHandler(System::Object^ o, System::EventArgs^ e)
{
	auto point = (PointEvent^)e;

	rotate(point->i, true, true);
}

void Game::winHandler(System::Object^ o, System::EventArgs^ e)
{
	updateField();
}