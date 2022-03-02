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
	active,
	bomb=9,
	flag,
	block
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
public:
	Table();
	void ReadText(const std::string &name);
	vector<vector<Cell>> GetTable();
	void Draw();
};

