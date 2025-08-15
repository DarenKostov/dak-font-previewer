#include "mainClass.hxx"

void MainClass::performActions(){


  while(const std::optional event=window.pollEvent()){
    if (event->is<sf::Event::Closed>()){
      window.close();
    }else{
      if(const auto* resized=event->getIf<sf::Event::Resized>()){
        float windowWidth=resized->size.x;
        float windowHeight=resized->size.y;
        mainView= sf::View(sf::FloatRect({0.f, 0.f}, {windowWidth, windowHeight}));
      }
    }
  }
}
