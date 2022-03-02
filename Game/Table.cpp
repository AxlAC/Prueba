#include "Table.h"
#include "System.h"

#define cellWidth 10
#define cellHeight 10

Table::Table()
{
}

vector <vector<Cell>> Table::GetTable()
{
	return table;
}

void Table::ReadText(const std::string &name)
{
	ifstream file(name);
	string line;
	while (getline(file, line))
	{
		vector<Cell> row;
		for (int i=0; i < line.size(); ++i) 
		{
			if(line[i]=='0' || line[i] == '9')
			{
				Cell temp;
				temp.value = line[i] - '0';
				temp.status = CellState::active;
				temp.image.Load("assets/Images/freeCell.png");
				row.push_back(temp);
			}
		}
		table.push_back(row);
	}
	file.close();
}

void Table::Draw()
{
	int offsetX = 0;
	int offsetY = 0;
	auto sys = System::GetPtr();
	
	for (auto row : table)
	{
		for (auto cell : row)
		{
			if (cell.status == CellState::active)
			{
				sys->RenderTexture(&cell.image, offsetX, offsetY);
			}
			offsetX += cellWidth;
		}
		offsetX = 0;
		offsetY += cellHeight;
	}
}
