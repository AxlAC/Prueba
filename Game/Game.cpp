#include "Game.h"
#include "System.h"
#include "Table.h"

void Game::Update()
{
	if (currentStateCell == CellState::Active)
	{
		int bombsNumber = table.CheckCell(cellX, cellY);
		if (table.GetValueCell(cellX, cellY) == CellState::Bomb)
		{
			//game over
			table.SetFinalStatus();
		}
		else if (bombsNumber > 0 && bombsNumber < 9)
		{
			table.SetStatusCell(cellX, cellY, bombsNumber);
		}
		else
		{
			table.SetStatusCell(cellX, cellY, CellState::Block);
		}


		// puede ser que sea una bomba o libre 
		// si es libre ---> ponemos el numero, lo bloqueamos y buscamos vecinos
		// en caso contrario (si es bomba) --> se acaba, muestra las demas bombas y bloqueamos todo
	}
}

void Game:: Input()
{
	auto sys = System::GetPtr();
	sys->Input(mouseX, mouseY, mouseButton, key);
	if(mouseButton==1)
	{
		currentStateCell = table.GetStatusCell(mouseX,mouseY, cellX, cellY);
	}

}

void Game::Draw()
{
	table.Draw();
}

void Game::Init()
{
	table.Init("assets/Config/table.txt");
	currentStateCell = -1;
}
/*
IDE


compilador
linker
editor de texto
debuger
*/

