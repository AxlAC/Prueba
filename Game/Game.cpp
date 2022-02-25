#include "Game.h"
#include "System.h"

void Game::Update(){

}

void Game:: Input()
{

}

void Game::Draw()
{
	auto sys = System::GetPtr();
	sys->RenderTexture(&background, 0, 0);
}

void Game::Init()
{
	background.Load("Image.png");
	tab.ReadText("table.txt");
}