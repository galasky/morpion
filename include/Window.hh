#ifndef	__WINDOW_HH__
#define	__WINDOW_HH__

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class	Window
{
private:
  Window();
  ~Window();

public:

  static Window	*getInstance()
  {
    if (_instance== NULL)
      {
	_instance= new Window;
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

  sf::RenderWindow	&getRenderWindow();
  sf::Event		&getEvent();

private:
  sf::RenderWindow	_window;
  sf::Event		_event;
  static Window		*_instance;
};

#endif
