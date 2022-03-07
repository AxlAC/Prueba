#pragma once
#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include <iterator>
#include "Image.h"

using namespace std;
/*
0- libre * Iniciales
1-8 bombas vecinas
9- bomba *
10 - banderita
11 - bloqueado
*/

enum CellState
{
	Active,
	Bomb=9,
	Flag,
	Block,
	Final
};

struct Cell
{
	int value;
	int status;
	Image image;
};

class Table
{
private:
	vector <vector<Cell>> table;
	Image selected;
	bool isFinal = false;
public:
	Table();
	void ReadText(const std::string &name);
	vector<vector<Cell>> GetTable();
	int GetStatusCell(int mouseX, int mouseY, int &cellX, int &cellY);
	void SetStatusCell(int cellX, int cellY, int status);
	int GetValueCell(int cellX, int cellY);
	void Draw();
	void SetFinalStatus();
};

