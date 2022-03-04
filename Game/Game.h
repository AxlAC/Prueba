#ifndef GAME_H
#define GAME_H


#include "Image.h"
#include "Table.h"

class Game
{
private:
    Table table;
    int mouseX; 
    int mouseY; 
    int mouseButton;
    int key;
    int currentStateCell;
    int cellX, cellY;
public:
    void Update();
    void Init();
    void Draw();
    void Input();
};


#endif // GAME_H