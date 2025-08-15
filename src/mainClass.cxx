#include "mainClass.hxx"
#include <charconv>
#include <unistd.h>
#include <stdlib.h>


MainClass::MainClass(){
  window.create(sf::VideoMode({123, 123}), "WXYZ");
  mainView=sf::View(sf::FloatRect({0, 0}, {123, 123}));
  mainView.setViewport(sf::FloatRect({0, 0}, {1, 1}));
  window.setView(mainView);
  window.setVerticalSyncEnabled(true);


  
}
MainClass::~MainClass(){
}



void MainClass::startProgram(){

  clock.restart();

  while(window.isOpen()){

    //drawing 66666-15fps 33333-30fps 16666-60fps 11111-90fps 8333-120fps 4166-240fps 
    usleep(16666);

    performActions();
    update();
    draw();


  }


}


