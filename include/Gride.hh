#ifndef	__GRIDE_HH__
#define	__GRIDE_HH__

#include <vector>
#include "Sprite.hh"
#include "Window.hh"

class	Gride
{
public:
  Gride(int x, int y);
  ~Gride();

  bool	write(int, int, int);
  int	getValue(int, int) const;
  void	draw();
private:

  bool	end();
  bool	full();
  Sprite				*_sprite;
  Window				*_window;
  std::vector<std::vector<int> >	_gride;
  int					_x;
  int					_y;
};

#endif
