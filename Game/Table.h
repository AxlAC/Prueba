#pragma once
#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include <iterator>

using namespace std;

class Table
{
private:
	vector <vector<int>> table;
public:
	Table();
	void ReadText(const std::string &name);
	vector<vector<int>> GetTable();
};

