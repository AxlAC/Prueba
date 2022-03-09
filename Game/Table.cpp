#include "Table.h"
#include "System.h"

#define cellWidth 10
#define cellHeight 10

Table::Table()
{
	selected.Load("assets/Images/selectedCell.png");
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
			if(line[i] =='0' || line[i] == '9')
			{
				Cell temp;
				temp.value = line[i] - '0';
				temp.status = CellState::Active;
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
			sys->RenderTexture(&cell.image, offsetX, offsetY);
			offsetX += cellWidth;
		}
		offsetX = 0;
		offsetY += cellHeight;
	}
}
int Table::GetValueCell(int cellX, int cellY)
{
	//validacion examen
	return table[cellY][cellX].value;
}

int Table::GetStatusCell(int mouseX, int mouseY, int& cellX, int& cellY)
{
	//validacion examen
	cellX = mouseX/10;
	cellY = mouseY/10;
	return table[cellY][cellX].status;
}

void Table::SetStatusCell(int cellX, int cellY, int status)
{
	//validacion examen posiciones y estados 
	table[cellY][cellX].status = status;
	switch (status)
	{
		case CellState::Block:
			table[cellY][cellX].image.Load("assets/Images/selectedCell.png");
		break;
		case 1:
			table[cellY][cellX].image.Load("assets/Images/1.png");
		break;
		case 2:
			table[cellY][cellX].image.Load("assets/Images/2.png");
		break;
		case 3:
			table[cellY][cellX].image.Load("assets/Images/3.png");
			break;
		case 4:
			table[cellY][cellX].image.Load("assets/Images/4.png");
			break;
		case 5:
			table[cellY][cellX].image.Load("assets/Images/5.png");
			break;
		case 6:
			table[cellY][cellX].image.Load("assets/Images/6.png");
			break;
		case 7:
			table[cellY][cellX].image.Load("assets/Images/7.png");
			break;
		case 8:
			table[cellY][cellX].image.Load("assets/Images/8.png");
		break;
		default:
			table[cellY][cellX].image.Load("assets/Images/selectedCell.png");
	}
}

void Table::SetFinalStatus()
{
	if (!isFinal)
	{
		for (auto &row : table)
		{
			for (auto &cell : row)
			{
				cell.status = CellState::Final;

				if (cell.value == CellState::Bomb)
				{
					cell.image.Load("assets/Images/Bomb.png");
				}
			}
		}
		isFinal = true;
	}
}

int Table::CheckCell(int cellX, int cellY)
{
	int contador = 0;
	int arrY = cellY - 1, abaY = cellY + 1;
	int izqX = cellX - 1, derX = cellX + 1;
	if (arrY < 0)
	{
		arrY = cellY;
	}
	else if (abaY > table.size()-1)
	{
		abaY = cellY;
	}
	if (izqX < 0)
	{
		izqX = cellX;
	}
	else if (derX > table[0].size()-1)
	{
		derX = cellX;
	}
1;	for (int y = arrY; y <= abaY; y++)
	{
		for (int x = izqX; x <= derX; x++)
		{
			if (table[y][x].value == CellState::Bomb)
				contador++;
		}
	}
	return contador;
}

