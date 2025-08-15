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

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Font.hpp>
#include <set>
#include <unordered_map>
#include <vector>

class MainClass{

  private:
    //variables:


    //sfml stuff
    sf::RenderWindow window;
    sf::View mainView;
    sf::View menuView;
    sf::Clock clock;
    int selectedFontFamily{0};
    int selectedFontMember{0};
    // std::unordered_map<std::string, std::vector<sf::Font>> fonts;
    std::vector<std::pair<std::string, std::vector<sf::Font>>> fonts;
    
    
  public:

    //constructor, like a atSTartUp function
    MainClass(std::set<std::filesystem::path> fontPaths);

    //deconstror
    ~MainClass();

    //the function that does all the logic, basically the main function
    void startProgram();

  
    private:
    
    //this performs tasks depending on the actions in the enviroment, like resizing the window 
    void performActions();
  
    //this updates the program, like a "loop" function
    void update();

    //this draws he program, like update but for drawing
    void draw();

};
