#ifndef	__MORPION_HH__
#define	__MORPION_HH__

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "Gride.hh"
#include "Window.hh"

class	Morpion
{
public:
  Morpion(int x_ = 3, int y_ = 3, int xWin = 800, int yWin = 800);
  ~Morpion();

  void	play(int, int);
  void	run();
  void	bot();
private:
  bool	_bot;

  int	_xWin;
  int	_yWin;

  int	_xCurs;
  int	_yCurs;

  int	_turn;
  bool	_buttonRelease;

  Window		*_window;
  Gride			_gride;
  Sprite		*_sprite;

  void	draw();
  void	drawCurs();
  void	refreshCurs(int, int);
  void	event();
  void	end();
};

#endif
