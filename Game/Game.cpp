#include "Game.h"
#include "System.h"

void Game::Update(){

}

void Game:: Input()
{

}

void Game::Draw()
{
	table.Draw();
}

void Game::Init()
{
	table.ReadText("assets/Config/table.txt");
}
/*
IDE


compilador
linker
editor de texto
debuger
*/

