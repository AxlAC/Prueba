#pragma once
#include "Image.h"
#include "Table.h"

class Game
{
private:
    Image background;
    Table tab;
public:
    void Update();
    void Init();
    void Draw();
    void Input();
};

