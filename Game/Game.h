#ifndef GAME_H
#define GAME_H


#include "Image.h"
#include "Table.h"

class Game
{
private:
    Table table;
public:
    void Update();
    void Init();
    void Draw();
    void Input();
};


#endif // GAME_H