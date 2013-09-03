#ifndef	__SPRITE_HH__
#define	__SPRITE_HH__

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <map>

class	Sprite
{
private:
  Sprite();
  ~Sprite();

public:

  static Sprite	*getInstance()
  {
    if (_instance== NULL)
      {
	_instance= new Sprite;
      }
    return _instance;
  }
  static void	kill()
  {
    if (_instance!= NULL)
      {
	delete _instance;
	_instance = NULL;
      }
  }

  void		addSprite(const std::string &path, const std::string &name);
  sf::Sprite	&getSprite(const std::string &name);
  sf::Sprite	&operator[](std::string &name);

private:
  std::vector<sf::Image *>		_texture;
  std::map<std::string , sf::Sprite>	_sprite;
  int					_n;
  static Sprite				*_instance;
};

#endif
