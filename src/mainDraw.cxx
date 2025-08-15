/*
Copyright (c) 2025 Daren Kostov

This file is part of dak-font-previewer

dak-font-previewer is free software: you can redistribute it and/or modify it under the terms
of the GNU General Public License as published by the Free Software Foundation,
either version 3 of the License, or (at your option) any later version.

dak-font-previewer is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with dak-font-previewer
If not, see <https://www.gnu.org/licenses/>.
*/

#include "mainClass.hxx"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Mouse.hpp>

void MainClass::draw(){

  //should probably display a warning message about there being 0 fonts....
  if(fonts.size()==0){
    return;
  }

  window.clear();
  // window.setView(mainView);
  window.setView(menuView);

  sf::RectangleShape selectedFamily(sf::Vector2f(170, 25));
  selectedFamily.setFillColor(sf::Color::Red);
  selectedFamily.setOutlineColor(sf::Color(100, 0, 0));
  selectedFamily.setOutlineThickness(2);
  selectedFamily.setPosition({5, static_cast<float>(selectedFontFamily*25+5)});
  window.draw(selectedFamily);

  float distance=5;
  for(auto& [family, members] : fonts){
    sf::Text identifier(members.front());
    identifier.setString(family);
    identifier.setCharacterSize(20);
    identifier.setPosition({5, distance});
    window.draw(identifier);
    distance+=25;
  }
  
  // float distance=5;
  // for(auto& [family, members] : fonts[selectedFamily].second){
  //   sf::Text identifier(members.front());
  //   identifier.setString(family);
  //   identifier.setCharacterSize(20);
  //   identifier.setPosition({5, distance});
  //   window.draw(identifier);
  //   distance+=25;
  // }




  
  // sf::Text sampleText(fonts[selectedFont]);

  // sampleText.setString("the quick brown fox jumps over the lazy dog");

  // for(int i{0}; i<10; i++){

  //   int size=10+i*2;
  //   // float distance=15.26712*i+5.76027;
  //   float distance=1.17926*i*i+7.09307*i+12.8843;
    
  //   sampleText.setCharacterSize(size);
  //   sampleText.setPosition({10, distance});
  //   window.draw(sampleText);
  // }

  window.display();
  
}
