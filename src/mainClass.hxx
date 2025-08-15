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
#include <vector>

class MainClass{

  private:
    //variables:


    //sfml stuff
    sf::RenderWindow window;
    sf::View mainView;
    sf::Clock clock;
    std::vector<sf::Font> fonts;
    int selectedFont{0};
    
    
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
