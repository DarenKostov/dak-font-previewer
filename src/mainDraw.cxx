#include "mainClass.hxx"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Mouse.hpp>

void MainClass::draw(){

  window.clear();
  window.setView(mainView);
  
  sf::RectangleShape rect(sf::Vector2f(30, 30));
  rect.setFillColor(sf::Color(255, 255, 255, 255));
  rect.setPosition(window.mapPixelToCoords(sf::Mouse::getPosition(window), mainView));
  window.draw(rect);

  window.display();
  
}
