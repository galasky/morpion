#include "Sprite.hh"

Sprite *Sprite::_instance = NULL;

Sprite::Sprite()
{
  _n = 0;
}

Sprite::~Sprite()
{

}

void
Sprite::addSprite(const std::string &path, const std::string &name)
{
  _texture.push_back(new sf::Image);
  _texture[_n]->LoadFromFile(path);
  _sprite[name].SetImage(*_texture[_n]);
  _n++;
}

sf::Sprite &
Sprite::getSprite(const std::string &name)
{
  return _sprite[name];
}

sf::Sprite &
Sprite::operator[](std::string &name)
{
  return _sprite[name];
}
