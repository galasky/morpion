#include "Gride.hh"

Gride::Gride(int x_, int y_) : _x(x_), _y(y_)
{
  _gride.resize(_y);
  for (int y = 0; y < _y; y++)
    _gride[y].resize(_x);
  _sprite = Sprite::getInstance();
  _sprite->addSprite("materials/texture/blue.png", "white");
  _sprite->addSprite("materials/texture/blue.png", "black");
  _sprite->addSprite("materials/texture/croix.png", "croix");
  _sprite->addSprite("materials/texture/rond.png", "rond");
  _window = Window::getInstance();
}

Gride::~Gride()
{

}

bool
Gride::end()
{
  bool	ok;

  for (int y = 0; y < _y; y++)
    {
      ok = true;
      for (int x = 1; x < _x; x++)
	{
	  if (_gride[y][x] != _gride[y][x - 1] || _gride[y][x] == 0)
	    ok = false;
	}
      if (ok == true)
	return true;
    }
  for (int x = 0; x < _x; x++)
    {
      ok = true;
      for (int y = 1; y < _y; y++)
	{
	  if (_gride[y][x] != _gride[y - 1][x] || _gride[y][x] == 0)
	    ok = false;
	}
      if (ok == true)
	return true;
    }
  int x = 1;
  int y = 1;

  ok = true;
  while (x < _x && y < _y)
    {
      if (_gride[y][x] != _gride[y - 1][x - 1] || _gride[y][x] == 0)
	ok = false;
      x++;
      y++;
    }
  if (ok == true)
    return true;
  ok = true;
  x = 1;
  y = 1;
  while (x < _x && y >= 0)
    {
      if (_gride[y][x] != _gride[y + 1][x - 1] || _gride[y][x] == 0)
	ok = false;
      x++;
      y--;
    }
  if (ok == true)
    return true;
  return false;
}

bool
Gride::full()
{
  for (int y = 0; y < _y; y++)
    {
      for (int x = 0; x < _x; x++)
	{
	  if (_gride[y][x] == 0)
	    return false;
	}
    }
  return true;
}

bool
Gride::write(int x, int y, int n)
{
  _gride[y][x] = n;
  if (this->full() && this->end() == false)
    {
      for (int y = 0; y < _y; y++)
	for (int x = 0; x < _x; x++)
	  _gride[y][x] = 0;
    }
  return this->end();
}

int
Gride::getValue(int x, int y) const
{
  return (_gride[y][x]);
}

void
Gride::draw()
{
  for (int y = 0; y < _y; y++)
    {
      for (int x = 0; x < _x; x++)
	{
	  _sprite->getSprite("white").SetPosition(x * 100, y * 100);
	  _sprite->getSprite("black").SetPosition(x * 100, y * 100);
	  _sprite->getSprite("croix").SetPosition(x * 100, y * 100);
	  _sprite->getSprite("rond").SetPosition(x * 100, y * 100);

	  if ((x + y) % 2 == 0)
	    {
	      _window->getRenderWindow().Draw(_sprite->getSprite("white"));
	    }
	  else
	    _window->getRenderWindow().Draw(_sprite->getSprite("black"));
	  if (_gride[y][x] == 1)
	    _window->getRenderWindow().Draw(_sprite->getSprite("croix"));
	  if (_gride[y][x] == 2)
	    _window->getRenderWindow().Draw(_sprite->getSprite("rond"));
	}
    }
}
