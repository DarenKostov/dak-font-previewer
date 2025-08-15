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
#include <SFML/Window/Keyboard.hpp>

void MainClass::performActions(){


  while(const std::optional event=window.pollEvent()){
    if (event->is<sf::Event::Closed>()){
      window.close();
    }else
    if(const auto* resized=event->getIf<sf::Event::Resized>()){
      float windowWidth=resized->size.x;
      float windowHeight=resized->size.y;
      mainView= sf::View(sf::FloatRect({0.f, 0.f}, {windowWidth, windowHeight}));
    }else
    if(const auto* keyPressed=event->getIf<sf::Event::KeyPressed>()){
      switch(keyPressed->code){
        case sf::Keyboard::Key::Up:
          selectedFontFamily--;
          if(selectedFontFamily<0){
            selectedFontFamily=fonts.size()-1;
          }
          selectedFontMember=0;
          break;
        case sf::Keyboard::Key::Down:
          selectedFontFamily++;
          selectedFontFamily%=static_cast<int>(fonts.size());

          selectedFontMember=0;
          break;
        case sf::Keyboard::Key::Left:
          selectedFontMember--;
          if(selectedFontMember<0){
            selectedFontMember=fonts[selectedFontFamily].second.size()-1;
          }
          break;
        case sf::Keyboard::Key::Right:
          selectedFontMember++;
          selectedFontMember%=static_cast<int>(fonts[selectedFontFamily].second.size());
          break;
        default:
          //do nothing
          break;


      }
    }
  }
}
