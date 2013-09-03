#include <unistd.h>
#include <iostream>
#include "Morpion.hh"

Morpion::Morpion(int x_, int y_, int xWin, int yWin) : _xWin(xWin), _yWin(yWin), _gride(x_, y_)
{
  _bot = true;
  _window = Window::getInstance();
  _window->getRenderWindow().ShowMouseCursor(false);
  _turn = 0;
  _buttonRelease = true;
  _sprite = Sprite::getInstance();
  _sprite->addSprite("materials/texture/croix.png", "Ccroix");
  _sprite->addSprite("materials/texture/rond.png", "Crond");
  _sprite->getSprite("Crond").SetCenter(50, 50);
  _sprite->getSprite("Ccroix").SetCenter(50, 50);
  _sprite->getSprite("Crond").SetScale(.5, .5);
  _sprite->getSprite("Ccroix").SetScale(.5, .5);
}

Morpion::~Morpion()
{
  
}

void
Morpion::draw()
{
  _window->getRenderWindow().Clear();
  _gride.draw();
  this->drawCurs();
  _window->getRenderWindow().Display();
}

void
Morpion::drawCurs()
{
  if (_turn % 2 == 0)
    {
      _sprite->getSprite("Ccroix").SetPosition(_xCurs, _yCurs);
      _window->getRenderWindow().Draw(_sprite->getSprite("Ccroix"));
    }
  else
    {
      _sprite->getSprite("Crond").SetPosition(_xCurs, _yCurs);
      _window->getRenderWindow().Draw(_sprite->getSprite("Crond"));    
    }
}

void
Morpion::refreshCurs(int x, int y)
{
  _xCurs = x;
  _yCurs = y;
}

void
Morpion::event()
{
  while (_window->getRenderWindow().GetEvent(_window->getEvent()))
    {
      if (_window->getEvent().Type == sf::Event::Closed)
	_window->getRenderWindow().Close();
      if (_window->getEvent().Type == sf::Event::MouseMoved)
	{
	  this->refreshCurs(_window->getEvent().MouseMove.X, _window->getEvent().MouseMove.Y);
	}
      if (_buttonRelease == true && _window->getEvent().Type == sf::Event::MouseButtonPressed)
	{
	  _buttonRelease = false;
	  this->play(_window->getEvent().MouseButton.X / 100, _window->getEvent().MouseButton.Y / 100);
	}
      if (_window->getEvent().Type == sf::Event::MouseButtonReleased)
	{
	  _buttonRelease = true;
	}
    }
}

void
Morpion::play(int x, int y)
{
  if (_gride.getValue(x, y) == 0)
    {
      if (_gride.write(x, y, _turn % 2 + 1) == 1)
	this->end();
      _turn++;
    }
}

void
Morpion::end()
{
  for (int y = 0; y < 3; y++)
    {
      for (int x = 0; x < 3; x++)
	{
	  usleep(100000);
	  _gride.write(x, y, 0);
	  _window->getRenderWindow().Clear();
	  _gride.draw();
	  _window->getRenderWindow().Display();
	}
    }
  for (int y = 0; y < 3; y++)
    {
      for (int x = 0; x < 3; x++)
	{
	  usleep(100000);
	  _gride.write(x, y, _turn % 2 + 1);
	  _window->getRenderWindow().Clear();
	  _gride.draw();
	  _window->getRenderWindow().Display();
	}
    }
  usleep(1000000);  
  for (int y = 0; y < 3; y++)
    for (int x = 0; x < 3; x++)
      _gride.write(x, y, 0);
}

void
Morpion::run()
{
  while (_window->getRenderWindow().IsOpened())
    {
      this->draw();
      if (_bot == true && _turn % 2 == 1)
	this->bot();
      else
	this->event();
    }
}

void
Morpion::bot()
{
  _turn++;
}
