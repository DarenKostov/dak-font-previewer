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
#include <SFML/Graphics/Font.hpp>
#include <charconv>
#include <iostream>
#include <unistd.h>
#include <stdlib.h>


MainClass::MainClass(std::set<std::filesystem::path> fontPaths){
  window.create(sf::VideoMode({123, 123}), "WXYZ");
  mainView=sf::View(sf::FloatRect({0, 0}, {123, 123}));
  mainView.setViewport(sf::FloatRect({0, 0}, {1, 1}));
  window.setView(mainView);
  window.setVerticalSyncEnabled(true);


  std::unordered_map<std::string, std::vector<sf::Font>> mappedFonts;
  for(const auto& font : fontPaths){

    //load the font and make sure it actually loaded
    sf::Font newFont;
    bool success=newFont.openFromFile(font);
    if(!success){
      std::cerr << font.c_str() << " did not load :/\n";
      continue;
    }


    mappedFonts[newFont.getInfo().family].push_back(newFont);
  }

  for(auto& [family, members] : mappedFonts){
    fonts.push_back({family, members});
  }

  selectedFontFamily=0;
  selectedFontMember=0;

  
}
MainClass::~MainClass(){
}



void MainClass::startProgram(){

  clock.restart();

  while(window.isOpen()){

    // for(const auto& font : fonts){
    //   std::cout << font.getInfo().family << "\n";
    // }
    // std::cout << "========\n";

    //drawing 66666-15fps 33333-30fps 16666-60fps 11111-90fps 8333-120fps 4166-240fps 
    usleep(16666);

    performActions();
    update();
    draw();


  }


}


