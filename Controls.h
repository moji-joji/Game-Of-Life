#pragma once
#include <SFML/Graphics.hpp>

class Key {
	// enumeration of key made
	sf::Keyboard::Key key;

	// to check state of key
	bool pressed;

	
public:
	// default  constructor
	Key();

	// overloaded constructor
	Key(sf::Keyboard::Key);

	bool key_pressed();
};



class Mouse {
    // enum mouse click
    sf::Mouse::Button button;

    // to check if pressed
    bool pressed;
public:
    Mouse();
    
    Mouse(sf::Mouse::Button);

	bool sense_click();
};
