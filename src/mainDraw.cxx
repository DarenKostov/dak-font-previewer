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
#include <iostream>

void MainClass::draw(){

  //should probably display a warning message about there being 0 fonts....
  if(fonts.size()==0){
    return;
  }

  window.clear();
  window.setView(mainView);
  // window.setView(menuView);

  sf::RectangleShape selectedFamily(sf::Vector2f(170, 25));
  selectedFamily.setFillColor(sf::Color::Red);
  selectedFamily.setOutlineColor(sf::Color(100, 0, 0));
  selectedFamily.setOutlineThickness(2);
  selectedFamily.setPosition({5, static_cast<float>(selectedFontFamily*25+5)});
  window.draw(selectedFamily);

  sf::RectangleShape selectedMember(sf::Vector2f(170, 25));
  selectedMember.setFillColor(sf::Color::Blue);
  selectedMember.setOutlineColor(sf::Color(0, 0, 100));
  selectedMember.setOutlineThickness(2);
  selectedMember.setPosition({5+170, static_cast<float>(selectedFontMember*25+5)});
  window.draw(selectedMember);



  
  float distance=5;
  for(auto& [family, members] : fonts){
    sf::Text identifier(members.front());
    identifier.setString(family);
    identifier.setCharacterSize(20);
    identifier.setPosition({5, distance});
    window.draw(identifier);
    distance+=25;
  }
  
  distance=5;
  for(auto& member : fonts[selectedFontFamily].second){
    
    sf::Text identifier(member);
    identifier.setString(fonts[selectedFontFamily].first);
    identifier.setCharacterSize(20);
    identifier.setPosition({5+170, distance});
    window.draw(identifier);
    distance+=25;
  }




  
  sf::Text sampleText(fonts[selectedFontFamily].second[selectedFontMember]);
  sampleText.setString("the quick brown fox jumps over the lazy dog");

  //make usre the sample text is big enough to be seen but not too big as to go off screen
  for(int i{0}; i<50; i++){
    sampleText.setCharacterSize(i);
    if(sampleText.getLocalBounds().size.x>700){
      sampleText.setCharacterSize(i-1);
      break;
    }
  }

  sampleText.setPosition({170*2+20, 5});
  window.draw(sampleText);

  sampleText.setStyle(sf::Text::Italic);
  sampleText.setPosition({170*2+20, static_cast<float>(10+sampleText.getCharacterSize())});
  window.draw(sampleText);

  sampleText.setStyle(sf::Text::StrikeThrough);
  sampleText.setPosition({170*2+20, 2*static_cast<float>(10+sampleText.getCharacterSize())});
  window.draw(sampleText);

  window.display();
  
}
