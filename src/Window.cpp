#include "Window.hh"

Window *Window::_instance = NULL;

Window::Window() : _window(sf::VideoMode(300, 300), "morpion")
{

}

Window::~Window()
{

}

sf::RenderWindow &
Window::getRenderWindow()
{
  return _window;
}

sf::Event &
Window::getEvent()
{
  return _event;
}
