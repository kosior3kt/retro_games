#include "game_objects.h"

int LOCAL::helper::random_number_from_scope(int _scope);

/////game objec satrt

/////game objec end
///
/////square start

Square::Square() {}

/////square end
///
/////snake satrt
Snake::Snake()
{
   this->pos_ = { LOCAL::WIDTH / 2, LOCAL::HEIGHT / 2 };
}

Snake::Snake(Position _pos)
{
   this->pos_ = _pos;
}

/////snake end
///
/////food satrt

Food::Food()
{
   this->pos_ = { LOCAL::helper::random_number_from_scope(LOCAL::WIDTH),
                  LOCAL::helper::random_number_from_scope(LOCAL::HEIGHT) };
}

/////food end
